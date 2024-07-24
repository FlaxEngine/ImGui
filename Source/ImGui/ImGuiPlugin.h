// Copyright (c) Wojciech Figat. All rights reserved.

#pragma once

#include "Engine/Scripting/Plugins/GamePlugin.h"
#include "Engine/Core/Math/Vector2.h"
#include "Engine/Core/Math/Color.h"

/// <summary>
/// Dear ImGui plugin that adds debug GUI interface to game viewport.
/// </summary>
API_CLASS(Namespace="") class IMGUI_API ImGuiPlugin : public GamePlugin
{
    DECLARE_SCRIPTING_TYPE(ImGuiPlugin);

private:
    class GPUTexture* _fontAtlasTexture = nullptr;
    Array<Float2> _vertices;
    Array<Float2> _uvs;
    Array<Color> _colors;
    bool _activeFrame = false;

public:
    /// <summary>
    /// Gets the singleton instance of the ImGui plugin.
    /// </summary>
    API_PROPERTY() static ImGuiPlugin* GetInstance();

    /// <summary>
    /// Toggles debug interface logic. Allows to disable and hide ImGui.
    /// </summary>
    API_FIELD() bool Enable = true;

    /// <summary>
    /// Toggles inputs reading. Can be used to block user interaction with debug interface.
    /// </summary>
    API_FIELD() bool EnableInput = true;

    /// <summary>
    /// Toggles interface rendering in the game viewport. Can be used to hide debug UI while still processing it.
    /// </summary>
    API_FIELD() bool EnableDrawing = true;

private:
    // [GamePlugin]
    void Initialize() override;
    void Deinitialize() override;

    bool IsReady();
    void OnUpdate();
    void OnLateUpdate();
    void OnPostRender(class GPUContext* context, struct RenderContext& renderContext);
};
