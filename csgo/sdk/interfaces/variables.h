#pragma once

#include "i_entity_list.h"
#include "i_engine_client.h"
#include "i_client.h"
#include "i_panel.h"
#include "i_surface.h"
#include "iv_debug_overlay.h"

namespace interfaces {

	inline i_client* client;
	inline void* client_mode;
	inline i_entity_list* entity_list;
	inline i_engine_client* engine;
	inline i_panel* vgui_panel;
	inline i_surface* surface;
	inline iv_debug_overlay* debug_overlay;
}