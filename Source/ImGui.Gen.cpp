// This code was auto-generated. Do not modify it.

#include "Engine/Scripting/BinaryModule.h"
#include "ImGui.Gen.h"

StaticallyLinkedBinaryModuleInitializer StaticallyLinkedBinaryModuleImGui(GetBinaryModuleImGui);

extern "C" BinaryModule* GetBinaryModuleImGui()
{
    static NativeBinaryModule module("ImGui", MAssemblyOptions());
    return &module;
}
