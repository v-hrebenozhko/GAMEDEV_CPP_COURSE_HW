#include <iostream>
#include <algorithm>

struct Student
{
	std::string Name;
	int Marks[4];
};

// Task 1

int GetAverageMark(const Student& SomeStudent)
{
	int Sum = 0;
	for (int i = 0; i < sizeof(SomeStudent.Marks) / sizeof(int); i++)
	{
		Sum += SomeStudent.Marks[i];
	}
	return Sum / (sizeof(SomeStudent.Marks) / sizeof(int));
}

// Task 3

bool CompareByAvgMark(const Student& Student1, const Student& Student2)
{
	return GetAverageMark(Student1) > GetAverageMark(Student2);
}

void SortStudentsByAvg(Student* Students, int Size)
{
	std::sort(Students, Students + Size , CompareByAvgMark);
}

// Task 4

Student* GetBestStudent(Student* Students, int Size)
{
	Student* BestStudent = Students;
	for (int i = 1; i < Size ; i++)
	{
		if (GetAverageMark(*BestStudent) < GetAverageMark(Students[i]))
		{
			BestStudent = &Students[i];
		}
	}
	return BestStudent;
}

// Task 5

int GetBestStudentsCount(const Student* Students, int Size, int N)
{
	int Count = 0;
	for (int i = 0; i < Size; i++)
	{
		if (GetAverageMark(Students[i]) > N)
		{
			Count++;
		}
	}
	return Count;
}

// Task 6

Student* GetBestStudents(const Student* InStudents, unsigned InSize, Student* OutStudents, unsigned& OutSize, unsigned Percent)
{
	OutSize = InSize * Percent / 100;
	Student* CopyStudents = new Student[InSize];
	for (int i = 0; i < InSize; i++)
	{
		CopyStudents[i] = InStudents[i];
	}
	SortStudentsByAvg(CopyStudents, InSize);
	OutStudents = new Student[OutSize];
	for (int i = 0; i < OutSize; i++)
	{
		OutStudents[i] = CopyStudents[i];
		std::cout << GetAverageMark(OutStudents[i]) << " ";
	}
	delete[] CopyStudents;
	return OutStudents;

}

int main()
{

//Task 2

	Student Students[5];
}