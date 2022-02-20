#pragma once

class i_panel {
public:
	const char* get_class_name(unsigned int panel) {
		using fn = const char* (__thiscall*)(i_panel*, unsigned int);
		return (*(fn**)this)[36](this, panel);
	}

	const char* keyboard_input_enabled(unsigned int panel, bool state) {
		using fn = const char* (__thiscall*)(i_panel*, unsigned int, bool);
		return (*(fn**)this)[31](this, panel, state);
	}

	const char* mouse_input_enabled(unsigned int panel, bool state) {
		using fn = const char* (__thiscall*)(i_panel*, unsigned int, bool);
		return (*(fn**)this)[32](this, panel, state);
	}
};