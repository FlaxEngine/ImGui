// Copyright (c) Wojciech Figat. All rights reserved.

#pragma once

#include "Engine/Core/Math/Vector2.h"
#include "Engine/Core/Math/Vector3.h"
#include "Engine/Core/Math/Vector4.h"
#include "Engine/Core/Math/Color.h"
#include "Engine/Core/Types/Span.h"
#include "Engine/Core/Collections/Array.h"
#include "Engine/Core/Types/String.h"
#include "Engine/Scripting/ScriptingType.h"
#include "ImGui/imgui.h"

class GPUTexture;

/// <summary>
/// Dear ImGui interface that adds debug GUI interface to game viewport.
/// </summary>
API_CLASS(Namespace="", Name="ImGui", Static) class IMGUI_API ImGuiAPI
{
    DECLARE_SCRIPTING_TYPE_NO_SPAWN(ImGuiAPI);

public:
    // Separator, generally horizontal. inside a menu bar or in horizontal layout mode, this becomes a vertical separator.
    API_FUNCTION() static void Separator()
    {
        ImGui::Separator();
    }

    // Call between widgets or groups to layout them horizontally. X position given in window coordinates.
    API_FUNCTION() static void SameLine(float offsetFromStartX = 0.0f, float spacing = -1.0f)
    {
        ImGui::SameLine(offsetFromStartX, spacing);
    }

    // Undo a SameLine() or force a new line when in an horizontal-layout context.
    API_FUNCTION() static void NewLine()
    {
        ImGui::NewLine();
    }

    // Add vertical spacing.
    API_FUNCTION() static void Spacing()
    {
        ImGui::Spacing();
    }

    // Add a dummy item of given size. unlike InvisibleButton(), Dummy() won't take the mouse click or be navigable into.
    API_FUNCTION() static void Dummy(const Float2& size)
    {
        ImGui::Dummy(*(ImVec2*)&size);
    }

    // Move content position toward the right, by indent_w, or style.IndentSpacing if indent_w less or equal to 0.
    API_FUNCTION() static void Indent(float indentW = 0.0f)
    {
        ImGui::Indent(indentW);
    }

    // Move content position back to the left, by indent_w, or style.IndentSpacing if indent_w less or equal to 0.
    API_FUNCTION() static void Unindent(float indentW = 0.0f)
    {
        ImGui::Unindent(indentW);
    }

    // Lock horizontal starting position.
    API_FUNCTION() static void BeginGroup()
    {
        ImGui::BeginGroup();
    }

    // Unlock horizontal starting position + capture the whole group bounding box into one "item" (so you can use IsItemHovered() or layout primitives such as SameLine() on whole group, etc.).
    API_FUNCTION() static void EndGroup()
    {
        ImGui::EndGroup();
    }

public:
    // Push string into the ID stack (will hash string).
    API_FUNCTION() static void PushID(const StringAnsiView& strID)
    {
        ImGui::PushID(strID.Get());
    }

    // Push integer into the ID stack (will hash integer).
    API_FUNCTION() static void PushID(int32 intID)
    {
        ImGui::PushID(intID);
    }

    // Pops ID from stack.
    API_FUNCTION() static void PopID()
    {
        ImGui::PopID();
    }

public:
    // Text.
    API_FUNCTION() static void Text(const StringAnsiView& text)
    {
        ImGui::Text(text.GetText());
    }

    // Shortcut for PushStyleColor(ImGuiCol_Text, col); Text(text); PopStyleColor();
    API_FUNCTION() static void TextColored(const Color& col, const StringAnsiView& text)
    {
        ImGui::TextColored(*(ImVec4*)&col, text.GetText());
    }

    // Shortcut for PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]); Text(text); PopStyleColor();
    API_FUNCTION() static void TextDisabled(const StringAnsiView& text)
    {
        ImGui::TextDisabled(text.GetText());
    }

    // Shortcut for PushTextWrapPos(0.0f); Text(text); PopTextWrapPos();. Note that this won't work on an auto-resizing window if there's no other widgets to extend the window width, yoy may need to set a size using SetNextWindowSize().
    API_FUNCTION() static void TextWrapped(const StringAnsiView& text)
    {
        ImGui::TextWrapped(text.GetText());
    }

    // Display text+label aligned the same way as value+label widgets.
    API_FUNCTION() static void LabelText(const StringAnsiView& label, const StringAnsiView& text)
    {
        ImGui::LabelText(label.GetText(), text.GetText());
    }

    // Shortcut for Bullet()+Text().
    API_FUNCTION() static void BulletText(const StringAnsiView& text)
    {
        ImGui::BulletText(text.GetText());
    }

public:
    // Button.
    API_FUNCTION() static bool Button(const StringAnsiView& label, const Float2& size = Float2::Zero)
    {
        return ImGui::Button(label.GetText(), *(ImVec2*)&size);
    }

    // Button with FramePadding=(0,0) to easily embed within text.
    API_FUNCTION() static bool SmallButton(const StringAnsiView& label)
    {
        return ImGui::SmallButton(label.GetText());
    }

    // Square button with an arrow shape.
    API_FUNCTION() static bool ArrowButton(const StringAnsiView& str, ImGuiDir dir)
    {
        return ImGui::ArrowButton(str.GetText(), dir);
    }

    // Image.
    API_FUNCTION() static void Image(GPUTexture* texture, const Float2& size, const Float2& uv0 = Float2::Zero, const Float2& uv1 = Float2::One, const Color& tintColor = Color::White, const Color& borderColor = Color::Transparent)
    {
        ImGui::Image((ImTextureID)texture, *(ImVec2*)&size, *(ImVec2*)&uv0, *(ImVec2*)&uv1, *(ImVec4*)&tintColor, *(ImVec4*)&borderColor);
    }

    // less than 0 framePadding uses default frame padding settings. 0 for no padding.
    API_FUNCTION() static bool ImageButton(GPUTexture* texture, const Float2& size, const Float2& uv0 = Float2::Zero, const Float2& uv1 = Float2::One, const Color& backgroundColor = Color::Transparent, const Color& tintColor = Color::White, int32 framePadding = -1)
    {
        return ImGui::ImageButton((ImTextureID)texture, *(ImVec2*)&size, *(ImVec2*)&uv0, *(ImVec2*)&uv1, framePadding, *(ImVec4*)&backgroundColor, *(ImVec4*)&tintColor);
    }

    // Checkbox.
    API_FUNCTION() static bool Checkbox(const StringAnsiView& label, API_PARAM(Ref) bool& v)
    {
        return ImGui::Checkbox(label.GetText(), &v);
    }

    // Checkbox for flags value.
    API_FUNCTION() static bool CheckboxFlags(const StringAnsiView& label, API_PARAM(Ref) int32& flags, int32 flagsValue)
    {
        return ImGui::CheckboxFlags(label.GetText(), &flags, flagsValue);
    }

    // Checkbox for flags value.
    API_FUNCTION() static bool CheckboxFlags(const StringAnsiView& label, API_PARAM(Ref) uint32& flags, uint32 flagsValue)
    {
        return ImGui::CheckboxFlags(label.GetText(), &flags, flagsValue);
    }

    // Use with e.g. if (RadioButton("one", my_value==1)) { my_value = 1; }
    API_FUNCTION() static bool RadioButton(const StringAnsiView& label, bool active)
    {
        return ImGui::RadioButton(label.GetText(), active);
    }

    // shortcut to handle the above pattern when value is an integer
    API_FUNCTION() static bool RadioButton(const StringAnsiView& label, API_PARAM(Ref) int32& v, int vButton)
    {
        return ImGui::RadioButton(label.GetText(), &v, vButton);
    }

    // ProgressBar.
    API_FUNCTION() static void ProgressBar(float fraction, const Float2& size, const StringAnsiView& overlay = StringAnsiView::Empty)
    {
        ImGui::ProgressBar(fraction, *(ImVec2*)&size, overlay.GetText());
    }

    // draw a small circle + keep the cursor on the same line. advance cursor x position by GetTreeNodeToLabelSpacing(), same distance that TreeNode() uses
    API_FUNCTION() static void Bullet()
    {
        ImGui::Bullet();
    }

public:
    // Combo.
    API_FUNCTION() static bool Combo(const StringAnsiView& label, API_PARAM(Ref) int32& currentItem, const Array<StringAnsi>& items, int itemsCount = -1, int popupMaxHeightInItems = -1)
    {
        Array<const char*> itemsRaw;
        itemsRaw.Resize(items.Count());
        for (int32 i = 0; i < items.Count(); i++)
            itemsRaw[i] = items[i].GetText();
        if (itemsCount == -1)
            itemsCount = items.Count();
        return ImGui::Combo(label.GetText(), &currentItem, itemsRaw.Get(), itemsCount, popupMaxHeightInItems);
    }

    // Separate items with \0 within a string, end item-list with \0\0. e.g. "One\0Two\0Three\0"
    API_FUNCTION() static bool Combo(const StringAnsiView& label, API_PARAM(Ref) int32& currentItem, const StringAnsiView& itemsSeparatedByZeros, int popupMaxHeightInItems = -1)
    {
        return ImGui::Combo(label.GetText(), &currentItem, itemsSeparatedByZeros.Get(), popupMaxHeightInItems);
    }

public:
    // If vMin >= vMax we have no bound
    API_FUNCTION() static bool DragFloat(const StringAnsiView& label, API_PARAM(Ref) float& v, float vSpeed = 1.0f, float vMin = 0.0f, float vMax = 0.0f, const StringAnsiView& format = "%.3f", ImGuiSliderFlags flags = 0)
    {
        return ImGui::DragFloat(label.GetText(), &v, vSpeed, vMin, vMax, format.GetText(), flags);
    }

    // If vMin >= vMax we have no bound
    API_FUNCTION() static bool DragFloat2(const StringAnsiView& label, API_PARAM(Ref) Float2& v, float vSpeed = 1.0f, float vMin = 0.0f, float vMax = 0.0f, const StringAnsiView& format = "%.3f", ImGuiSliderFlags flags = 0)
    {
        return ImGui::DragFloat2(label.GetText(), (float*)&v, vSpeed, vMin, vMax, format.GetText(), flags);
    }

    // If vMin >= vMax we have no bound
    API_FUNCTION() static bool DragFloat3(const StringAnsiView& label, API_PARAM(Ref) Float3& v, float vSpeed = 1.0f, float vMin = 0.0f, float vMax = 0.0f, const StringAnsiView& format = "%.3f", ImGuiSliderFlags flags = 0)
    {
        return ImGui::DragFloat3(label.GetText(), (float*)&v, vSpeed, vMin, vMax, format.GetText(), flags);
    }

    // If vMin >= vMax we have no bound
    API_FUNCTION() static bool DragFloat4(const StringAnsiView& label, API_PARAM(Ref) Float4& v, float vSpeed = 1.0f, float vMin = 0.0f, float vMax = 0.0f, const StringAnsiView& format = "%.3f", ImGuiSliderFlags flags = 0)
    {
        return ImGui::DragFloat4(label.GetText(), (float*)&v, vSpeed, vMin, vMax, format.GetText(), flags);
    }

    // If vMin >= vMax we have no bound
    API_FUNCTION() static bool DragInt(const StringAnsiView& label, API_PARAM(Ref) int32& v, float vSpeed = 1.0f, int vMin = 0, int vMax = 0, const StringAnsiView& format = "%d", ImGuiSliderFlags flags = 0)
    {
        return ImGui::DragInt(label.GetText(), &v, vSpeed, vMin, vMax, format.GetText(), flags);
    }

public:
    // adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display.
    API_FUNCTION() static bool SliderFloat(const StringAnsiView& label, API_PARAM(Ref) float& v, float vMin, float vMax, const StringAnsiView& format = "%.3f", ImGuiSliderFlags flags = 0)
    {
        return ImGui::SliderFloat(label.GetText(), &v, vMin, vMax, format.GetText(), flags);
    }

    // adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display.
    API_FUNCTION() static bool SliderFloat2(const StringAnsiView& label, API_PARAM(Ref) Float2& v, float vMin, float vMax, const StringAnsiView& format = "%.3f", ImGuiSliderFlags flags = 0)
    {
        return ImGui::SliderFloat2(label.GetText(), (float*)&v, vMin, vMax, format.GetText(), flags);
    }

    // adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display.
    API_FUNCTION() static bool SliderFloat3(const StringAnsiView& label, API_PARAM(Ref) Float3& v, float vMin, float vMax, const StringAnsiView& format = "%.3f", ImGuiSliderFlags flags = 0)
    {
        return ImGui::SliderFloat3(label.GetText(), (float*)&v, vMin, vMax, format.GetText(), flags);
    }

    // adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display.
    API_FUNCTION() static bool SliderFloat4(const StringAnsiView& label, API_PARAM(Ref) Float4& v, float vMin, float vMax, const StringAnsiView& format = "%.3f", ImGuiSliderFlags flags = 0)
    {
        return ImGui::SliderFloat4(label.GetText(), (float*)&v, vMin, vMax, format.GetText(), flags);
    }

    // adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display.
    API_FUNCTION() static bool SliderAngle(const StringAnsiView& label, API_PARAM(Ref) float& vRad, float vDegreesMin = -360.0f, float vDegreesMax = +360.0f, const StringAnsiView& format = "%.0f deg", ImGuiSliderFlags flags = 0)
    {
        return ImGui::SliderAngle(label.GetText(), &vRad, vDegreesMin, vDegreesMax, format.GetText(), flags);
    }

    // adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display.
    API_FUNCTION() static bool SliderInt(const StringAnsiView& label, API_PARAM(Ref) int32& v, int vMin, int vMax, const StringAnsiView& format = "%d", ImGuiSliderFlags flags = 0)
    {
        return ImGui::SliderInt(label.GetText(), &v, vMin, vMax, format.GetText(), flags);
    }

public:
    // Input text field.
    API_FUNCTION() static bool InputText(const StringAnsiView& label, API_PARAM(Ref) StringAnsi& str, ImGuiInputTextFlags flags = 0)
    {
        ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
        flags |= ImGuiInputTextFlags_CallbackResize;
        InputTextCallbackUserData textUserData;
        textUserData.Str = &str;
        return ImGui::InputText(label.GetText(), (char*)str.GetText(), str.Length() + 1, flags, InputTextCallback, &textUserData);
    }

    // Input multi-line text field.
    API_FUNCTION() static bool InputTextMultiline(const StringAnsiView& label, API_PARAM(Ref) StringAnsi& str, const Float2& size, ImGuiInputTextFlags flags = 0)
    {
        ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
        flags |= ImGuiInputTextFlags_CallbackResize;
        InputTextCallbackUserData textUserData;
        textUserData.Str = &str;
        return ImGui::InputTextMultiline(label.GetText(), (char*)str.GetText(), str.Length() + 1, *(ImVec2*)&size, flags, InputTextCallback, &textUserData);
    }

public:
    // Begin window
    API_FUNCTION() static bool Begin(const StringAnsiView& name, API_PARAM(Ref) bool& open, ImGuiWindowFlags flags = 0)
    {
        return ImGui::Begin(name.GetText(), &open, flags);
    }

    // End window
    API_FUNCTION() static void End()
    {
        ImGui::End();
    }

    // Begin child
    API_FUNCTION() static bool BeginChild(const StringAnsiView& label, const Float2& size = Float2::Zero, bool border = false, ImGuiWindowFlags flags = 0)
    {
        return ImGui::BeginChild(label.GetText(), *(ImVec2*)&size, border, flags);
    }

    // End child
    API_FUNCTION() static void EndChild()
    {
        ImGui::EndChild();
    }

public:
    // Window Scrolling - Get Max X
    API_FUNCTION() static float GetScrollMaxX()
    {
        return ImGui::GetScrollMaxX();
    }

    // Window Scrolling - Get Max Y
    API_FUNCTION() static float GetScrollMaxY()
    {
        return ImGui::GetScrollMaxY();
    }

    // Window Scrolling - Get X
    API_FUNCTION() static float GetScrollX()
    {
        return ImGui::GetScrollX();
    }

    // Window Scrolling - Get Y
    API_FUNCTION() static float GetScrollY()
    {
        return ImGui::GetScrollY();
    }

    // Window Scrolling - Set From X Position
    API_FUNCTION() static void SetScrollFromPosX(float value, float ratio)
    {
        ImGui::SetScrollFromPosX(value, ratio);
    }

    // Window Scrolling - Set From Y Position
    API_FUNCTION() static void SetScrollFromPosY(float value, float ratio)
    {
        ImGui::SetScrollFromPosY(value, ratio);
    }

    // Window Scrolling - Set X Position Ratio
    API_FUNCTION() static void SetScrollHereX(float ratio)
    {
        ImGui::SetScrollHereX(ratio);
    }

    // Window Scrolling - Set Y Position Ratio
    API_FUNCTION() static void SetScrollHereY(float ratio)
    {
        ImGui::SetScrollHereY(ratio);
    }

    // Window Scrolling - Set X Position
    API_FUNCTION() static void SetScrollX(float value)
    {
        ImGui::SetScrollX(value);
    }

    // Window Scrolling - Set Y Position
    API_FUNCTION() static void SetScrollY(float value)
    {
        ImGui::SetScrollY(value);
    }



private:
    struct InputTextCallbackUserData
    {
        StringAnsi* Str;
    };

    static int InputTextCallback(ImGuiInputTextCallbackData* data)
    {
        // Reference: https://github.com/ocornut/imgui/blob/master/misc/cpp/imgui_stdlib.cpp
        auto userData = (InputTextCallbackUserData*)data->UserData;
        if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
        {
            // Resize string
            StringAnsi* str = userData->Str;
            str->Resize(data->BufTextLen);
            data->Buf = (char*)str->Get();
        }
        return 0;
    }
};
