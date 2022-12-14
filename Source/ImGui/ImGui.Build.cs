using Flax.Build;
using Flax.Build.NativeCpp;

public class ImGui : ThirdPartyModule
{
    public ImGui()
    {
        BuildCSharp = true;
        BuildNativeCode = true;
        LicenseType = LicenseTypes.MIT;
        LicenseFilePath = "LICENSE.txt";
    }

    /// <inheritdoc />
    public override void Setup(BuildOptions options)
    {
        base.Setup(options);

        options.PrivateIncludePaths.Add(FolderPath);
        options.PublicDependencies.Add("Core");
        options.PublicDependencies.Add("Engine");
    }
}
