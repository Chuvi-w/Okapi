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

#include <function.h>

template <typename T>
T max_val();

template <>
int max_val<int>()
{
	return 0;
}

template <typename T>
T create_empty();

template <>
bool create_empty<bool>();

template <>
int create_empty<int>();

template <>
Function* create_empty<Function*>()
{
	return NULL;
}

template <typename T>
bool check_empty(T& a);

template <>
bool check_empty(Command*& a);

template <>
bool check_empty<bool>(bool& a);

template <>
bool check_empty<float>(float& a);

template <>
bool check_empty<int>(int& a);

template <typename T>
T create_empty()
{
	return T();
}

template <>
bool create_empty<bool>()
{
	return false;
}

template <>
int create_empty<int>()
{
	return 0;
}

template <>
Command* create_empty()
{
	return NULL;
}

template <typename T>
bool check_empty(T& a)
{
	return a.is_empty();
}

template <>
bool check_empty(Command*& a)
{
	return a == NULL;
}

template <>
bool check_empty(Function*& a)
{
	return a == NULL;
}

template <>
bool check_empty<bool>(bool& a)
{
	return a == false;
}

template <>
bool check_empty<float>(float& a)
{
	return a == 0.0f;
}

template <>
bool check_empty<int>(int& a)
{
	return a == 0;
}