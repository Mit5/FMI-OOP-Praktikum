#pragma once
#include "Employee.h"
class Manager : public Employee
{
private:
	int employeesCount;
	//TODO add employeesArr
public:
	Manager();
	Manager(std::string name, int experience, float salary, int employeesCount);
};

