#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <moaicore/MOAIEntity2D.h>
#include <params.h>

class SeekSteering;


class Character: public MOAIEntity2D
{
public:
    DECL_LUA_FACTORY(Character)
protected:
	virtual void OnStart();
	virtual void OnStop();
	virtual void OnUpdate(float step);
public:
	virtual void DrawDebug();

	Character();
	~Character();

	USVec2D GetLinearVelocity() const { return mLinearVelocity; }
	void SetLinearVelocity(float x, float y);
	float GetMaxVelocity() const { return maxVelocity; }
	float GetMaxAcceleration() const { return maxAcceleration; }

private:
	USVec2D mLinearVelocity;
	float maxVelocity;
	float maxAcceleration;
	
	Params mParams;

	SeekSteering* seekSteering;


// Lua configuration
public:
	virtual void RegisterLuaFuncs(MOAILuaState& state);

private:
	static int _setLinearVel(lua_State* L);
};

#endif