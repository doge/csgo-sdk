#include <corecrt_wstring.h>
#include <corecrt_wstdio.h>

#include "render.h"

#include "../../sdk/interfaces/variables.h"

void render::text(const char* text, int x, int y, int font, color c) {

	wchar_t data[32];
	swprintf(data, 32, L"%hs", text);

	interfaces::surface->draw_text_font(font);
	interfaces::surface->draw_text_pos(x, y);
	interfaces::surface->text_set_color(c.r, c.g, c.b, c.a);
	interfaces::surface->draw_render_text(data, wcslen(data));
}

void render::filled_rect(int x, int y, int w, int h, color c) {

	interfaces::surface->draw_set_color(c.r, c.g, c.b, c.a);
	interfaces::surface->draw_filled_rect(x, y, w, h);
}

void render::outlined_rect(int x, int y, int w, int h, color c) {

	interfaces::surface->draw_set_color(c.r, c.g, c.b, c.a);
	interfaces::surface->draw_outlined_rect(x, y, w, h);
}

void render::line(int x1, int y1, int x2, int y2, color c) {

	interfaces::surface->draw_set_color(c.r, c.g, c.b, c.a);
	interfaces::surface->draw_line(x1, y1, x2, y2);
}

void render::poly_line(int* x, int* y, int poly_count, color c) {

	interfaces::surface->draw_set_color(c.r, c.g, c.b, c.a);
	interfaces::surface->draw_poly_line(x, y, poly_count);
}