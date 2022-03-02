#include "visuals.h"

#include "../../cheat/render/render.h"
#include "../../cheat/render/fonts/fonts.h"

#include "../../sdk/interfaces/variables.h"
#include "../../sdk/interfaces/c_base_player.h"

void visuals::render() {

	if (!interfaces::engine->is_in_game()) {

		return;
	}

	auto local_player = reinterpret_cast<c_base_player*>(interfaces::entity_list->get_client_entity(interfaces::engine->local_player()));

	for (int i = 1; i < 32; i++) {

		const auto ent = reinterpret_cast<c_base_player*>(interfaces::entity_list->get_client_entity(i));

		if (!ent) {
			continue;
		}

		math::vec3_t ent_pos;

		if (interfaces::debug_overlay->world_to_screen(ent->vec_origin(), ent_pos)) {

			if (ent->is_valid(local_player)) {

				// do rendering here

				// snapline
				int screen_width, screen_height;
				interfaces::engine->screen_size(screen_width, screen_height);

				render::line(ent_pos.x, ent_pos.y, screen_width / 2, screen_height);

				// get player info
				player_info_t player;
				interfaces::engine->get_player_info(i, player);

				// get the text size for text centering
				int text_h, text_w;
				interfaces::surface->get_text_size(fonts::tahoma, player.name, text_w, text_h);

				// render the players name
				render::text(player.name, ent_pos.x - (text_w / 2), ent_pos.y, fonts::tahoma, color(145, 219, 88, 255));
			}
		}
	}
}