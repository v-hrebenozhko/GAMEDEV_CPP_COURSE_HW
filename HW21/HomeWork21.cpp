#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void PrintVector(std::vector<std::string>& Vector)
{
	for (int i = 0; i < Vector.size(); i++)
	{
		std::cout << Vector[i] << " ";
	}
	std::cout << std::endl;
}

bool CompareByLength(const std::string& Str1, const std::string& Str2)
{
	return Str1.size() < Str2.size();
}

class LengthComparator
{
public:
	bool operator()(const std::string& Str1, const std::string& Str2)
	{
		return Str1.size() > Str2.size();
	}
};

unsigned int countDivisibleBy(const std::vector<int>& Vector, int Number) {
	return std::count_if(Vector.begin(), Vector.end(), [Number](int Var) {
		return Var % Number == 0;
	});
}

int main()
{
	std::vector<std::string> StringContainer = { "str","Word","Any","Economy","Software","tree" };

	std::sort(StringContainer.begin(), StringContainer.end(),CompareByLength);
	PrintVector(StringContainer);
	
	std::sort(StringContainer.begin(), StringContainer.end(), LengthComparator());
	PrintVector(StringContainer);

	std::sort(StringContainer.begin(), StringContainer.end(),
	[](const std::string& Str1, const std::string& Str2){return Str1.size() < Str2.size(); });
	PrintVector(StringContainer);

	std::vector<int> VectorInt = { 5,3,2,2,10,8,15,18 };
	std::cout << countDivisibleBy(VectorInt, 3);
}


