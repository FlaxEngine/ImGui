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

/// <summary>
/// Flags for configuring the behavior and appearance of color editing and picking widgets in ImGui.
/// </summary>
public enum ImGuiColorEditFlags
{
    /// <summary>
    /// No special flags.
    /// </summary>
    None = 0,

    /// <summary>
    /// Ignore the Alpha component (will only read 3 components from the input pointer).
    /// </summary>
    NoAlpha = 1 << 1,

    /// <summary>
    /// Disable the color picker when clicking on the color square.
    /// </summary>
    NoPicker = 1 << 2,

    /// <summary>
    /// Disable toggling options menu when right-clicking on inputs/small preview.
    /// </summary>
    NoOptions = 1 << 3,

    /// <summary>
    /// Disable the color square preview next to the inputs (e.g., to show only the inputs).
    /// </summary>
    NoSmallPreview = 1 << 4,

    /// <summary>
    /// Disable input sliders/text widgets (e.g., to show only the small preview color square).
    /// </summary>
    NoInputs = 1 << 5,

    /// <summary>
    /// Disable tooltip when hovering the preview.
    /// </summary>
    NoTooltip = 1 << 6,

    /// <summary>
    /// Disable the display of inline text label (the label is still forwarded to the tooltip and picker).
    /// </summary>
    NoLabel = 1 << 7,

    /// <summary>
    /// Disable the bigger color preview on the right side of the picker, use small color square preview instead.
    /// </summary>
    NoSidePreview = 1 << 8,

    /// <summary>
    /// Disable drag and drop target for ColorEdit; disable drag and drop source for ColorButton.
    /// </summary>
    NoDragDrop = 1 << 9,

    /// <summary>
    /// Disable the border for ColorButton (which is enforced by default).
    /// </summary>
    NoBorder = 1 << 10,

    /// <summary>
    /// Show the vertical alpha bar/gradient in the picker for ColorEdit and ColorPicker.
    /// </summary>
    AlphaBar = 1 << 16,

    /// <summary>
    /// Display the preview as a transparent color over a checkerboard, instead of opaque, for ColorEdit, ColorPicker, and ColorButton.
    /// </summary>
    AlphaPreview = 1 << 17,

    /// <summary>
    /// Display half opaque/half checkerboard instead of opaque for ColorEdit, ColorPicker, and ColorButton.
    /// </summary>
    AlphaPreviewHalf = 1 << 18,

    /// <summary>
    /// (WIP) Currently only disable 0.0f to 1.0f limits in RGBA edition (note: you probably want to use ImGuiColorEditFlags_Float flag as well).
    /// </summary>
    Hdr = 1 << 19,

    /// <summary>
    /// Override the display type among RGB/HSV/Hex for ColorEdit; select any combination using one or more of RGB/HSV/Hex for ColorPicker.
    /// </summary>
    DisplayRgb = 1 << 20,

    /// <summary>
    /// Override the display type among RGB/HSV/Hex for ColorEdit; select any combination using one or more of RGB/HSV/Hex for ColorPicker.
    /// </summary>
    DisplayHsv = 1 << 21,

    /// <summary>
    /// Override the display type among RGB/HSV/Hex for ColorEdit; select any combination using one or more of RGB/HSV/Hex for ColorPicker.
    /// </summary>
    DisplayHex = 1 << 22,

    /// <summary>
    /// Display values formatted as 0..255 for ColorEdit, ColorPicker, and ColorButton.
    /// </summary>
    Uint8 = 1 << 23,

    /// <summary>
    /// Display values formatted as 0.0f..1.0f floats instead of 0..255 integers for ColorEdit, ColorPicker, and ColorButton; no round-trip of value via integers.
    /// </summary>
    Float = 1 << 24,

    /// <summary>
    /// Use a bar for Hue and a rectangle for Saturation/Value in the ColorPicker.
    /// </summary>
    PickerHueBar = 1 << 25,

    /// <summary>
    /// Use a wheel for Hue and a triangle for Saturation/Value in the ColorPicker.
    /// </summary>
    PickerHueWheel = 1 << 26,

    /// <summary>
    /// Input and output data in RGB format for ColorEdit and ColorPicker.
    /// </summary>
    InputRgb = 1 << 27,

