#pragma once

#include "recv_prop.h"

class client_class
{
public:
	void* create_client_class;
	void* create_event;
	char* network_name;
	recv_table* recv_table;
	client_class* next;
	int class_id;
	const char* map_class_name;
};
