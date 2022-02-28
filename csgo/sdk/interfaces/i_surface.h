#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/sp/src/public/vgui/ISurface.h#L121

enum e_font_flags
{
	fontflag_none,
	fontflag_italic = 0x001,
	fontflag_underline = 0x002,
	fontflag_strikeout = 0x004,
	fontflag_symbol = 0x008,
	fontflag_antialias = 0x010,
	fontflag_gaussianblur = 0x020,
	fontflag_rotary = 0x040,
	fontflag_dropshadow = 0x080,
	fontflag_additive = 0x100,
	fontflag_outline = 0x200,
	fontflag_custom = 0x400,		// custom generated font - never fall back to asian compatibility mode
	fontflag_bitmap = 0x800,		// compiled bitmap font - no fallbacks
};

class i_surface {

public:
	const char* draw_set_color(int r, int g, int b, int a) {
		using fn = const char* (__thiscall*)(i_surface*, int, int, int, int);
		return (*(fn**)this)[15](this, r, g, b, a);
	}

	const char* text_set_color(int r, int g, int b, int a) {
		using fn = const char* (__thiscall*)(i_surface*, int, int, int, int);
		return (*(fn**)this)[25](this, r, g, b, a);
	}

	const char* draw_filled_rect(int x, int y, int w, int h) {
		using fn = const char* (__thiscall*)(i_surface*, int, int, int, int);
		return (*(fn**)this)[16](this, x, y, w, h);
	}

	const char* draw_outlined_rect(int x, int y, int w, int h) {
		using fn = const char* (__thiscall*)(i_surface*, int, int, int, int);
		return (*(fn**)this)[18](this, x, y, w, h);
	}

	const char* draw_line(int x1, int y1, int x2, int y2) {
		using fn = const char* (__thiscall*)(i_surface*, int, int, int, int);
		return (*(fn**)this)[19](this, x1, y1, x2, y2);
	}

	const char* draw_poly_line(int* x, int* y, int point_count) {
		using fn = const char* (__thiscall*)(i_surface*, int*, int*, int);
		return (*(fn**)this)[20](this, x, y, point_count);
	}

	unsigned long create_font() {
		using fn = unsigned int (__thiscall*)(i_surface*);
		return (*(fn**)this)[71](this);
	}

	void draw_text_font(unsigned long font) {
		using fn = void (__thiscall*)(i_surface*, unsigned long);
		return (*(fn**)this)[23](this, font);
	}

	void set_font_glyph_set(unsigned long font, const char* font_name, int tall, int weight, int blur, int scanlines, int flags) {
		using fn = void (__thiscall*)(i_surface*, unsigned long, const char*, int, int, int, int, int, int, int);
		return (*(fn**)this)[72](this, font, font_name, tall, weight, blur, scanlines, flags, 0, 0);
	}

	void draw_text_pos(int x, int y) {
		using fn = void (__thiscall*)(i_surface*, int, int);
		return (*(fn**)this)[26](this, x, y);
	}

	void draw_render_text(const wchar_t* text, int textLen) {
		using fn = void (__thiscall*)(i_surface*, const wchar_t*, int, int);
		return (*(fn**)this)[28](this, text, textLen, 0);
	}

	int get_font_tall(unsigned long font) {
		using fn = int(__thiscall*)(i_surface*, unsigned long);
		return (*(fn**)this)[74](this, font);
	}

	void get_text_size(unsigned long font, const wchar_t* text, int& w, int& h) {
		using fn = void (__thiscall*)(i_surface*, unsigned long, const wchar_t*, int&, int&);
		return (*(fn**)this)[79](this, font, text, w, h);
	}
};