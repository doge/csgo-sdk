#include <Windows.h>
#include <iostream>

#include "sdk/netvars/netvars.h"
#include "sdk/utilities/utils.h"

#include "sdk/interfaces/i_client.h"
#include "sdk/interfaces/i_entity_list.h"
#include "sdk/interfaces/c_base_entity.h"
#include "sdk/interfaces/variables.h"

#include "cheat/hooks/hooks.h"


void cheat(HMODULE instance) {

	// allocate the console
	AllocConsole();

	// create a file pointer
	FILE* file;
	freopen_s(&file, "CONOUT$", "w", stdout);

	{
		// setup interfaces and netvars
		interfaces::client = utils::get_interface<i_client>("VClient018", "client.dll");
		interfaces::client_mode = **reinterpret_cast<void***>((*reinterpret_cast<unsigned int**>(interfaces::client))[10] + 5);
		interfaces::entity_list = utils::get_interface<i_entity_list>("VClientEntityList003", "client.dll");
		interfaces::engine = utils::get_interface<i_engine_client>("VEngineClient014", "engine.dll");

		netvars::setup();
		hooks::setup();

		std::cout << "csgo-sdk";

		// main
		while (!GetAsyncKeyState(VK_END)) {
			
			// iterate over all the entities
			for (auto i = 0; i < 64; i++) {

				const auto ent = reinterpret_cast<c_base_entity*>(interfaces::entity_list->get_client_entity(i));

				// check for valid entity
				if (!ent) {
					continue;
				}

				// radar hack
				ent->spotted() = true;
			}

		}
	}

	hooks::destroy();

	// detach console and exit thread
	if (file) {
		fclose(file);
	}

	FreeConsole();
	FreeLibraryAndExitThread(instance, 0);
}

// entry point
BOOL WINAPI DllMain(HMODULE instance, DWORD reason, LPVOID reserved) {

	if (reason == DLL_PROCESS_ATTACH) {

		const HANDLE thread = CreateThread(
			nullptr,
			0,
			reinterpret_cast<LPTHREAD_START_ROUTINE>(cheat),
			instance,
			0,
			nullptr
		);

		if (thread) {
			CloseHandle(thread);
		}

	}

	return TRUE;
}