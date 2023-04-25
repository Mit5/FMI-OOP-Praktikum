#pragma once
#include "Employee.h"
#include "Project.h"

class ITPerson: public Employee
{
private:
	Project** projects;
	int projectsCount;
	int capacity;

	void resize(); //predstavi si che ima takova neshto

public:
	ITPerson();
	ITPerson(std::string name, int experience, float salary);
	
	void addProject(Project& project);


};

