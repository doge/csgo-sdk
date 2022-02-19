#pragma once

#include <Windows.h>

namespace utils {

	template <typename T>
	T* get_interface(const char* version_string, const char* module_handle) {

		const HMODULE handle = GetModuleHandle(module_handle);

		// check if we have a valid handle
		if (!handle) {
			return nullptr;
		}

		// get address of the createinterface function
		const auto function_address = GetProcAddress(handle, "CreateInterface");

		// create a template for createinterface
		// const char* p_name, int* p_return_code
		using function = T * (*)(const char*, int*);

		// cast the address of the function to our function pointer 
		const auto create_interface = reinterpret_cast<function>(function_address);

		// we have the functions address now so let's call it
		return create_interface(version_string, nullptr);
	};

}
