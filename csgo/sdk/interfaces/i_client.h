#pragma once

#include "../utilities/utils.h"
#include "../valve/classes/client_class.h"

// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/mp/src/public/cdll_int.h#L580

class i_client
{
public:
	// 0x8
	client_class* get_all_classes()
	{
		using func = client_class * (__thiscall*)(i_client*);
		return (*(func**)this)[ 8 ](this);
	}
};

inline i_client* g_client;