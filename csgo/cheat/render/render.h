#pragma once

struct color {
	int r, g, b, a;
};

namespace render {

	void text(const char* text, int x, int y, int font, color c = color(255, 255, 255, 255));
	
	void filled_rect(int x, int y, int w, int h, color c);

	void outlined_rect(int x, int y, int w, int h, color c);

	void line(int x1, int y1, int x2, int y2, color c);

	void poly_line(int* x, int* y, int poly_count, color c);
}