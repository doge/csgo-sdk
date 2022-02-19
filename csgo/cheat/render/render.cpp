#include <corecrt_wstring.h>
#include <corecrt_wstdio.h>

#include "render.h"
#include "../../sdk/interfaces/variables.h"

void render::text(const char* text, int x, int y, int font, color c) {
	wchar_t to_render[32];
	swprintf(to_render, 32, L"%hs", text);

	interfaces::surface->draw_text_font(font);
	interfaces::surface->draw_text_pos(x, y);
	interfaces::surface->text_set_color(c.r, c.g, c.b, c.a);
	interfaces::surface->draw_render_text(to_render, wcslen(to_render));
}