#include <stdafx.h>
#include "character.h"
#include <tinyxml.h>
#include <params.h>

#include "steerings/seekSteering.h"


Character::Character() : 
	mLinearVelocity(0.0f, 0.0f)
{
	RTTI_BEGIN
		RTTI_EXTEND (MOAIEntity2D)
	RTTI_END
}

Character::~Character()
{

}

void Character::OnStart()
{
	ReadParams("params.xml", mParams);

	maxVelocity = mParams.max_velocity;
	maxAcceleration = mParams.max_acceleration;

	seekSteering = new SeekSteering(this, mParams.targetPosition, mParams.dest_radius);
}

void Character::OnStop()
{
	delete seekSteering;
}

void Character::OnUpdate(float step)
{
	USVec2D velocity = mLinearVelocity + seekSteering->getSteering() * step;
	SetLinearVelocity(velocity.mX, velocity.mY);
	SetLoc(GetLoc() + (mLinearVelocity * step));
}

void Character::DrawDebug()
{
	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();
	gfxDevice.SetPenColor(1.0f, 1.0f, 1.0f, 0.5f);
	MOAIDraw::DrawPoint(0.0f, 0.0f);

	seekSteering->DrawDebug();
}

void Character::SetLinearVelocity(float x, float y)
{
	mLinearVelocity.mX = x;
	mLinearVelocity.mY = y;
	if (mLinearVelocity.Length() > GetMaxVelocity())
	{
		mLinearVelocity.NormSafe();
		mLinearVelocity *= GetMaxVelocity();
	}
}


// Lua configuration

void Character::RegisterLuaFuncs(MOAILuaState& state)
{
	MOAIEntity2D::RegisterLuaFuncs(state);
	
	luaL_Reg regTable [] = {
		{ "setLinearVel",			_setLinearVel},
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

int Character::_setLinearVel(lua_State* L)
{
	MOAI_LUA_SETUP(Character, "U")
	
	float pX = state.GetValue<float>(2, 0.0f);
	float pY = state.GetValue<float>(3, 0.0f);
	self->SetLinearVelocity(pX, pY);
	return 0;	
}
