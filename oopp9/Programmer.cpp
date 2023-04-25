#include "Programmer.h"

Programmer::Programmer() : ITPerson(), language(C)
{
}

Programmer::Programmer(std::string name, int experience, float salary, Language language) : ITPerson(name,experience,salary), language(language)
{
}
