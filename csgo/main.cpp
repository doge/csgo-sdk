#include <Windows.h>
#include <iostream>

#include "sdk/netvars/netvars.h"
#include "sdk/utilities/utils.h"

#include "sdk/interfaces/i_client.h"
#include "sdk/interfaces/i_entity_list.h"
#include "sdk/interfaces/c_base_entity.h"
#include "sdk/interfaces/variables.h"
#include "sdk/interfaces/i_client_mode.h"

#include "cheat/gui/gui.h"
#include "cheat/gui/settings.h"

#include "cheat/hooks/hooks.h"
#include "cheat/input/input.h"

#include "cheat/render/fonts/fonts.h"

void cheat(HMODULE instance) {

	// allocate the console
	AllocConsole();

	// create a file pointer
	FILE* file;
	freopen_s(&file, "CONOUT$", "w", stdout);

	{
		// setup interfaces
		interfaces::client = utils::get_interface<i_client>("VClient018", "client.dll");
		interfaces::client_mode = **reinterpret_cast<i_client_mode***>((*reinterpret_cast<unsigned int**>(interfaces::client))[10] + 5);
		interfaces::entity_list = utils::get_interface<i_entity_list>("VClientEntityList003", "client.dll");
		interfaces::engine = utils::get_interface<i_engine_client>("VEngineClient014", "engine.dll");
		interfaces::surface = utils::get_interface<i_surface>("VGUI_Surface031", "vguimatsurface.dll");
		interfaces::vgui_panel = utils::get_interface<i_panel>("VGUI_Panel009", "vgui2.dll");
		interfaces::debug_overlay = utils::get_interface<iv_debug_overlay>("VDebugOverlay004", "engine.dll");

		// netvars, fonts and hooks
		netvars::setup();
		fonts::setup();
		hooks::setup();

		std::cout << "csgo-sdk\n";

		interfaces::engine->client_cmd_unrestricted("clear");
		interfaces::engine->client_cmd_unrestricted("echo csgo-sdk");

		int screen_w, screen_h;
		interfaces::engine->screen_size(screen_w, screen_h);

		std::cout << screen_w << "x" << screen_h << "\n";

		// main
		while (!GetAsyncKeyState(VK_END)) {

			input::handle();

			// iterate over all the entities
			for (auto i = 0; i < 64; i++) {

				const auto ent = reinterpret_cast<c_base_entity*>(interfaces::entity_list->get_client_entity(i));

				// check for valid entity
				if (!ent) {

					continue;
				}

				// radar hack
				if (gui::settings::radar) {

					ent->spotted() = true;
				}
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