#pragma once
#include "stdafx.h"


struct VECTOR3
{
public:
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;

	VECTOR3() = default;
	VECTOR3(float _x, float _y, float _z)
		:x(_x), y(_y), z(_z)
	{}

	void Normalize()
	{
		(*this) = Normalized();
	}

	VECTOR3 Normalized() const
	{
		float mangnitude = Magnitude();
		if (mangnitude <= 0.f)
			return (*this);

		float invMagnitude = 1.f / mangnitude;

		return VECTOR3(x * invMagnitude, y * invMagnitude, z * invMagnitude);
	}

	float Magnitude() const
	{
		return std::sqrtf(std::powf(x, 2.f) + std::powf(y, 2.f) + std::powf(z, 2.f));
	}
};