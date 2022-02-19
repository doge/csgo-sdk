#pragma once

class i_panel {
public:
	const char* get_class_name(unsigned int panel)
	{
		using fn = const char* (__thiscall*)(i_panel*, unsigned int);
		return (*(fn**)this)[36](this, panel);
	}
};