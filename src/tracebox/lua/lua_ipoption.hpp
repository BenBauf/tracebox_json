/**
 * Tracebox -- A middlebox detection tool
 *
 *  Copyright 2013-2015 by its authors.
 *  Some rights reserved. See LICENSE, AUTHORS.
 */

#ifndef __LUA_IPOption_H_
#define __LUA_IPOption_H_

#include "lua_crafter.hpp"

struct l_ipoption_ref : public l_layer_ref<Crafter::IPOptionLayer> {
	l_ipoption_ref (Crafter::IPOptionLayer *i, lua_State *l)
		: l_layer_ref<Crafter::IPOptionLayer>(i, l) {}
	l_ipoption_ref(l_ipoption_ref *r, lua_State *l)
		: l_layer_ref<Crafter::IPOptionLayer>(r, l) {}
	template<class T>
	l_ipoption_ref(l_ref<T> *r, Crafter::IPOptionLayer *i, lua_State *l)
		: l_layer_ref<Crafter::IPOptionLayer>(r, i, l) {}
	~l_ipoption_ref() {}

	template<class C>
	static C* new_option_ref(lua_State *l)
	{
		C *o = new C();
		new l_ipoption_ref(o, l);
		return o;
	};
	static int l_IP_NOP(lua_State *l);
	static int l_IP_EOL(lua_State *l);
	static int l_IP_SSRR(lua_State *l);
	static int l_IP_LSRR(lua_State *l);
	static int l_IP_RR(lua_State *l);
	static int l_IP_Traceroute(lua_State *l);
	static void register_globals(lua_State *l);
	static void register_members(lua_State *l);
};

#endif
