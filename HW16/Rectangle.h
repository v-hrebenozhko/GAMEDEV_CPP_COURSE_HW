#pragma once

// Task 1

class rectangle
{
private:
	float Length;
	float Height;

public:
	rectangle();
	rectangle(float m_Length, float m_Height);
	float GetArea();
	float GetPerimeter();
};