    /// <summary>
    /// Input and output data in HSV format for ColorEdit and ColorPicker.
    /// </summary>
    InputHsv = 1 << 28,
}

/// <summary>
/// Flags for controlling the behavior of tree nodes in ImGui.
/// </summary>
public enum ImGuiTreeNodeFlags
{
    /// <summary>
    /// No special flags.
    /// </summary>
    None = 0,

    /// <summary>
    /// Draw as selected.
    /// </summary>
    Selected = 1 << 0,

    /// <summary>
    /// Draw frame with background (e.g., for CollapsingHeader).
    /// </summary>
    Framed = 1 << 1,

    /// <summary>
    /// Hit testing to allow subsequent widgets to overlap this one.
    /// </summary>
    AllowOverlap = 1 << 2,

    /// <summary>
    /// Don't do a TreePush() when open (e.g., for CollapsingHeader) = no extra indent nor pushing on the ID stack.
    /// </summary>
    NoTreePushOnOpen = 1 << 3,

    /// <summary>
    /// Don't automatically and temporarily open the node when Logging is active (by default, logging will automatically open tree nodes).
    /// </summary>
    NoAutoOpenOnLog = 1 << 4,

    /// <summary>
    /// Default node to be open.
    /// </summary>
    DefaultOpen = 1 << 5,

    /// <summary>
    /// Need double-click to open node.
    /// </summary>
    OpenOnDoubleClick = 1 << 6,

    /// <summary>
    /// Only open when clicking on the arrow part. If ImGuiTreeNodeFlags.OpenOnDoubleClick is also set, single-click arrow or double-click all box to open.
    /// </summary>
    OpenOnArrow = 1 << 7,

    /// <summary>
    /// No collapsing, no arrow (use as a convenience for leaf nodes).
    /// </summary>
    Leaf = 1 << 8,

    /// <summary>
    /// Display a bullet instead of an arrow. IMPORTANT: node can still be marked open/close if you don't set the Leaf flag!
    /// </summary>
    Bullet = 1 << 9,

    /// <summary>
    /// Use FramePadding (even for an unframed text node) to vertically align text baseline to regular widget height. Equivalent to calling AlignTextToFramePadding().
    /// </summary>
    FramePadding = 1 << 10,

    /// <summary>
    /// Extend the hitbox to the right-most edge, even if not framed. This is not the default to allow adding other items on the same line. In the future, we may refactor the hit system to be front-to-back, allowing natural overlaps, and then this can become the default.
    /// </summary>
    SpanAvailWidth = 1 << 11,

    /// <summary>
    /// Extend the hitbox to the left-most and right-most edges (bypass the indented area).
    /// </summary>
    SpanFullWidth = 1 << 12,

    /// <summary>
    /// (WIP) Navigation: left direction may move to this TreeNode() from any of its child (items submitted between TreeNode and TreePop).
    /// </summary>
    NavLeftJumpsBackHere = 1 << 13,

    // s_NoScrollOnOpen = 1 << 14,  // FIXME: TODO: Disable automatic scroll on TreePop() if node got just open and contents are not visible.

    /// <summary>
    /// Flags for CollapsingHeader.
    /// </summary>
    CollapsingHeader = Framed | NoTreePushOnOpen | NoAutoOpenOnLog,
}

/// <summary>
/// Flags for controlling the conditions used by ImGui functions.
/// </summary>
public enum ImGuiCond
{
    /// <summary>
    /// No condition (always set the variable), same as Always.
    /// </summary>
    None = 0,

    /// <summary>
    /// No condition (always set the variable), same as None.
    /// </summary>
    Always = 1 << 0,

    /// <summary>
    /// Set the variable once per runtime session (only the first call will succeed).
    /// </summary>
    Once = 1 << 1,

    /// <summary>
    /// Set the variable if the object/window has no persistently saved data (no entry in .ini file).
    /// </summary>
    FirstUseEver = 1 << 2,

    /// <summary>
    /// Set the variable if the object/window is appearing after being hidden/inactive (or the first time).
    /// </summary>
    Appearing = 1 << 3,
}

/// <summary>
/// Flags for controlling selectable behavior in ImGui.
/// </summary>
public enum ImGuiSelectableFlags
{
    /// <summary>
    /// No special flags.
    /// </summary>
    None = 0,

