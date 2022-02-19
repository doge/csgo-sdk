#pragma once

#include <unordered_map>
#include "../utilities/fnv.h"
#include "../valve/classes/recv_prop.h"

#define netvar_fn(func_name, netvar, type) type& func_name() \
{ \
	static auto offset = netvars::data[fnv::hash_const(netvar)]; \
	return *reinterpret_cast<type*>(uint32_t(this) + offset); \
}

namespace netvars {
	// dump netvars
	void setup();

	// recursive dump
	void dump(const char* base_class, recv_table* table, uint32_t offset = 0);
	
	// [ fnv hash of the netvar, offset ]
	inline std::unordered_map<uint32_t, uint32_t> data;
};