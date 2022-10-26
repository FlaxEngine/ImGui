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

public:
    /// <summary>
    /// Gets the singleton instance of the ImGui plugin.
    /// </summary>
    API_PROPERTY() static ImGuiPlugin* GetInstance();

private:
    // [GamePlugin]
    void Initialize() override;
    void Deinitialize() override;

    bool IsReady();
    void OnUpdate();
    void OnLateUpdate();
    void OnPostRender(class GPUContext* context, struct RenderContext& renderContext);
};
