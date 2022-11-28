// Copyright (c) Wojciech Figat. All rights reserved.

using FlaxEngine;

/// <summary>
/// A cardinal direction
/// </summary>
public enum ImGuiDir
{
    /// <summary>
    /// Nothing
    /// </summary>
    None = -1,

    /// <summary>
    /// Left
    /// </summary>
    Left = 0,

    /// <summary>
    /// Right
    /// </summary>
    Right = 1,

    /// <summary>
    /// Up
    /// </summary>
    Up = 2,

    /// <summary>
    /// Down
    /// </summary>
    Down = 3,
};

/// <summary>
/// Flags: for Begin(), BeginChild()
/// </summary>
public enum ImGuiWindowFlags
{
    /// <summary>
    /// None
    /// </summary>
    None = 0,

    /// <summary>
    /// Disable title-bar
    /// </summary>
    NoTitleBar = 1 << 0,

    /// <summary>
    /// Disable user resizing with the lower-right grip
    /// </summary>
    NoResize = 1 << 1,

    /// <summary>
    /// Disable user moving the window
    /// </summary>
    NoMove = 1 << 2,

    /// <summary>
    /// Disable scrollbars (window can still scroll with mouse or programmatically)
    /// </summary>
    NoScrollbar = 1 << 3,

    /// <summary>
    /// Disable user vertically scrolling with mouse wheel. On child window, mouse wheel will be forwarded to the parent unless NoScrollbar is also set.
    /// </summary>
    NoScrollWithMouse = 1 << 4,

    /// <summary>
    /// Disable user collapsing window by double-clicking on it. Also referred to as Window Menu Button (e.g. within a docking node).
    /// </summary>
    NoCollapse = 1 << 5,

    /// <summary>
    /// Resize every window to its content every frame
    /// </summary>
    AlwaysAutoResize = 1 << 6,

    /// <summary>
    /// Disable drawing background color (WindowBg, etc.) and outside border. Similar as using SetNextWindowBgAlpha(0.0f).
    /// </summary>
    NoBackground = 1 << 7,

    /// <summary>
    /// Never load/save settings in .ini file
    /// </summary>
    NoSavedSettings = 1 << 8,

    /// <summary>
    /// Disable catching mouse, hovering test with pass through.
    /// </summary>
    NoMouseInputs = 1 << 9,

    /// <summary>
    /// Has a menu-bar
    /// </summary>
    MenuBar = 1 << 10,

    /// <summary>
    /// Allow horizontal scrollbar to appear (off by default). You may use SetNextWindowContentSize(ImVec2(width,0.0f)); prior to calling Begin() to specify width. Read code in imgui_demo in the "Horizontal Scrolling" section.
    /// </summary>
    HorizontalScrollbar = 1 << 11,

    /// <summary>
    /// Disable taking focus when transitioning from hidden to visible state
    /// </summary>
    NoFocusOnAppearing = 1 << 12,

    /// <summary>
    /// Disable bringing window to front when taking focus (e.g. clicking on it or programmatically giving it focus)
    /// </summary>
    NoBringToFrontOnFocus = 1 << 13,

    /// <summary>
    /// Always show vertical scrollbar (even if ContentSize.y &lt; Size.y)
    /// </summary>
    AlwaysVerticalScrollbar = 1 << 14,

    /// <summary>
    /// Always show horizontal scrollbar (even if ContentSize.x &lt; Size.x)
    /// </summary>
    AlwaysHorizontalScrollbar = 1 << 15,

    /// <summary>
    /// Ensure child windows without border uses style.WindowPadding (ignored by default for non-bordered child windows, because more convenient)
    /// </summary>
    AlwaysUseWindowPadding = 1 << 16,

    /// <summary>
    /// No gamepad/keyboard navigation within the window
    /// </summary>
    NoNavInputs = 1 << 18,

    /// <summary>
    /// No focusing toward this window with gamepad/keyboard navigation (e.g. skipped by CTRL+TAB)
    /// </summary>
    NoNavFocus = 1 << 19,

    /// <summary>
    /// Display a dot next to the title. When used in a tab/docking context, tab is selected when clicking the X + closure is not assumed (will wait for user to stop submitting the tab). Otherwise closure is assumed when pressing the X, so if you keep submitting the tab may reappear at end of tab bar.
    /// </summary>
    UnsavedDocument = 1 << 20,

