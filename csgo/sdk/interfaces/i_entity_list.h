#pragma once

// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/icliententitylist.h

class i_client_networkable;
class i_client_unknown;
class i_client_entity;
class c_base_handle;

class i_entity_list {
public:

	// Get IClientNetworkable interface for specified entity
	virtual i_client_networkable* get_client_networkable(int entnum) = 0;
	virtual i_client_networkable* get_client_networkable_from_handle(c_base_handle hEnt) = 0;
	virtual i_client_unknown* get_client_unknown_from_handle(c_base_handle hEnt) = 0;

	// NOTE: This function is only a convenience wrapper.
	// It returns GetClientNetworkable( entnum )->GetIClientEntity().
	virtual i_client_entity* get_client_entity(int entnum) = 0;
	virtual i_client_entity* get_client_entity_from_handle(c_base_handle hEnt) = 0;

	// Returns number of entities currently in use
	virtual int					number_of_entities(bool bIncludeNonNetworkable) = 0;

	// Returns highest index actually used
	virtual int					highest_entity_index(void) = 0;

	// Sizes entity list to specified size
	virtual void				set_max_entities(int maxents) = 0;
	virtual int					get_max_entities() = 0;
};