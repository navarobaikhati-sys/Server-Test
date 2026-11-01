#pragma once

namespace DesignSystem {

// ============================================================
// Color Palette - Modern Minecraft Aesthetic
// ============================================================

// Deep charcoal / near-black backgrounds
inline constexpr char BACKGROUND_DEFAULT[] = "#0F1115";
inline constexpr char BACKGROUND_ELEVATED[] = "#1A1D23";
inline constexpr char BACKGROUND_CARD[] = "#24272E";
inline constexpr char BACKGROUND_SECTION[] = "#2A2D35";

// Surfaces and borders
inline constexpr char SURFACE[] = "#2C303B";
inline constexpr char BORDER[] = "#3E4451";
inline constexpr char BORDER_LIGHT[] = "#4A4F5A";
inline constexpr char BORDER_MEDIUM[] = "#5A606D";

// Accent colors - Emerald green
inline constexpr char ACCENT_PRIMARY[] = "#3DDC84";
inline constexpr char ACCENT_SECONDARY[] = "#2ECC71";
inline constexpr char ACCENT_SOFT[] = "#6BCB96";

// Sandstone/beige secondary accents
inline constexpr char ACCENT_WARM[] = "#F7DCBA";
inline constexpr char ACCENT_WARM_SUBTLE[] = "#EFE7D0";

// Text colors
inline constexpr char TEXT_PRIMARY[] = "#FAFAFA";
inline constexpr char TEXT_SECONDARY[] = "#8D99A5";
inline constexpr char TEXT_MUTED[] = "#6E7B8B";
inline constexpr char TEXT_ON_ACCENT[] = "#0F1115";

// Status colors
inline constexpr char STATUS_OK[] = "#3DDC84";
inline constexpr char STATUS_WARNING[] = "#F7DCBA";
inline constexpr char STATUS_ERROR[] = "#FF5F57";

// ============================================================
// Spacing and Layout Tokens
// ============================================================

inline constexpr int SPACE_XS = 4;
inline constexpr int Space_S = 8;
inline constexpr int Space_M = 16;
inline constexpr int Space_L = 24;
inline constexpr int Space_XL = 32;
inline constexpr int Space_XXL = 48;

// ============================================================
// Border Radius and Shadows
// ============================================================

inline constexpr int RADIUS_SMALL = 6;
inline constexpr int RADIUS_MEDIUM = 8;
inline constexpr int RADIUS_LARGE = 12;

inline constexpr char SHADOW_SMALL[] = "0 2px 4px rgba(0,0,0,0.3)";
inline constexpr char SHADOW_MEDIUM[] = "0 4px 12px rgba(0,0,0,0.4)";
inline constexpr char SHADOW_LARGE[] = "0 8px 24px rgba(0,0,0,0.5)";

// ============================================================
// Typography Tokens
// ============================================================

inline constexpr char FONT_FAMILY[] = "Segoe UI, system-ui, -apple-system, sans-serif";
inline constexpr char FONT_MONO[] = "JetBrains Mono, monospace";

inline constexpr int FONT_SIZE_CAPTION = 11;
inline constexpr int FONT_SIZE_BODY = 13;
inline constexpr int FONT_SIZE_SMALL = 11;
inline constexpr int FONT_SIZE_LARGE = 18;
inline constexpr int FONT_SIZE_HEADER = 24;

inline constexpr int FONT_WEIGHT_REGULAR = 400;
inline constexpr int FONT_WEIGHT_MEDIUM = 500;
inline constexpr int FONT_WEIGHT_BOLD = 700;

} // namespace DesignSystem