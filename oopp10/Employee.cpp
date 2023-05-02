#include "Employee.h"

void Employee::writeToFile()
{
	std::ofstream file("Employees.txt", std::ios::app);

	file << *this;

	file.close();
}
