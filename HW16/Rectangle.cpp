// Task 1

#include "Rectangle.h"


rectangle::rectangle()
{
	Height = 0;
	Length = 0;
}

rectangle::rectangle(float m_Length,float  m_Height)
{
	Length = m_Length;
	Height = m_Height;
}

float rectangle::GetArea()
{
	return Length * Height;
}

float rectangle::GetPerimeter()
{
	return (Length + Height) * 2;
}