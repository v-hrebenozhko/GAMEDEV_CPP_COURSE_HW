#pragma once
#include <cstdio>
#include <iostream>
#include <cmath>

class vector2d
{
private:
	static int InstancesCount;
	float x = 0.0f;
	float y = 0.0f;
public:
	vector2d();
	~vector2d();
	vector2d(float x, float y);
	static const int GetInstanses();

	vector2d operator=(const vector2d& Other);
	vector2d operator+(const vector2d& Other);
	vector2d operator-(const vector2d& Other);

	void operator*=(float Scalar);
	float operator()();
	float& operator[](std::size_t idx);

	friend vector2d operator+(const vector2d& LeftVector, const vector2d& RightVector);
	friend vector2d operator-(const vector2d& LeftVector, const vector2d& RightVector);
	friend std::ostream& operator<<(std::ostream& out, vector2d Vector);
	friend void operator>>(std::istream& in, vector2d& Vector);
};

