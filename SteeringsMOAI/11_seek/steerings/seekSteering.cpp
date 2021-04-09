
#include <stdafx.h>
#include "../character.h"
#include "seekSteering.h"


SeekSteering::SeekSteering(Character* _character, USVec2D& _target, float _destRadius) :
	character(_character),
	target(_target),
	destRadius(_destRadius)
{
}

USVec2D SeekSteering::getSteering()
{
	float dist = target.Dist(character->GetLoc());

	USVec2D desiredVelocity = target - character->GetLoc();
	desiredVelocity.NormSafe();

	if (dist > destRadius)
	{
		desiredVelocity *= character->GetMaxVelocity();
	}
	else 
	{ 
		desiredVelocity = USVec2D(0.f, 0.f);
	}

	USVec2D acceleration = desiredVelocity - character->GetLinearVelocity();
	acceleration.NormSafe();
	acceleration *= character->GetMaxAcceleration();
	return acceleration;
}

void SeekSteering::DrawDebug()
{
	if (character)
	{
		MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();
		gfxDevice.SetPenColor(1.0f, 0.0f, 0.0f, 0.5f);
		MOAIDraw::DrawLine(character->GetLoc().mX, character->GetLoc().mY, target.mX, target.mY);
		gfxDevice.SetPenColor(0.2f, 0.2f, 1.0f, 1.0f);
		MOAIDraw::DrawLine(character->GetLoc().mX, character->GetLoc().mY, character->GetLoc().mX + getSteering().mX, character->GetLoc().mY + getSteering().mY);
	}
}
