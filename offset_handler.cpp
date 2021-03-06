#include <offset_handler.h>
//
// AMX Mod X, based on AMX Mod by Aleksander Naszko ("OLO").
// Copyright (C) The AMX Mod X Development Team.
//
// This software is licensed under the GNU General Public License, version 3 or higher.
// Additional exceptions apply. For full license details, see LICENSE.txt or visit:
//     https://alliedmods.net/amxmodx-license

//
// Okapi Module
//

#include <amxxmodule.h>
#include "globals.h"

void OffsetHandler::search_pev()
{
	edict_t* edict = INDEXENT(0);
	entvars_t* entvars = &edict->v;

	char* private_c = (char*)edict->pvPrivateData;

	for (int i = 0; i < 0xFFF; i++)
	{
		long val = *((long*)(private_c + i));

		if (val == (long)entvars)
		{
			this->PEV = i;

			return;
		}
	}

	printf("PEV value was not found. This should not happen\n");

	this->PEV = 0;
}

void OffsetHandler::search_virtual_table()
{
	edict_t* edict = INDEXENT(0);
	entvars_t* entvars = &edict->v;

	this->EntityVirtualTable = search_virtual_table(edict->pvPrivateData);
}

int OffsetHandler::search_virtual_table(void* address)
{
	char* c_address = (char*)address;

	for (int i = 0; i < 0xFFF; ++i)
	{
		long address = *((long*)(c_address + i));

		if (G_GameLibraries.Engine->contains_address(address) || G_GameLibraries.Mod->contains_address(address))
		{
			void** address_ptr = (void**)address;

			int sum = 0;

			for (int j = 0; j <= 10; ++j)
			{
				void* address_inside = address_ptr[j];

				sum += G_GameLibraries.Engine->contains_address(address) | G_GameLibraries.Mod->contains_address(address);
			}

			if (sum > 5)
			{
				return i;
			}
		}
	}

	printf("Virtual table was not found. This should not happen\n");

	return 0;
}
