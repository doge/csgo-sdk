#pragma once

#include "i_entity_list.h"
#include "i_engine_client.h"
#include "i_client.h"

namespace interfaces {
	inline i_client* client;
	inline void* client_mode;
	inline i_entity_list* entity_list;
	inline i_engine_client* engine;
}