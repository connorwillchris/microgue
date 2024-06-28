#include <lua.h>
#include <lauxlib.h>

static int LUA_microgue_multiply(lua_State* L) {
    int a = luaL_checkinteger(L, 1);
    int b = luaL_checkinteger(L, 2);

    lua_Integer c = a*b;
    lua_pushinteger(L, c);
    return 1;
}

const struct luaL_Reg MyMicrogueLib[] = {
    { "mul", LUA_microgue_multiply, },
};