    /// <summary>
    /// Clicking this doesn't close the parent popup window.
    /// </summary>
    DontClosePopups = 1 << 0,

    /// <summary>
    /// Selectable frame can span all columns (text will still fit in the current column).
    /// </summary>
    SpanAllColumns = 1 << 1,

    /// <summary>
    /// Generate press events on double-clicks too.
    /// </summary>
    AllowDoubleClick = 1 << 2,

    /// <summary>
    /// Cannot be selected, display grayed-out text.
    /// </summary>
    Disabled = 1 << 3,

    /// <summary>
    /// (WIP) Hit testing to allow subsequent widgets to overlap this one.
    /// </summary>
    AllowOverlap = 1 << 4,
}

/// <summary>
/// Flags for controlling the behavior of popups in ImGui.
/// </summary>
public enum ImGuiPopupFlags
{
    /// <summary>
    /// No special flags.
    /// </summary>
    None = 0,

    /// <summary>
    /// For BeginPopupContext*(): open on Left Mouse release. Guaranteed to always be == 0 (same as ImGuiMouseButton.Left).
    /// </summary>
    MouseButtonLeft = 0,

    /// <summary>
    /// For BeginPopupContext*(): open on Right Mouse release. Guaranteed to always be == 1 (same as ImGuiMouseButton.Right).
    /// </summary>
    MouseButtonRight = 1,

    /// <summary>
    /// For BeginPopupContext*(): open on Middle Mouse release. Guaranteed to always be == 2 (same as ImGuiMouseButton.Middle).
    /// </summary>
    MouseButtonMiddle = 2,

    /// <summary>
    /// Mask for mouse button flags.
    /// </summary>
    MouseButtonMask = 0x1F,

    /// <summary>
    /// Default mouse button for popup open.
    /// </summary>
    MouseButtonDefault = 1,

    /// <summary>
    /// For OpenPopup*(), BeginPopupContext*(): don't open if there's already a popup at the same level of the popup stack.
    /// </summary>
    NoOpenOverExistingPopup = 1 << 5,

    /// <summary>
    /// For BeginPopupContextWindow(): don't return true when hovering items, only when hovering empty space.
    /// </summary>
    NoOpenOverItems = 1 << 6,

    /// <summary>
    /// For IsPopupOpen(): ignore the ImGuiID parameter and test for any popup.
    /// </summary>
    AnyPopupId = 1 << 7,

    /// <summary>
    /// For IsPopupOpen(): search/test at any level of the popup stack (default test in the current level).
    /// </summary>
    AnyPopupLevel = 1 << 8,

    /// <summary>
    /// Combination of AnyPopupId and AnyPopupLevel.
    /// </summary>
    AnyPopup = AnyPopupId | AnyPopupLevel,
}

/// <summary>
/// Enumeration representing ImGui color variables.
/// </summary>
public enum ImGuiCol
{
    /// <summary>
    /// Text color.
    /// </summary>
    Text,

    /// <summary>
    /// Text color for disabled elements.
    /// </summary>
    TextDisabled,

    /// <summary>
    /// Background color of normal windows.
    /// </summary>
    WindowBg,

    /// <summary>
    /// Background color of child windows.
    /// </summary>
    ChildBg,

    /// <summary>
    /// Background color of popups, menus, and tooltips.
    /// </summary>
    PopupBg,

    /// <summary>
    /// Border color.
    /// </summary>
    Border,

    /// <summary>
    /// Border shadow color.
    /// </summary>
    BorderShadow,

    /// <summary>
    /// Background color of checkboxes, radio buttons, plots, sliders, and text input boxes.
    /// </summary>
    FrameBg,

    /// <summary>
    /// Background color of hovered checkboxes, radio buttons, plots, sliders, and text input boxes.
    /// </summary>
    FrameBgHovered,

    /// <summary>
    /// Background color of active (pressed) checkboxes, radio buttons, plots, sliders, and text input boxes.
    /// </summary>
    FrameBgActive,

    /// <summary>
    /// Background color of window title bars.
    /// </summary>
    TitleBg,

    /// <summary>
    /// Background color of active window title bars.
    /// </summary>
    TitleBgActive,

    /// <summary>
    /// Background color of collapsed window title bars.
    /// </summary>
    TitleBgCollapsed,

    /// <summary>
    /// Background color of the menu bar.
    /// </summary>
    MenuBarBg,

