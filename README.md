# Dear ImGui for Flax Engine

![Dear ImGui for Flax Engine](imgui-flax-engine.png)

[Dear ImGui](https://github.com/ocornut/imgui) is a bloat-free graphical user interface library for C++. It outputs optimized vertex buffers that you can render anytime in your 3D-pipeline-enabled application. It is fast, portable, renderer agnostic, and self-contained (no external dependencies). This repository contains a plugin project for [Flax Engine](https://flaxengine.com/) games with ImGui.

Minimum supported Flax version: `1.5`.

## Installation

0. Ensure to have proper system setup for C++ Scripting - see [Flax Docs](https://docs.flaxengine.com/manual/scripting/cpp/index.html)

1. Clone repo into `<game-project>\Plugins\ImGui`

2. Add reference to ImGui project in your game by modyfying your game `<game-project>.flaxproj` as follows:

```
...
"References": [
    {
        "Name": "$(EnginePath)/Flax.flaxproj"
    },
    {
        "Name": "$(ProjectPath)/Plugins/ImGui/ImGui.flaxproj"
    }
]
```

3. Add reference to *ImGui* module in your game build script (eg. `Game.Build.cs`) as follows:

```cs
/// <inheritdoc />
public override void Setup(BuildOptions options)
{
    base.Setup(options);

    BuildNativeCode = false;
    options.ScriptingAPI.IgnoreMissingDocumentationWarnings = true;

    // Add reference to ImGui
    options.PrivateDependencies.Add("ImGui");
}
```

4. Test it out!

Now you can use ImGui API directly in your game code within `Update` (scripts, plugins, anywhere within game logic update) as follows:

```cpp
// C++
#include "ImGui/imgui.h"

void MyScript::OnUpdate()
{
    ImGui::Text("Hello, world %d", 123);
    ImGui::Button("Click");
}
```

```cs
// C#
public override void OnUpdate()
{
    ImGui.Text("Hello!");
    ImGui.Button("Click");
}
```

## License

Both this plugin and ImGui are released under **MIT License**.
