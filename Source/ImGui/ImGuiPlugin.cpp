// Copyright (c) Wojciech Figat. All rights reserved.

#include "ImGuiPlugin.h"
#include "Engine/Core/Log.h"
#include "Engine/Core/Types/DataContainer.h"
#include "Engine/Engine/Engine.h"
#include "Engine/Engine/Screen.h"
#include "Engine/Engine/Time.h"
#include "Engine/Graphics/GPUDevice.h"
#include "Engine/Graphics/RenderTask.h"
#include "Engine/Graphics/Async/GPUTask.h"
#include "Engine/Graphics/Textures/GPUTexture.h"
#include "Engine/Input/Input.h"
#include "Engine/Profiler/Profiler.h"
#include "Engine/Render2D/Render2D.h"
#include "Engine/Scripting/Plugins/PluginManager.h"
#include "ImGui/imgui.h"

struct ImGuiKeyMapping
{
    ImGuiKey_ ImGui;
    KeyboardKeys Flax;
};

ImGuiKeyMapping KeyMappings[] =
{
    { ImGuiKey_Tab, KeyboardKeys::Tab },
    { ImGuiKey_LeftArrow, KeyboardKeys::ArrowLeft },
    { ImGuiKey_RightArrow, KeyboardKeys::ArrowLeft },
    { ImGuiKey_UpArrow, KeyboardKeys::ArrowUp },
    { ImGuiKey_DownArrow, KeyboardKeys::ArrowDown },
    { ImGuiKey_PageUp, KeyboardKeys::PageUp },
    { ImGuiKey_PageDown, KeyboardKeys::PageDown },
    { ImGuiKey_Home, KeyboardKeys::Home },
    { ImGuiKey_End, KeyboardKeys::End },
    { ImGuiKey_Insert, KeyboardKeys::Insert },
    { ImGuiKey_Delete, KeyboardKeys::Delete },
    { ImGuiKey_Backspace, KeyboardKeys::Backspace },
    { ImGuiKey_Space, KeyboardKeys::Spacebar },
    { ImGuiKey_Enter, KeyboardKeys::Return },
    { ImGuiKey_Escape, KeyboardKeys::Escape },
    { ImGuiKey_Comma, KeyboardKeys::Comma },
    { ImGuiKey_Minus, KeyboardKeys::Minus },
    { ImGuiKey_Period, KeyboardKeys::Period },
    { ImGuiKey_Slash, KeyboardKeys::Slash },
    { ImGuiKey_Semicolon, KeyboardKeys::Colon },
    { ImGuiKey_LeftBracket, KeyboardKeys::LeftBracket },
    { ImGuiKey_RightBracket, KeyboardKeys::RightBracket },
};

ImGuiPlugin::ImGuiPlugin(const SpawnParams& params)
    : GamePlugin(params)
{
    _description.Category = TEXT("Debug");
#if USE_EDITOR
    _description.Description = TEXT("Dear ImGui plugin that adds debug GUI interface to game viewport.");
    _description.Author = TEXT("Omar Cornut");
    _description.Version = Version(1, 88);
    _description.HomepageUrl = TEXT("https://github.com/ocornut/imgui");
    _description.RepositoryUrl = TEXT("https://github.com/FlaxEngine/ImGui");
#endif
}

ImGuiPlugin* ImGuiPlugin::GetInstance()
{
    return PluginManager::GetPlugin<ImGuiPlugin>();
}