    /// <summary>
    /// Background color of scrollbars.
    /// </summary>
    ScrollbarBg,

    /// <summary>
    /// Background color of scrollbar grabbers.
    /// </summary>
    ScrollbarGrab,

    /// <summary>
    /// Background color of scrollbar grabbers when hovered.
    /// </summary>
    ScrollbarGrabHovered,

    /// <summary>
    /// Background color of scrollbar grabbers when active.
    /// </summary>
    ScrollbarGrabActive,

    /// <summary>
    /// Color of check marks (e.g., in checkboxes).
    /// </summary>
    CheckMark,

    /// <summary>
    /// Color of slider grabbers.
    /// </summary>
    SliderGrab,

    /// <summary>
    /// Color of slider grabbers when active.
    /// </summary>
    SliderGrabActive,

    /// <summary>
    /// Background color of buttons.
    /// </summary>
    Button,

    /// <summary>
    /// Background color of buttons when hovered.
    /// </summary>
    ButtonHovered,

    /// <summary>
    /// Background color of buttons when active.
    /// </summary>
    ButtonActive,

    /// <summary>
    /// Background color of headers (used for CollapsingHeader, TreeNode, Selectable, and MenuItem).
    /// </summary>
    Header,

    /// <summary>
    /// Background color of headers when hovered.
    /// </summary>
    HeaderHovered,

    /// <summary>
    /// Background color of headers when active.
    /// </summary>
    HeaderActive,

    /// <summary>
    /// Separator color.
    /// </summary>
    Separator,

    /// <summary>
    /// Separator color when hovered.
    /// </summary>
    SeparatorHovered,

    /// <summary>
    /// Separator color when active.
    /// </summary>
    SeparatorActive,

    /// <summary>
    /// Color of resize grips in the lower-right and lower-left corners of windows.
    /// </summary>
    ResizeGrip,

    /// <summary>
    /// Color of resize grips in the lower-right and lower-left corners of windows when hovered.
    /// </summary>
    ResizeGripHovered,

    /// <summary>
    /// Color of resize grips in the lower-right and lower-left corners of windows when active.
    /// </summary>
    ResizeGripActive,

    /// <summary>
    /// Color of TabItem in a TabBar.
    /// </summary>
    Tab,

    /// <summary>
    /// Color of TabItem in a TabBar when hovered.
    /// </summary>
    TabHovered,

    /// <summary>
    /// Color of TabItem in a TabBar when active.
    /// </summary>
    TabActive,

    /// <summary>
    /// Color of TabItem in a TabBar when unfocused.
    /// </summary>
    TabUnfocused,

    /// <summary>
    /// Color of TabItem in a TabBar when unfocused and active.
    /// </summary>
    TabUnfocusedActive,

    /// <summary>
    /// Color for plot lines.
    /// </summary>
    PlotLines,

    /// <summary>
    /// Color for plot lines when hovered.
    /// </summary>
    PlotLinesHovered,

    /// <summary>
    /// Color for plot histograms.
    /// </summary>
    PlotHistogram,

    /// <summary>
    /// Color for plot histograms when hovered.
    /// </summary>
    PlotHistogramHovered,

    /// <summary>
    /// Background color of table headers.
    /// </summary>
    TableHeaderBg,

    /// <summary>
    /// Color of strong borders in tables (prefer using Alpha=1.0 here).
    /// </summary>
    TableBorderStrong,

    /// <summary>
    /// Color of light borders in tables (prefer using Alpha=1.0 here).
    /// </summary>
    TableBorderLight,

    /// <summary>
    /// Background color of even rows in tables.
    /// </summary>
    TableRowBg,

    /// <summary>
    /// Background color of odd rows in tables.
    /// </summary>
    TableRowBgAlt,

    /// <summary>
    /// Background color for selected text.
    /// </summary>
    TextSelectedBg,

    /// <summary>
    /// Rectangle highlighting a drop target.
    /// </summary>
    DragDropTarget,

    /// <summary>
    /// Color for gamepad/keyboard navigation highlights.
    /// </summary>
    NavHighlight,

    /// <summary>
    /// Color for window highlights during CTRL+TAB window switching.
    /// </summary>
    NavWindowingHighlight,

    /// <summary>
    /// Background color for CTRL+TAB window switching with darkening/colorization.
    /// </summary>
    NavWindowingDimBg,

