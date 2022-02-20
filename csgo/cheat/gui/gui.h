#pragma once

namespace gui {

	inline int selected_item = 0;
	inline int render_item = 0;

	inline int y_offset = 10;
	inline int element_count = 0;

	inline bool is_open = false;

	void render();

	void item(const char* name, bool& variable);
}
