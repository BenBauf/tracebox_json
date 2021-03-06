/**
 * Tracebox -- A middlebox detection tool
 *
 *  Copyright 2013-2015 by its authors.
 *  Some rights reserved. See LICENSE, AUTHORS.
 */

#ifndef __LUA_UDP_H_
#define __LUA_UDP_H_

#include "lua_crafter.hpp"

struct l_udp_ref : public l_layer_ref<Crafter::UDP> {
	l_udp_ref (Crafter::UDP *i, lua_State *l) : l_layer_ref<Crafter::UDP>(i, l) {}
	l_udp_ref(l_udp_ref *r, lua_State *l) : l_layer_ref<Crafter::UDP>(r, l) {}
	template<class T>
	l_udp_ref(l_ref<T> *r, Crafter::UDP *i, lua_State *l)
		: l_layer_ref<Crafter::UDP>(r, i, l) {}
	~l_udp_ref() {}

	static int l_UDP(lua_State *l);
	static void register_members(lua_State *l);
	static void register_globals(lua_State *l);
};

#endif