    /// <summary>
    /// Background color for modal windows with darkening/colorization.
    /// </summary>
    ModalWindowDimBg,
}

/// <summary>
/// Enumeration representing style variables in ImGui.
/// </summary>
public enum ImGuiStyleVar
{
    /// <summary>
    /// float - Global alpha applied to everything in ImGui.
    /// </summary>
    Alpha,

    /// <summary>
    /// float - Global alpha applied to disabled widgets.
    /// </summary>
    DisabledAlpha,

    /// <summary>
    /// Float2 - Padding within a window.
    /// </summary>
    WindowPadding,

    /// <summary>
    /// float - Radius of window corners rounding.
    /// </summary>
    WindowRounding,

    /// <summary>
    /// float - Thickness of the border around windows.
    /// </summary>
    WindowBorderSize,

    /// <summary>
    /// Float2 - Minimum size for windows.
    /// </summary>
    WindowMinSize,

    /// <summary>
    /// Float2 - Alignment of window title text.
    /// </summary>
    WindowTitleAlign,

    /// <summary>
    /// float - Radius of child window corners rounding.
    /// </summary>
    ChildRounding,

    /// <summary>
    /// float - Thickness of the border around child windows.
    /// </summary>
    ChildBorderSize,

    /// <summary>
    /// float - Radius of popup window corners rounding.
    /// </summary>
    PopupRounding,

    /// <summary>
    /// float - Thickness of the border around popup windows.
    /// </summary>
    PopupBorderSize,

    /// <summary>
    /// Float2 - Padding within a frame (e.g., button frame).
    /// </summary>
    FramePadding,

    /// <summary>
    /// float - Radius of frame corners rounding.
    /// </summary>
    FrameRounding,

    /// <summary>
    /// float - Thickness of the border around framed widgets (e.g., button frame).
    /// </summary>
    FrameBorderSize,

    /// <summary>
    /// Float2 - Spacing between widgets (e.g., button spacing).
    /// </summary>
    ItemSpacing,

    /// <summary>
    /// Float2 - Spacing between elements of a composed widget (e.g., within a menu).
    /// </summary>
    ItemInnerSpacing,

    /// <summary>
    /// float - Horizontal indentation when e.g., entering a tree node.
    /// </summary>
    IndentSpacing,

    /// <summary>
    /// Float2 - Padding within a table cell.
    /// </summary>
    CellPadding,

    /// <summary>
    /// float - Width/height of the vertical/horizontal scrollbars.
    /// </summary>
    ScrollbarSize,

    /// <summary>
    /// float - Radius of scrollbar corners rounding.
    /// </summary>
    ScrollbarRounding,

    /// <summary>
    /// float - Minimum width/height of the grab box when resizing.
    /// </summary>
    GrabMinSize,

    /// <summary>
    /// float - Radius of grab box corners rounding.
    /// </summary>
    GrabRounding,

    /// <summary>
    /// float - Radius of tab corners rounding.
    /// </summary>
    TabRounding,

    /// <summary>
    /// Float2 - Alignment of button text.
    /// </summary>
    ButtonTextAlign,

    /// <summary>
    /// Float2 - Alignment of selectable text.
    /// </summary>
    SelectableTextAlign,

    /// <summary>
    /// float - Thickness of border around separator.
    /// </summary>
    SeparatorTextBorderSize,

    /// <summary>
    /// Float2 - Alignment of separator text.
    /// </summary>
    SeparatorTextAlign,

    /// <summary>
    /// Float2 - Padding around separator text.
    /// </summary>
    SeparatorTextPadding,
}

/// <summary>
/// Flags used for specifying hover behavior in ImGui.
/// </summary>
public enum ImGuiHoveredFlags
{
    /// <summary>
    /// No hover flags are set.
    /// </summary>
    None                          = 0,
    
    /// <summary>
    /// Only applicable to IsWindowHovered(). Returns true if any children of the window are hovered.
    /// </summary>
    ChildWindows                  = 1 << 0,
    
    /// <summary>
    /// IsWindowHovered() only: Tests from the root window (topmost parent of the current hierarchy).
    /// </summary>
    RootWindow                    = 1 << 1,
    
    /// <summary>
    /// IsWindowHovered() only: Returns true if any window is hovered.
    /// </summary>
    AnyWindow                     = 1 << 2,
    
