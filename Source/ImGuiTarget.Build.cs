using Flax.Build;

public class ImGuiTarget : GameProjectTarget
{
    /// <inheritdoc />
    public override void Init()
    {
        base.Init();

        Modules.Add("ImGui");
    }
}