ImVec4 ColorFromBytes(uint8_t r, uint8_t g, uint8_t b)
{
    return ImVec4((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, 1.0f);
};

void ImGuiPlugin::Initialize()
{
    GamePlugin::Initialize();

    // Initialize
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    Engine::Update.Bind<ImGuiPlugin, &ImGuiPlugin::OnUpdate>(this);
    Engine::LateUpdate.Bind<ImGuiPlugin, &ImGuiPlugin::OnLateUpdate>(this);
    MainRenderTask::Instance->PostRender.Bind<ImGuiPlugin, &ImGuiPlugin::OnPostRender>(this);

    // Setup font atlas texture
    int width, height;
    unsigned char* pixels = nullptr;
    io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
    _fontAtlasTexture = GPUDevice::Instance->CreateTexture(TEXT("ImGui.FontAtlas"));
    if (_fontAtlasTexture->Init(GPUTextureDescription::New2D(width, height, 1, PixelFormat::R8G8B8A8_UNorm, GPUTextureFlags::ShaderResource)))
    {
        LOG(Error, "Failed to setup ImGui font atlas texture.");
        return;
    }
    BytesContainer data;
    data.Link(pixels, width * height * sizeof(uint32));
    auto task = _fontAtlasTexture->UploadMipMapAsync(data, 0, true);
    if (task)
        task->Start();
    io.Fonts->SetTexID(_fontAtlasTexture);
}

void ImGuiPlugin::Deinitialize()
{
    // Shutdown
    Engine::Update.Unbind<ImGuiPlugin, &ImGuiPlugin::OnUpdate>(this);
    Engine::LateUpdate.Unbind<ImGuiPlugin, &ImGuiPlugin::OnLateUpdate>(this);
    MainRenderTask::Instance->PostRender.Unbind<ImGuiPlugin, &ImGuiPlugin::OnPostRender>(this);
    ImGui::DestroyContext();
    SAFE_DELETE_GPU_RESOURCE(_fontAtlasTexture);

    GamePlugin::Deinitialize();
}

bool ImGuiPlugin::IsReady()
{
    return _fontAtlasTexture && _fontAtlasTexture->HasResidentMip();
}

void ImGuiPlugin::OnUpdate()
{
    PROFILE_CPU();

    // Begin frame
    ImGuiIO& io = ImGui::GetIO();
    io.DeltaTime = Time::Update.UnscaledDeltaTime.GetTotalSeconds();
    const Float2 screenSize = Screen::GetSize();
    io.DisplaySize.x = screenSize.X;
    io.DisplaySize.y = screenSize.Y;
    const bool hasFocus = Engine::HasGameViewportFocus();
    io.AddFocusEvent(hasFocus);
    if (hasFocus)
    {
        // Send input events
        const Float2 mousePos = Input::GetMousePosition();
        io.AddMousePosEvent(mousePos.X, mousePos.Y);
        io.AddMouseButtonEvent(0, Input::GetMouseButton(MouseButton::Left));
        io.AddMouseButtonEvent(1, Input::GetMouseButton(MouseButton::Right));
        io.AddMouseWheelEvent(0, Input::GetMouseScrollDelta());
        const StringView inputText = Input::GetInputText();
        if (inputText.Length() != 0)
            io.AddInputCharacterUTF16(inputText[0]);
        for (const auto& e : KeyMappings)
        {
            if (Input::GetKeyDown(e.Flax))
                io.AddKeyEvent(e.ImGui, true);
            else if (Input::GetKeyUp(e.Flax))
                io.AddKeyEvent(e.ImGui, false);
        }
    }
    ImGui::NewFrame();

    //ImGui::ShowDemoWindow();
}

void ImGuiPlugin::OnLateUpdate()
{
    PROFILE_CPU();

    // End frame
    ImGui::EndFrame();

    if (!IsReady())
        return;
    ImGui::Render();
}

void ImGuiPlugin::OnPostRender(GPUContext* context, RenderContext& renderContext)
{
    if (!IsReady())
        return;
    PROFILE_GPU_CPU("ImGui");

    // Draw ImGui data into the output (via Render2D)
    const ImDrawData* drawData = ImGui::GetDrawData();
    if (!drawData)
        return;
    const Viewport viewport = renderContext.Task->GetOutputViewport();
    Render2D::Begin(context, renderContext.Task->GetOutputView(), nullptr, viewport);
    const ImVec2 displayPos = drawData->DisplayPos;
    for (int cmdListIndex = 0; cmdListIndex < drawData->CmdListsCount; cmdListIndex++)
    {
        const ImDrawList* cmdList = drawData->CmdLists[cmdListIndex];

        // Convert vertex buffer
        _vertices.Resize(cmdList->VtxBuffer.Size);
        _uvs.Resize(cmdList->VtxBuffer.Size);
        _colors.Resize(cmdList->VtxBuffer.Size);
        for (int32 i = 0; i < cmdList->VtxBuffer.Size; i++)
        {
            const ImDrawVert v = cmdList->VtxBuffer.Data[i];
            _vertices.Get()[i] = Float2(v.pos.x, v.pos.y);
            _uvs.Get()[i] = Float2(v.uv.x, v.uv.y);
            _colors.Get()[i] = Color((float)((v.col >> IM_COL32_R_SHIFT) & 0xFF) / 255.0f, (float)((v.col >> IM_COL32_G_SHIFT) & 0xFF) / 255.0f, (float)((v.col >> IM_COL32_B_SHIFT) & 0xFF) / 255.0f, (float)((v.col >> IM_COL32_A_SHIFT) & 0xFF) / 255.0f);
        }
        Span<Float2> vertices(_vertices.Get(), _vertices.Count());
        Span<Float2> uvs(_uvs.Get(), _uvs.Count());
        Span<Color> colors(_colors.Get(), _colors.Count());
        const uint16* indices = cmdList->IdxBuffer.Data;

        // Submit draw commands
        for (int cmdIndex = 0; cmdIndex < cmdList->CmdBuffer.Size; cmdIndex++)
        {
            const ImDrawCmd& cmd = cmdList->CmdBuffer[cmdIndex];
            if (cmd.UserCallback)
            {
                cmd.UserCallback(cmdList, &cmd);
            }
            else
            {
                // Perform scissors clipping
                const ImVec2 clipMin(cmd.ClipRect.x - displayPos.x, cmd.ClipRect.y - displayPos.y);
                const ImVec2 clipMax(cmd.ClipRect.z - displayPos.x, cmd.ClipRect.w - displayPos.y);
                if (clipMax.x <= clipMin.x || clipMax.y <= clipMin.y)
                    continue;
                Rectangle scissor(clipMin.x, clipMin.y, clipMax.x - clipMin.x, clipMax.y - clipMin.y);
                Render2D::PushClip(scissor);

                // Draw textured indexed triangles list
                auto tex = (GPUTexture*)cmd.GetTexID();
                Render2D::DrawTexturedTriangles(tex, Span<uint16>(indices + cmd.IdxOffset, cmd.ElemCount), vertices, uvs, colors);

                Render2D::PopClip();
            }
        }
    }

    Render2D::End();
}