    /// <summary>
    /// IsWindowHovered() only: Do not consider popup hierarchy (do not treat popup emitter as the parent of the popup) when used with ChildWindows or RootWindow.
    /// </summary>
    NoPopupHierarchy              = 1 << 3,
    
    /// <summary>
    /// Return true even if a popup window is normally blocking access to this item or window.
    /// </summary>
    AllowWhenBlockedByPopup       = 1 << 5,
    
    /// <summary>
    /// Return true even if an active item is blocking access to this item or window. Useful for Drag and Drop patterns.
    /// </summary>
    AllowWhenBlockedByActiveItem  = 1 << 7,
    
    /// <summary>
    /// IsItemHovered() only: Return true even if the item uses AllowOverlap mode and is overlapped by another hoverable item.
    /// </summary>
    AllowWhenOverlappedByItem     = 1 << 8,
    
    /// <summary>
    /// IsItemHovered() only: Return true even if the position is obstructed or overlapped by another window.
    /// </summary>
    AllowWhenOverlappedByWindow   = 1 << 9,
    
    /// <summary>
    /// IsItemHovered() only: Return true even if the item is disabled.
    /// </summary>
    AllowWhenDisabled             = 1 << 10,
    
    /// <summary>
    /// IsItemHovered() only: Disable using gamepad/keyboard navigation state when active, always query the mouse.
    /// </summary>
    NoNavOverride                 = 1 << 11,
    
    /// <summary>
    /// IsItemHovered() only: Return true if any of the following conditions are met:
    /// 1. The item is overlapped by another hoverable item.
    /// 2. The item is blocked by an active item.
    /// 3. The item is blocked by a popup window.
    /// </summary>
    AllowWhenOverlapped           = AllowWhenOverlappedByItem | AllowWhenOverlappedByWindow,
    
    /// <summary>
    /// Only applicable to IsItemHovered(). Returns true if either the item is not blocked by a popup or an active item, or the item is not overlapped by another hoverable item.
    /// </summary>
    RectOnly                      = AllowWhenBlockedByPopup | AllowWhenBlockedByActiveItem | AllowWhenOverlapped,
    
    /// <summary>
    /// A combination of RootWindow and ChildWindows.
    /// </summary>
    RootAndChildWindows           = RootWindow | ChildWindows,
    
    // Tooltips mode
    // - Typically used in IsItemHovered() + SetTooltip() sequence.
    // - This is a shortcut to pull flags from 'style.HoverFlagsForTooltipMouse' or 'style.HoverFlagsForTooltipNav' where you can reconfigure desired behavior.
    // - For frequently actioned or hovered items providing a tooltip, you may want to use ImGuiHoveredFlags_ForTooltip (stationary + delay) so the tooltip doesn't show too often.
    // - For items whose main purpose is to be hovered, or items with low affordance, or in less consistent apps, prefer no delay or a shorter delay.
    
    /// <summary>
    /// Shortcut for standard flags when using IsItemHovered() + SetTooltip() sequence.
    /// </summary>
    ForTooltip                    = 1 << 12,
    
    // (Advanced) Mouse Hovering delays.
    // - Generally, you can use ImGuiHoveredFlags_ForTooltip to use application-standardized flags.
    // - Use those if you need specific overrides.
    
    /// <summary>
    /// Require the mouse to be stationary for style.HoverStationaryDelay (~0.15 sec) at least one time. After this, it can move on the same item or window. Using the stationary test tends to reduce the need for a long delay.
    /// </summary>
    Stationary                    = 1 << 13,
    
    /// <summary>
    /// IsItemHovered() only: Return true immediately (default). As this is the default, you generally ignore this.
    /// </summary>
    DelayNone                     = 1 << 14,
    
    /// <summary>
    /// IsItemHovered() only: Return true after style.HoverDelayShort elapsed (~0.15 sec) (shared between items) + requires the mouse to be stationary for style.HoverStationaryDelay (once per item).
    /// </summary>
    DelayShort                    = 1 << 15,
    
    /// <summary>
    /// IsItemHovered() only: Return true after style.HoverDelayNormal elapsed (~0.40 sec) (shared between items) + requires the mouse to be stationary for style.HoverStationaryDelay (once per item).
    /// </summary>
    DelayNormal                   = 1 << 16,
    
