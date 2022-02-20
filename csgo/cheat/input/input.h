#pragma once

namespace input {

	inline bool click_key_states[256];
	inline bool hold_key_states[256];

	void update();
	void handle();

	bool click(int keycode);
	bool is_holding(int keycode);
}