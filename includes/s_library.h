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

#ifndef S_LIBRARY_H
#define S_LIBRARY_H

#include <MemoryUtils.h>

struct s_library
{
	void* handle;
	void* address;
	int length;
};

s_library* create_library(void* address);
const char* get_address_symbol(void* address);
void* find_function(s_library* library, const char* functionName);
void create_addons_libraries();

#endif // S_LIBRARY_H