    /// <summary>
    /// No gamepad/keyboard navigation within the window
    /// No focusing toward this window with gamepad/keyboard navigation (e.g. skipped by CTRL+TAB)
    /// </summary>
    NoNav = ImGuiWindowFlags.NoNavInputs | ImGuiWindowFlags.NoNavFocus,

    /// <summary>
    /// Disable title-bar
    /// Disable user resizing with the lower-right grip
    /// Disable scrollbars (window can still scroll with mouse or programmatically)
    /// Disable user collapsing window by double-clicking on it. Also referred to as Window Menu Button (e.g. within a docking node).
    /// </summary>
    NoDecoration = ImGuiWindowFlags.NoTitleBar | ImGuiWindowFlags.NoResize | ImGuiWindowFlags.NoScrollbar | ImGuiWindowFlags.NoCollapse,

    /// <summary>
    /// Disable catching mouse, hovering test with pass through.
    /// No gamepad/keyboard navigation within the window
    /// No focusing toward this window with gamepad/keyboard navigation (e.g. skipped by CTRL+TAB)
    /// </summary>
    NoInputs = ImGuiWindowFlags.NoMouseInputs | ImGuiWindowFlags.NoNavInputs | ImGuiWindowFlags.NoNavFocus,

    // [Internal]
    /// <summary>
    /// [BETA] On child window: allow gamepad/keyboard navigation to cross over parent border to this child or between sibling child windows.
    /// </summary>
    NavFlattened = 1 << 23,

    /// <summary>
    /// Don't use! For internal use by BeginChild()
    /// </summary>
    ChildWindow = 1 << 24,

    /// <summary>
    /// Don't use! For internal use by BeginTooltip()
    /// </summary>
    Tooltip = 1 << 25,

    /// <summary>
    /// Don't use! For internal use by BeginPopup()
    /// </summary>
    Popup = 1 << 26,

    /// <summary>
    /// Don't use! For internal use by BeginPopupModal()
    /// </summary>
    Modal = 1 << 27,

    /// <summary>
    /// Don't use! For internal use by BeginMenu()
    /// </summary>
    ChildMenu = 1 << 28,
}

/// <summary>
/// Flags for DragFloat(), DragInt(), SliderFloat(), SliderInt() etc.
/// </summary>
public enum ImGuiSliderFlags
{
    /// <summary>
    /// Nothing
    /// </summary>
    None = 0,

    /// <summary>
    /// Clamp value to min/max bounds when input manually with CTRL+Click. By default CTRL+Click allows going out of bounds.
    /// </summary>
    AlwaysClamp = 1 << 4,

    /// <summary>
    /// Make the widget logarithmic (linear otherwise). Consider using ImGuiSliderFlags_NoRoundToFormat with this if using a format-string with small amount of digits.
    /// </summary>
    Logarithmic = 1 << 5,

    /// <summary>
    /// Disable rounding underlying value to match precision of the display format string (e.g. %.3f values are rounded to those 3 digits)
    /// </summary>
    NoRoundToFormat = 1 << 6,

    /// <summary>
    /// Disable CTRL+Click or Enter key allowing to input text directly into the widget
    /// </summary>
    NoInput = 1 << 7,
};

/// <summary>
/// Flags for InputText().
/// </summary>
public enum ImGuiInputTextFlags
{
    /// <summary>
    /// Nothing.
    /// </summary>
    None = 0,

    /// <summary>
    /// Allow 0123456789.+-*/
    /// </summary>
    CharsDecimal = 1 << 0,

    /// <summary>
    /// Allow 0123456789ABCDEFabcdef
    /// </summary>
    CharsHexadecimal = 1 << 1,

    /// <summary>
    /// Turn a..z into A..Z
    /// </summary>
    CharsUppercase = 1 << 2,

    /// <summary>
    /// Filter out spaces, tabs
    /// </summary>
    CharsNoBlank = 1 << 3,

    /// <summary>
    /// Select entire text when first taking mouse focus
    /// </summary>
    AutoSelectAll = 1 << 4,

