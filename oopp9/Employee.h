#pragma once
#include <string>
class Employee
{
private:
	std::string name;
	int experience;
	float salary;

public:
	Employee();
	Employee(std::string name, int experience, float salary);
};

