#include <iostream>

const float Pi = 3.14f;

float GetArea(float Radius)
{
	if (Radius <= 0)
	{
		std::cout << "GetArea: INVALID INPUT" << std::endl;
		return 0;
	}
	return Pi * Radius * Radius;
}

float GetCircumference(float Radius)
{
	if (Radius <= 0)
	{
		std::cout << "GetCircumference: INVALID INPUT" << std::endl;
		return 0;
	}
	return Pi * 2 * Radius;
}