    /// <summary>
    /// Return 'true' when Enter is pressed (as opposed to every time the value was modified). Consider looking at the IsItemDeactivatedAfterEdit() function.
    /// </summary>
    EnterReturnsTrue = 1 << 5,

    /// <summary>
    /// Callback on pressing TAB (for completion handling)
    /// </summary>
    CallbackCompletion = 1 << 6,

    /// <summary>
    /// Callback on pressing Up/Down arrows (for history handling)
    /// </summary>
    CallbackHistory = 1 << 7,

    /// <summary>
    /// Callback on each iteration. User code may query cursor position, modify text buffer.
    /// </summary>
    CallbackAlways = 1 << 8,

    /// <summary>
    /// Callback on character inputs to replace or discard them. Modify 'EventChar' to replace or discard, or return 1 in callback to discard.
    /// </summary>
    CallbackCharFilter = 1 << 9,

    /// <summary>
    /// Pressing TAB input a '\t' character into the text field
    /// </summary>
    AllowTabInput = 1 << 10,

    /// <summary>
    /// In multi-line mode, unfocus with Enter, add new line with Ctrl+Enter (default is opposite: unfocus with Ctrl+Enter, add line with Enter).
    /// </summary>
    CtrlEnterForNewLine = 1 << 11,

    /// <summary>
    /// Disable following the cursor horizontally
    /// </summary>
    NoHorizontalScroll = 1 << 12,

    /// <summary>
    /// Overwrite mode
    /// </summary>
    AlwaysOverwrite = 1 << 13,

    /// <summary>
    /// Read-only mode
    /// </summary>
    ReadOnly = 1 << 14,

    /// <summary>
    /// Password mode, display all characters as '*'
    /// </summary>
    Password = 1 << 15,

    /// <summary>
    /// Disable undo/redo. Note that input text owns the text data while active, if you want to provide your own undo/redo stack you need e.g. to call ClearActiveID().
    /// </summary>
    NoUndoRedo = 1 << 16,

    /// <summary>
    /// Allow 0123456789.+-*/eE (Scientific notation input)
    /// </summary>
    CharsScientific = 1 << 17,

    /// <summary>
    /// Callback on buffer capacity changes request (beyond 'buf_size' parameter value), allowing the string to grow. Notify when the string wants to be resized (for string types which hold a cache of their Size). You will be provided a new BufSize in the callback and NEED to honor it. (see misc/cpp/imgui_stdlib.h for an example of using this)
    /// </summary>
    CallbackResize = 1 << 18,

    /// <summary>
    /// Callback on any edit (note that InputText() already returns true on edit, the callback is useful mainly to manipulate the underlying buffer while focus is active)
    /// </summary>
    CallbackEdit = 1 << 19,
};

partial class ImGui
{
    /// <summary>
    /// Button.
    /// </summary>
    [Unmanaged]
    public static bool Button(string label)
    {
        return Button(label, Float2.Zero);
    }

    /// <summary>
    /// Image.
    /// </summary>
    [Unmanaged]
    public static void Image(GPUTexture texture, Float2 size)
    {
        Image(texture, size, Float2.Zero, Float2.One, Color.White, Color.Transparent);
    }

    /// <summary>
    /// less than 0 framePadding uses default frame padding settings. 0 for no padding.
    /// </summary>
    [Unmanaged]
    public static bool ImageButton(GPUTexture texture, Float2 size)
    {
        return ImageButton(texture, size, Float2.Zero, Float2.One, Color.White, Color.Transparent);
    }

    /// <summary>
    /// ProgressBar.
    /// </summary>
    [Unmanaged]
    public static void ProgressBar(float fraction)
    {
        ProgressBar(fraction, new Float2(-1, 0));
    }

    /// <summary>
    /// Input multi-line text field.
    /// </summary>
    [Unmanaged]
    public static bool InputTextMultiline(string label, ref string str, ImGuiInputTextFlags flags = 0)
    {
        return InputTextMultiline(label, ref str, new Float2(0, 0), flags);
    }

    /// <summary>
    /// Begin Child.
    /// </summary>
    [Unmanaged]
    public static bool BeginChild(string label)
    {
        //return BeginChild(label, Float2.Zero, false, 0);
        return false;
    }
}
