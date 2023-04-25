#include "ITPerson.h"

void ITPerson::resize()
{
	Project** newProjects = new Project * [capacity * 2]{nullptr};
	for (int i = 0; i < capacity; i++)
	{
		newProjects[i] = projects[i];
	}
	delete projects;
	projects = newProjects;
}

ITPerson::ITPerson() : Employee(), projects({nullptr}), projectsCount(0), capacity(10)
{
}

ITPerson::ITPerson(std::string name, int experience, float salary) : Employee(name, experience, salary), projects({nullptr}), projectsCount(0), capacity(10)
{
}

void ITPerson::addProject(Project& project)
{
	if (projectsCount == capacity)
	{
		resize();
	}
	projects[projectsCount] = &project;
	projectsCount++;
}
