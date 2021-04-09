
#pragma once

class Character;


class SeekSteering
{

protected:
	Character* character;
	USVec2D target;
	float destRadius;

public:
	SeekSteering(Character* _character, USVec2D& _target, float _destRadius);

	USVec2D getSteering();

	void DrawDebug();

};
