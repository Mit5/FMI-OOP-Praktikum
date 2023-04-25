#pragma once
#include "ITPerson.h"

enum WorkType{automation, manual };

class QA : public ITPerson
{
private:
	WorkType workType;
public:
	QA();
	QA(std::string name, int experience, float salary, WorkType workType);
};

