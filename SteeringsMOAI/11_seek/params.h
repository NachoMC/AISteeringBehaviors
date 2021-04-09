#ifndef __PARAMS_H__
#define __PARAMS_H__

struct Params
{
	float max_velocity;
	float max_acceleration;

	USVec2D targetPosition;
	float dest_radius;

};

bool ReadParams(const char* filename, Params& params);

#endif