// Copyright (c) Wojciech Figat. All rights reserved.

#pragma once

#include "Engine/Core/Delegate.h"
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

    // Formatted text with an horizontal line.
    API_FUNCTION() static void SeparatorText(const StringAnsiView& label)
    {
        ImGui::SeparatorText(label.GetText());
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
        ImGui::Text("%s", text.GetText());
    }

    // Shortcut for PushStyleColor(ImGuiCol_Text, col); Text(text); PopStyleColor();
    API_FUNCTION() static void TextColored(const Color& col, const StringAnsiView& text)
    {
        ImGui::TextColored(*(ImVec4*)&col, "%s", text.GetText());
    }

    // Shortcut for PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]); Text(text); PopStyleColor();
    API_FUNCTION() static void TextDisabled(const StringAnsiView& text)
    {
        ImGui::TextDisabled("%s", text.GetText());
    }

    // Shortcut for PushTextWrapPos(0.0f); Text(text); PopTextWrapPos();. Note that this won't work on an auto-resizing window if there's no other widgets to extend the window width, yoy may need to set a size using SetNextWindowSize().
    API_FUNCTION() static void TextWrapped(const StringAnsiView& text)
    {
        ImGui::TextWrapped("%s", text.GetText());
    }

    // Display text+label aligned the same way as value+label widgets.
    API_FUNCTION() static void LabelText(const StringAnsiView& label, const StringAnsiView& text)
    {
        ImGui::LabelText(label.GetText(), "%s", text.GetText());
    }

    // Shortcut for Bullet()+Text().
    API_FUNCTION() static void BulletText(const StringAnsiView& text)
    {
        ImGui::BulletText("%s", text.GetText());
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
    
    /// <summary>
    /// Color Editor/Picker. Has a little color square that can be left-clicked to open a picker, and right-clicked to open an option menu.
    /// Doesn't modify the alpha value of the color.
    /// </summary>
    API_FUNCTION() static void ColorEdit3(const StringAnsiView& label, API_PARAM(Ref) Color& color, ImGuiColorEditFlags flags = 0)
    {
        ImGui::ColorEdit3(label.GetText(), (float*)&color, flags);
    }

    // Color Editor/Picker. Has a little color square that can be left-clicked to open a picker, and right-clicked to open an option menu.
    API_FUNCTION() static void ColorEdit4(const StringAnsiView& label, API_PARAM(Ref) Color& color, ImGuiColorEditFlags flags = 0)
    {
        ImGui::ColorEdit4(label.GetText(), (float*)&color, flags);
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

    // Begin window
    API_FUNCTION() static bool Begin(const StringAnsiView& name, ImGuiWindowFlags flags = 0)
    {
        return ImGui::Begin(name.GetText(), nullptr, flags);
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

public: // Menus
    /// <summary>
    /// Use on a window with <see cref="ImGuiWindowFlags.MenuBar"/> to append to its menu bar.
    /// </summary>
    API_FUNCTION() static bool BeginMenuBar()
    {
        return ImGui::BeginMenuBar();
    }
    
    // Only call EndMenuBar if BeginMenuBar returns true.
    API_FUNCTION() static void EndMenuBar()
    {
        ImGui::EndMenuBar();
    }

    // Use BeginMenu to create a menu. You can call BeginMenu multiple time with the same identifier to append more items to it.
    API_FUNCTION() static bool BeginMenu(const StringAnsiView& label, bool enabled = true)
    {
        return ImGui::BeginMenu(label.GetText(), enabled);
    }

    // Only call EndMenu if BeginMenu returns true.
    API_FUNCTION() static void EndMenu()
    {
        ImGui::EndMenu();
    }

    /// <summary>
    /// Adds a new item to the menu.
    /// </summary>
    API_FUNCTION() static bool MenuItem(const StringAnsiView& label, const StringAnsiView& shortcut = StringAnsiView::Empty, bool selected = false, bool enabled = true)
    {
        return ImGui::MenuItem(label.GetText(), shortcut.GetText(), selected, enabled);
    }

public: // Trees

    /// <summary>
    /// Creates a tree node with a specified label.
    /// </summary>
    API_FUNCTION() static bool TreeNode(const StringAnsiView& label) 
    {
        return ImGui::TreeNode(label.GetText());
    }

    /// <summary>
    /// Creates a tree node with a specified identifier and label.
    /// </summary>
    API_FUNCTION() static bool TreeNode(const StringAnsiView& id, const StringAnsiView& label) 
    {
        return ImGui::TreeNode(id.GetText(), "%s", label.GetText());
    }

    /// <summary>
    /// Creates an extended tree node with a specified label and flags.
    /// </summary>
    API_FUNCTION() static bool TreeNodeEx(const StringAnsiView& label, ImGuiTreeNodeFlags flags = 0) 
    {
        return ImGui::TreeNodeEx(label.GetText(), flags);
    }
    
    /// <summary>
    /// Create an expandable tree node with a specified identifier, flags, and label.
    /// </summary>
    API_FUNCTION() static bool TreeNodeEx(const StringAnsiView& id, ImGuiTreeNodeFlags flags, const StringAnsiView& label) 
    {
        return ImGui::TreeNodeEx(id.GetText(), flags, "%s", label.GetText());
    }
    
    // Indent()+PushId(). Already called by TreeNode() when returning true, but you can call TreePush/TreePop yourself if desired.
    API_FUNCTION() static void TreePush(const StringAnsiView& id) 
    {
        ImGui::TreePush(id.GetText());
    }

    // Unindent()+PopId()
    API_FUNCTION() static void TreePop() 
    {
        ImGui::TreePop();
    }
    
    // Retrieves the spacing between a tree node and its label.
    API_FUNCTION() static float GetTreeNodeToLabelSpacing() 
    {
        return ImGui::GetTreeNodeToLabelSpacing();
    }

    /// <summary>
    /// Creates a collapsible header with a specified label and optional flags.
    /// Doesn't indent nor push on ID stack. user doesn't have to call TreePop().
    /// </summary>
    API_FUNCTION() static bool CollapsingHeader(const StringAnsiView& label, ImGuiTreeNodeFlags flags = 0) 
    {
        return ImGui::CollapsingHeader(label.GetText(), flags);
    }
    
    /// <summary>
    /// Creates a collapsible header with a specified label and optional flags.
    /// Doesn't indent nor push on ID stack. user doesn't have to call TreePop().
    /// </summary>
    API_FUNCTION() static bool CollapsingHeader(const StringAnsiView& label, API_PARAM(ref) bool& visible, ImGuiTreeNodeFlags flags = 0) 
    {
        return ImGui::CollapsingHeader(label.GetText(), &visible, flags);
    }

    // Set the open state of the next ImGui item.
    API_FUNCTION() static void SetNextItemOpen(bool isOpen, ImGuiCond cond = 0)
    {
        return ImGui::SetNextItemOpen(isOpen, cond);
    }

public: // Selectables

    // Create a selectable item with a specified label, selection state, flags, and size.
    API_FUNCTION() static bool Selectable(const StringAnsiView& label, bool selected, ImGuiSelectableFlags flags, const Float2& size = Float2::Zero)
    {
        return ImGui::Selectable(label.GetText(), selected, flags, *(ImVec2*)&size);
    }

    // Create a selectable item with a specified label, selection state, flags, and size.
    API_FUNCTION() static bool Selectable(const StringAnsiView& label, API_PARAM(ref) bool* selected, ImGuiSelectableFlags flags, const Float2& size = Float2::Zero)
    {
        return ImGui::Selectable(label.GetText(), selected, flags, *(ImVec2*)&size);
    }

public: // Popups

    // Call to mark popup as open (don't call every frame!).
    API_FUNCTION() static void OpenPopup(const StringAnsiView& strId, ImGuiPopupFlags flags = 0)
    {
        ImGui::OpenPopup(strId.GetText(), flags);
    }

    // Call to mark popup as open (don't call every frame!).
    API_FUNCTION() static void OpenPopup(uint32 id, ImGuiPopupFlags flags = 0)
    {
        ImGui::OpenPopup(id, flags);
    }

    /// <summary>
    /// Helper to open popup when clicked on last item. Default to ImGuiPopupFlags_MouseButtonRight == 1.
    /// (note: actually triggers on the mouse _released_ event to be consistent with popup behaviors)
    /// </summary>
    API_FUNCTION() static void OpenPopupOnItemClick(const StringAnsiView& strId, ImGuiPopupFlags flags)
    {
        ImGui::OpenPopupOnItemClick(strId.GetText(), flags);
    }

    // Manually close the popup we have begin-ed into
    API_FUNCTION() static void CloseCurrentPopup()
    {
        ImGui::CloseCurrentPopup();
    }

    /// <summary>
    /// open+begin popup when clicked on last item. Use str_id==NULL to associate the popup to previous item.
    /// If you want to use that on a non-interactive item such as Text() you need to pass in an explicit ID here.
    /// </summary>
    API_FUNCTION() static bool BeginPopupContextItem(const StringAnsiView& strId, ImGuiPopupFlags flags)
    {
        return ImGui::BeginPopupContextItem(strId.GetText(), flags);
    }

    // open+begin popup when clicked on current window.
    API_FUNCTION() static bool BeginPopupContextWindow(const StringAnsiView& strId, ImGuiPopupFlags flags)
    {
        return ImGui::BeginPopupContextWindow(strId.GetText(), flags);
    }

    // open+begin popup when clicked in void (where there are no windows).
    API_FUNCTION() static bool BeginPopupContextVoid(const StringAnsiView& strId, ImGuiPopupFlags flags)
    {
        return ImGui::BeginPopupContextVoid(strId.GetText(), flags);
    }

    // Only call EndPopup() if BeginPopupXXX() returns true!
    API_FUNCTION() static void EndPopup()
    {
        ImGui::EndPopup();
    }

public: // Window manipulation

    // Set next window position. Call before Begin(). Use pivot=(0.5f,0.5f) to center on given point, etc.
    API_FUNCTION() static void SetNextWindowPos(const Float2& pos, ImGuiCond cond, const Float2& pivot)
    {
        ImGui::SetNextWindowPos(*(ImVec2*)&pos, cond, *(ImVec2*)&pivot);
    }

    // Set next window size. Set axis to 0.0f to force an auto-fit on this axis. Call before Begin().
    API_FUNCTION() static void SetNextWindowSize(const Float2& size, ImGuiCond cond = 0)
    {
        ImGui::SetNextWindowSize(*(ImVec2*)&size, cond);
    }

    /// <summary>
    /// Set next window content size (~ scrollable client area, which enforce the range of scrollbars).
    /// Not including window decorations (title bar, menu bar, etc.) nor WindowPadding.
    /// Set an axis to 0.0f to leave it automatic. call before Begin().
    /// </summary>
    API_FUNCTION() static void SetNextWindowContentSize(const Float2& size)
    {
        ImGui::SetNextWindowContentSize(*(ImVec2*)&size);
    }

    // Set next window collapsed state. Call before Begin().
    API_FUNCTION() static void SetNextWindowCollapsed(bool collapsed, ImGuiCond cond = 0)
    {
        ImGui::SetNextWindowCollapsed(collapsed, cond);
    }

    // Set next window to be focused / top-most. Call before Begin().
    API_FUNCTION() static void SetNextWindowFocus()
    {
        ImGui::SetNextWindowFocus();
    }

    // Set next window scrolling value (use &lt; 0.0f to not affect a given axis).
    API_FUNCTION() static void SetNextWindowScroll(const Float2& scroll)
    {
        ImGui::SetNextWindowScroll(*(ImVec2*)&scroll);
    }

    /// <summary>
    /// Set next window background color alpha.
    /// Helper to easily override the Alpha component of ImGuiCol_WindowBg/ChildBg/PopupBg.
    /// You may also use ImGuiWindowFlags_NoBackground.
    /// </summary>
    API_FUNCTION() static void SetNextWindowBgAlpha(float alpha)
    {
        ImGui::SetNextWindowBgAlpha(alpha);
    }

    /// <summary>
    /// (not recommended) set current window position - call within Begin()/End().
    /// Prefer using SetNextWindowPos(), as this may incur tearing and side-effects.
    /// </summary>
    API_FUNCTION() static void SetWindowPos(const Float2& pos, ImGuiCond cond = 0)
    {
        ImGui::SetWindowPos(*(ImVec2*)&pos, cond);
    }

    /// <summary>
    /// (Not Recommended) Set current window size - call within Begin()/End(). Set to ImVec2(0, 0) to force an auto-fit.
    /// Prefer using SetNextWindowSize(), as this may incur tearing and minor side-effects.
    /// </summary>
    API_FUNCTION() static void SetWindowSize(const Float2& size, ImGuiCond cond = 0)
    {
        ImGui::SetWindowSize(*(ImVec2*)&size, cond);
    }

    // (Not recommended) Set current window collapsed state. prefer using SetNextWindowCollapsed().
    API_FUNCTION() static void SetWindowCollapsed(bool collapsed, ImGuiCond cond = 0)
    {
        ImGui::SetWindowCollapsed(collapsed, cond);
    }

    // (Not recommended) Set current window to be focused / top-most. Prefer using SetNextWindowFocus()
    API_FUNCTION() static void SetWindowFocus()
    {
        ImGui::SetWindowFocus();
    }
    
    // Set named window position.
    API_FUNCTION() static void SetWindowPos(const StringAnsiView& name, const Float2& pos, ImGuiCond cond = 0)
    {
        ImGui::SetWindowPos(name.GetText(), *(ImVec2*)&pos, cond);
    }

    // Set named window size. Set axis to 0.0f to force an auto-fit on this axis.
    API_FUNCTION() static void SetWindowSize(const StringAnsiView& name, const Float2& size, ImGuiCond cond = 0)
    {
        ImGui::SetWindowSize(name.GetText(), *(ImVec2*)&size, cond);
    }

    // Set named window collapsed state.
    API_FUNCTION() static void SetWindowCollapsed(const StringAnsiView& name, bool collapsed, ImGuiCond cond = 0)
    {
        ImGui::SetWindowCollapsed(name.GetText(), collapsed, cond);
    }

    // Set named window to be focused / top-most. Use NULL to remove focus.
    API_FUNCTION() static void SetWindowFocus(const StringAnsiView& name)
    {
        ImGui::SetWindowFocus(name.GetText());
    }

public: // Parameters stacks (shared)

    // Modify a style color. Always use this if you modify the style after NewFrame().
    API_FUNCTION() static void PushStyleColor(ImGuiCol idx, uint32 col)
    {
        ImGui::PushStyleColor(idx, col);
    }
    
    // Modify a style color. Always use this if you modify the style after NewFrame().
    API_FUNCTION() static void PushStyleColor(ImGuiCol idx, const Float4& col)
    {
        ImGui::PushStyleColor(idx, *(ImVec4*)&col);
    }

    // Pop style color.
    API_FUNCTION() static void PopStyleColor(int count = 1)
    {
        ImGui::PopStyleColor(count);
    }

    // Modify a style float variable. Always use this if you modify the style after NewFrame().
    API_FUNCTION() static void PushStyleVar(ImGuiStyleVar idx, float val)
    {
        ImGui::PushStyleVar(idx, val);
    }

    // Modify a style Float2 variable. Always use this if you modify the style after NewFrame().
    API_FUNCTION() static void PushStyleVar(ImGuiStyleVar idx, const Float2& val)
    {
        ImGui::PushStyleVar(idx, *(ImVec2*)&val);
    }

    // Pop style var.
    API_FUNCTION() static void PopStyleVar(int count = 1)
    {
        ImGui::PopStyleVar(count);
    }

    // Allow focusing using TAB/Shift-TAB, enabled by default but you can disable it for certain widgets.
    API_FUNCTION() static void PushTabStop(bool tabStop)
    {
        ImGui::PushTabStop(tabStop);
    }

    // Pop tab stop
    API_FUNCTION() static void PopTabStop()
    {
        ImGui::PopTabStop();
    }

    /// <summary>
    /// In 'repeat' mode, Button*() functions return repeated true in a typematic manner (using io.KeyRepeatDelay/io.KeyRepeatRate setting).
    /// Note that you can call IsItemActive() after any Button() to tell if the button is held in the current frame.
    /// </summary>
    API_FUNCTION() static void PushButtonRepeat(bool repeat)
    {
        ImGui::PushButtonRepeat(repeat);
    }

    // Pop button repeat.
    API_FUNCTION() static void PopButtonRepeat()
    {
        ImGui::PopButtonRepeat();
    }

public: // Parameters stacks (current window)

    /// <summary>
    /// Push width of items for common large "item+label" widgets. &gt; 0.0f: width in pixels,
    /// &lt; 0.0f align xx pixels to the right of window (so -FLT_MIN always align width to the right side).
    /// </summary>
    API_FUNCTION() static void PushItemWidth(float itemWidth)
    {
        ImGui::PushItemWidth(itemWidth);
    }

    // Pop item width
    API_FUNCTION() static void PopItemWidth()
    {
        ImGui::PopItemWidth();
    }

    /// <summary>
    /// set width of the _next_ common large "item+label" widget. &gt; 0.0f: width in pixels,
    /// &lt; 0.0f align xx pixels to the right of window (so -FLT_MIN always align width to the right side)
    /// </summary>
    API_FUNCTION() static void SetNextItemWidth(float itemWidth)
    {
        ImGui::SetNextItemWidth(itemWidth);
    }

    /// <summary>
    /// Width of item given pushed settings and current cursor position.
    /// NOT necessarily the width of last item unlike most 'Item' functions.
    /// </summary>
    API_FUNCTION() static float CalcItemWidth()
    {
        return ImGui::CalcItemWidth();
    }

    /// <summary>
    /// Push word-wrapping position for Text*() commands.
    /// &lt; 0.0f: no wrapping; 0.0f: wrap to end of window (or column); > 0.0f: wrap at 'wrap_pos_x' position in window local space.
    /// </summary>
    API_FUNCTION() static void PushTextWrapPos(float warpLocalPosX = 0.0f)
    {
        ImGui::PushTextWrapPos(warpLocalPosX);
    }

    // Pop text wrap pos.
    API_FUNCTION() static void PopTextWrapPos()
    {
        ImGui::PopTextWrapPos();
    }

public: // Item/Widgets Utilities and Query Functions
    
    // Is the last item hovered? (and usable, aka not blocked by a popup, etc.). See ImGuiHoveredFlags for more options.
    API_FUNCTION() static bool IsItemHovered(ImGuiHoveredFlags flags = 0) {return ImGui::IsItemHovered(flags);}

    // Is the last item active? (e.g. button being held, text field being edited. This will continuously return true while holding mouse button on an item. Items that don't interact will always return false)
    API_FUNCTION() static bool IsItemActive() { return ImGui::IsItemActive(); }

    // is the last item focused for keyboard/gamepad navigation?
    API_FUNCTION() static bool IsItemFocused() {return ImGui::IsItemFocused();}

    // is the last item hovered and mouse clicked on? Important: is NOT equivalent to the behavior of e.g. Button(). Read comments in function definition.
    API_FUNCTION() static bool IsItemClicked(ImGuiMouseButton mouseButton = 0) {return ImGui::IsItemClicked(mouseButton);}

    // is the last item visible? (items may be out of sight because of clipping/scrolling)
    API_FUNCTION() static bool IsItemVisible() {return ImGui::IsItemVisible();}

    // did the last item modify its underlying value this frame? or was pressed? This is generally the same as the "bool" return value of many widgets.
    API_FUNCTION() static bool IsItemEdited() {return ImGui::IsItemEdited();}

    // was the last item just made active (item was previously inactive).
    API_FUNCTION() static bool IsItemActivated() {return ImGui::IsItemActivated();}

    // was the last item just made inactive (item was previously active). Useful for Undo/Redo patterns with widgets that require continuous editing.
    API_FUNCTION() static bool IsItemDeactivated() {return ImGui::IsItemDeactivated();}

    // was the last item just made inactive and made a value change when it was active? (e.g. Slider/Drag moved). Useful for Undo/Redo patterns with widgets that require continuous editing. Note that you may get false positives (some widgets such as Combo()/ListBox()/Selectable() will return true even when clicking an already selected item).
    API_FUNCTION() static bool IsItemDeactivatedAfterEdit() {return ImGui::IsItemDeactivatedAfterEdit();}

    // was the last item open state toggled? set by TreeNode().
    API_FUNCTION() static bool IsItemToggledOpen(){return ImGui::IsItemToggledOpen();}

    // is any item focused?
    API_FUNCTION() static bool IsAnyItemHovered(){return ImGui::IsAnyItemFocused();}

    // is any item active?
    API_FUNCTION() static bool IsAnyItemActive(){return ImGui::IsAnyItemActive();}

    // is any item focused?
    API_FUNCTION() static bool IsAnyItemFocused(){return ImGui::IsAnyItemFocused();}

    // get ID of last item (~~ often same ImGui::GetID(label) beforehand)
    API_FUNCTION() static uint32 GetItemID() {return static_cast<uint32>(ImGui::GetItemID());}

    // get upper-left bounding rectangle of the last item (screen space)
    API_FUNCTION() static Float2 GetItemRectMin()
    {
        const auto min = ImGui::GetItemRectMin();
        return {min.x, min.y};
    }

    // get lower-right bounding rectangle of the last item (screen space)
    API_FUNCTION() static Float2 GetItemRectMax()
    {
        const auto max = ImGui::GetItemRectMax();
        return {max.x, max.y};
    }

    // get size of last item
    API_FUNCTION() static Float2 GetItemRectSize()
    {
        const auto size = ImGui::GetItemRectSize();
        return {size.x, size.y};
    }

    // - A tooltip window can contain items of any types. SetTooltip() is a shortcut for the 'if (BeginTooltip()) { Text(...); EndTooltip(); }' idiom.
    API_FUNCTION() static bool BeginTooltip(){return ImGui::BeginTooltip();}

    // only call EndTooltip() if BeginTooltip()/BeginItemTooltip() returns true!
    API_FUNCTION() static void EndTooltip() {ImGui::EndTooltip();}

    // set a text-only tooltip. Often used after a ImGui::IsItemHovered() check. Override any previous call to SetTooltip().
    API_FUNCTION() static void SetTooltip(const StringAnsiView& fmt)
    {
        ImGui::SetTooltip("%s", fmt.GetText());
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
    
public:
    // Plot lines.
    API_FUNCTION() static void PlotLines(
        const StringAnsiView& label, 
        const Array<float>& values, 
        int valuesOffset, 
        const StringAnsiView& overlayText,
        float scaleMin,
        float scaleMax,
        const Float2& graphSize,
        int stride)
    {
        ImGui::PlotLines(label.GetText(), values.Get(), values.Count(), valuesOffset, overlayText.GetText(), scaleMin, scaleMax, *(ImVec2*)&graphSize, stride);
    }
    
    // Plot lines. Use a callback to provide the values.
    API_FUNCTION() static void PlotLines(
        const StringAnsiView& label, 
        Function<float(int)> valuesGetter,
        int valuesCount,
        int valuesOffset, 
        const StringAnsiView& overlayText,
        float scaleMin,
        float scaleMax,
        const Float2& graphSize)
    {
        auto getter = [](void* data, int i) -> float
        {
            const auto function = *static_cast<Function<float(int)>*>(data);
            return function(i);
        };
        ImGui::PlotLines(label.GetText(), getter, &valuesGetter, valuesCount, valuesOffset, overlayText.GetText(),  scaleMin, scaleMax, *(ImVec2*)&graphSize);
    }

    // Plot histogram.
    API_FUNCTION() static void PlotHistogram(
        const StringAnsiView& label, 
        const Array<float>& values, 
        int valuesOffset, 
        const StringAnsiView& overlayText,
        float scaleMin,
        float scaleMax,
        const Float2& graphSize,
        int stride = 4)
    {
        ImGui::PlotHistogram(label.GetText(), values.Get(), values.Count(), valuesOffset, overlayText.GetText(), scaleMin, scaleMax, *(ImVec2*)&graphSize, stride);
    }

    // Plot histogram. Use a callback to provide the values.
    API_FUNCTION() static void PlotHistogram(
        const StringAnsiView& label, 
        Function<float(int)> valuesGetter,
        int valuesCount,
        int valuesOffset, 
        const StringAnsiView& overlayText,
        float scaleMin,
        float scaleMax,
        const Float2& graphSize,
        int stride = 4)
    {
        auto getter = [](void* data, int i) -> float
        {
            const auto function = *static_cast<Function<float(int)>*>(data);
            return function(i);
            
        };
        ImGui::PlotHistogram(label.GetText(), getter, &valuesGetter, valuesCount, valuesOffset, overlayText.GetText(), scaleMin, scaleMax, *(ImVec2*)&graphSize);
    }

    // Get the time since startup in ms.
    API_FUNCTION() static double GetTime()
    {
        return ImGui::GetTime();
    }

    // Get the font size.
    API_FUNCTION() static float GetFontSize()
    {
        return ImGui::GetFontSize();
    }

    // Get the current version of the ImGui library.
    API_FUNCTION() static String GetVersion()
    {
        return String(ImGui::GetVersion());
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
