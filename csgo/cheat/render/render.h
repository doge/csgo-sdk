#pragma once

struct color {
	int r, g, b, a;
};

namespace render {
	void text(const char* text, int x, int y, int font, color c);
}