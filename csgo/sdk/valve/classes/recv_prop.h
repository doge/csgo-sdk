#pragma once

#include <cstdint>

// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/sp/src/public/dt_recv.h#L87

enum class send_prop_type : int
{
	integer = 0,
	floating_point,
	vector,
	vector2d,
	string,
	array,
	datatable,
	int64,
	sendproptypemax
};

struct data_variant
{
	union
	{
		float	m_float;
		long	m_int;
		char*	m_string;
		void*	m_data;
		float	m_vector[3];
		int64_t m_int64;
	};

	send_prop_type type;
};

struct recv_prop;
struct recv_table
{
	recv_prop*	props;
	int			props_count;
	void*		decoder;
	char*		table_name;
	bool		initialized;
	bool		in_main_list;
};

struct recv_prop
{
	char* name;
	send_prop_type type;
	int flags;
	int buffer_size;
	bool inside_array;
	const void* extra_data_ptr;
	recv_prop* prop_array_ptr;
	void* array_length_proxy;
	void* proxy;
	void* data_table_proxy;
	recv_table* data_table_ptr;
	int offset;
	int element_stride;
	int elements;
	const char* parent_array_prop_name;
};