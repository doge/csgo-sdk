#pragma once

class i_surface
{
public:
	const char* draw_set_color(int r, int g, int b, int a)
	{
		using fn = const char* (__thiscall*)(i_surface*, int, int, int, int);
		return (*(fn**)this)[15](this, r, g, b, a);
	}

	const char* draw_filled_rect(int x, int y, int w, int h)
	{
		using fn = const char* (__thiscall*)(i_surface*, int, int, int, int);
		return (*(fn**)this)[16](this, x, y, w, h);
	}
};