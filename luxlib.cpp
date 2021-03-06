#include "pch.h"

luxZ::luxZ()
{
	this->lux = luaL_newstate();
	luaL_openlibs(this->lux);
}

luxZ::luxZ(lua_State* L)
{
	this->lux = L;
}

luxZ::luxZ(int EMPTY)
{
	if (EMPTY)
		this->lux = nullptr;
}

luxZ::~luxZ()
{

}

void luxZ::ReassignEnvironment(lua_State* L)
{
	this->lux = L;
}

void luxZ::CloseEnvironment()
{
	lua_close(this->lux);
}

int luxZ::RunString(const char* str)
{
	if (luaL_loadstring(this->lux, str) == 0) {
		lua_call(this->lux, 0, 0);

		return 1;
	}

	return NULL;
}

void luxZ::Register(const char* name, int(func)(lua_State* L))
{
	return lua_register(this->lux, name, (lua_CFunction)func);
}

int luxZ::LoadFile(const char* file)
{
	return luaL_loadfile(this->lux, file);
}

void luxZ::OpenLib(const char* name, const luaL_Reg* t, int up)
{
	return luaL_openlib(this->lux, name, t, up);
}

const char* luxZ::PushFString(const char* fmt, char* buff)
{
	return lua_pushfstring(this->lux, fmt, buff);
}

void luxZ::PushString(const char* str)
{
	return lua_pushstring(this->lux, str);
}

void luxZ::PushLiteral(const char* str)
{
	return lua_pushlstring(this->lux, str, strlen(str));
}

void luxZ::PushValue(int index)
{
	return lua_pushvalue(this->lux, index);
}

void luxZ::PushNumber(int num)
{
	return lua_pushnumber(this->lux, num);
}

void luxZ::Pop(int index)
{
	return lua_pop(this->lux, index);
}

int luxZ::Pcall(int nargs, int nresults, int errfunc)
{
	return lua_pcall(this->lux, nargs, nresults, errfunc);
}

void luxZ::Rawset(int index)
{
	return lua_rawset(this->lux, index);
}

const char* luxZ::CheckString(int index)
{
	return luaL_checkstring(this->lux, index);
}

int luxZ::CheckInt(int index)
{
	return luaL_checkint(this->lux, index);
}

void luxZ::CheckType(int index, int type)
{
	return luaL_checktype(this->lux, index, type);
}

int luxZ::NewMetatable(const char* name)
{
	return luaL_newmetatable(this->lux, name);
}

int luxZ::SetMetatable(int index)
{
	return lua_setmetatable(this->lux, index);
}

void luxZ::GetMetatable(const char* name)
{
	return luaL_getmetatable(this->lux, name);
}

void* luxZ::ToUserdata(int index)
{
	return lua_touserdata(this->lux, index);
}

void* luxZ::NewUserdata(size_t size)
{
	return lua_newuserdata(this->lux, size);
}

void* luxZ::CheckUserdata(int index, const char* name)
{
	return luaL_checkudata(this->lux, index, name);
}

int luxZ::TypeError(int index, const char* name)
{
	return luaL_typerror(this->lux, index, name);
}

const char* luxZ::ToString(int index)
{
	return lua_tostring(this->lux, index);
}