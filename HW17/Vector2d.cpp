#include "Vector2d.h"

int vector2d::InstancesCount = 0;

vector2d::vector2d() { InstancesCount++; };
vector2d::~vector2d() { InstancesCount--; };

vector2d::vector2d(float x, float y)
{
	this->x = x;
	this->y = y;
	InstancesCount++;
}

const int vector2d::GetInstanses() { return InstancesCount; }
vector2d vector2d::operator=(const vector2d& Other) { return Other; }
vector2d vector2d::operator+(const vector2d& Other) { return { this->x + Other.x, this->y + Other.y }; }
vector2d vector2d::operator-(const vector2d& Other) { return { this->x - Other.x, this->y - Other.y }; }
void vector2d::operator*=(float Scalar) { this->x *= Scalar; this->y *= Scalar; }

float vector2d::operator()()
{
	return std::sqrtf(powf(x, 2) + powf(y, 2));
}

float& vector2d::operator[](std::size_t idx)
{
	if (idx == 0)
	{
		return x;
	}
	else if (idx == 1)
	{
		return y;
	}
}


vector2d operator+(const vector2d& LeftVector, const vector2d& RightVector)
{
	return {LeftVector.x + RightVector.x, LeftVector.y + RightVector.y};
}

vector2d operator-(const vector2d& LeftVector, const vector2d& RightVector)
{
	return { LeftVector.x - RightVector.x, LeftVector.y - RightVector.y };
}

std::ostream& operator<<(std::ostream& out, vector2d Vector)
{
	out << "{" << Vector.x << "; " << Vector.y << "}";
	return out;
}

void operator>>(std::istream& in, vector2d& Vector)
{
	in >> Vector.x;
	in >> Vector.y;
}
