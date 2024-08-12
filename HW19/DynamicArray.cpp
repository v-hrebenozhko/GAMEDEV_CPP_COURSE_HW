#include <iostream>
#include "DynamicIntArray.h"

int main()
{
	//Testing of ALL methods, c-tors, d-tors goes here

	DynamicIntArray intArray;
	DynamicIntArray intArray1(3);
	intArray1[0] = 3;
	intArray1[1] = 3;
	intArray1[2] = 3;
	intArray = intArray1;
	for (int i = 0; i < intArray.getSize(); i++)
	{
		std::cout << intArray[i] << "\n";
	}
	intArray.setSize(2);
	if (intArray != intArray1)
	{
		intArray.push_back(5);
		for (int i = 0; i < intArray.getSize(); i++)
		{
			std::cout << intArray[i] << "\n";
		}
	}
	intArray1.clear();
	std::cout << intArray1.getSize();

}