    /// <summary>
    /// IsItemHovered() only: Disable the shared delay system where moving from one item to the next keeps the previous timer for a short time (standard for tooltips with long delays).
    /// </summary>
    NoSharedDelay                 = 1 << 17,
}


/// <summary>
/// Enumeration representing mouse buttons in ImGui.
/// </summary>
public enum ImGuiMouseButton
{
    /// <summary>
    /// Left mouse button.
    /// </summary>
    Left = 0,
    
    /// <summary>
    /// Right mouse button.
    /// </summary>
    Right = 1,
    
    /// <summary>
    /// Middle mouse button.
    /// </summary>
    Middle = 2,
    
    /// <summary>
    /// The total number of mouse buttons.
    /// </summary>
    Count = 5
}


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
        return BeginChild(label, Float2.Zero, false, 0);
    }
    
    /// <summary>
    /// Plots a series of data points as lines using ImGui.
    /// </summary>
    /// <param name="label">The label for the plot.</param>
    /// <param name="values">An array of floating-point values representing the data points to be plotted.</param>
    [Unmanaged]
    public static void PlotLines(string label, float[] values)
    {
        PlotLines(label, values, 0, "", float.MaxValue, float.MaxValue, Float2.Zero, 4);
    }

    /// <summary>
    /// Creates a selectable item with the specified label using ImGui.
    /// </summary>
    /// <param name="label">The text label for the selectable item.</param>
    /// <returns><c>true</c> if the selectable item is clicked, <c>false</c> otherwise.</returns>
    [Unmanaged]
    public static bool Selectable(string label)
    {
        return Selectable(label, false, ImGuiSelectableFlags.None, Float2.Zero);
    }
    
    /// <summary>
    /// Creates a selectable item with the specified label using ImGui, allowing you to set its initial selection state.
    /// </summary>
    /// <param name="label">The text label for the selectable item.</param>
    /// <param name="selected">A boolean indicating whether the item is initially selected.</param>
    /// <returns><c>true</c> if the selectable item is clicked, <c>false</c> otherwise.</returns>
    [Unmanaged]
    public static bool Selectable(string label, bool selected)
    {
        return Selectable(label, selected, ImGuiSelectableFlags.None, Float2.Zero);
    }
    
    /// <summary>
    /// Begins a popup context associated with the last item, typically triggered by right-clicking the item.
    /// </summary>
    /// <param name="strId">An optional identifier for the popup context. If not specified, a unique identifier is generated.</param>
    /// <returns><c>true</c> if the popup context is opened, <c>false</c> otherwise.</returns>
    [Unmanaged]
    public static bool BeginPopupContextItem(string strId = null)
    {
        return BeginPopupContextItem(strId, ImGuiPopupFlags.MouseButtonDefault);
    }
    
    /// <summary>
    /// Begins a popup context window associated with the current ImGui window.
    /// </summary>
    /// <param name="strId">An optional identifier for the popup context. If not specified, a unique identifier is generated.</param>
    /// <returns><c>true</c> if the popup context is opened, <c>false</c> otherwise.</returns>
    [Unmanaged]
    public static bool BeginPopupContextWindow(string strId = null)
    {
        return BeginPopupContextWindow(strId, ImGuiPopupFlags.MouseButtonDefault);
    }
    
    /// <summary>
    /// Begins a popup context associated with a specific position or region, typically triggered by right-clicking that area.
    /// </summary>
    /// <param name="strId">An optional identifier for the popup context. If not specified, a unique identifier is generated.</param>
    /// <returns><c>true</c> if the popup context is opened, <c>false</c> otherwise.</returns>
    [Unmanaged]
    public static bool BeginPopupContextVoid(string strId = null)
    {
        return BeginPopupContextVoid(strId, ImGuiPopupFlags.MouseButtonDefault);
    }
    
    /// <summary>
    /// Opens a popup on item click, typically triggered by clicking on the item.
    /// </summary>
    /// <param name="strId">An optional identifier for the popup. If not specified, a unique identifier is generated.</param>
    [Unmanaged]
    public static void OpenPopupOnItemClick(string strId = null)
    {
        Internal_OpenPopupOnItemClick(strId, ImGuiPopupFlags.MouseButtonDefault);
    }
}
