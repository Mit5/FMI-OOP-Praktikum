#include "Manager.h"

Manager::Manager() : Employee(), employeesCount(0)
{
}

Manager::Manager(std::string name, int experience, float salary, int employeesCount) : Employee(name,experience,salary), employeesCount(employeesCount)
{
}
