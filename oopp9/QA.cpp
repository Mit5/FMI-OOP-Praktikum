#include "QA.h"

QA::QA() : ITPerson(), workType(manual)
{
}

QA::QA(std::string name, int experience, float salary, WorkType workType) : ITPerson(name,experience,salary), workType(workType)
{
}
