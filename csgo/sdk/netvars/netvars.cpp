#include "netvars.h"
#include "../utilities/utils.h"

#include "../interfaces/i_client.h"
#include "../interfaces/variables.h"


#include <format>
#include <ctype.h>

void netvars::setup() {
	
	// loop through the linked list
	for (auto client_class = interfaces::client->get_all_classes(); client_class; client_class = client_class->next) {

		// valid table?
		if (client_class->recv_table) {
			dump(client_class->network_name, client_class->recv_table);
		}
	}
}

void netvars::dump(const char* base_class, recv_table* table, uint32_t offset) {

	for (auto i = 0; i < table->props_count; i++) {

		const auto prop = &table->props[i];

		// check for a valid prop or if the first character in 
		// the name of the prop is a digit
		if (!prop || isdigit(prop->name[0])) {
			continue;
		}

		// make sure we aren't storing a base class
		if (fnv::hash(prop->name) == fnv::hash_const("baseclass")) {
			continue;
		}

		// dump member props
		if (prop->type == send_prop_type::datatable && prop->data_table_ptr && 
			prop->data_table_ptr->table_name[0] == 'D') {

			dump(base_class, prop->data_table_ptr, offset + prop->offset);
		}

		const auto netvar_name = std::format("{}->{}", base_class, prop->name);
		data[fnv::hash(netvar_name.c_str())] = offset + prop->offset;
	}
}