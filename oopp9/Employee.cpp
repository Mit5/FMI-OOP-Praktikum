#include "Employee.h"

Employee::Employee() : name("No name"), experience(0), salary(10)
{
}

Employee::Employee(std::string name, int experience, float salary) : name(name), experience(experience), salary(salary)
{
}
