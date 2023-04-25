#pragma once
#include "ITPerson.h"

enum Language{ C, CPP, Pyhton, Java, Ruby, Haskell };

class Programmer : public ITPerson
{
private:
	Language language;
public:
	Programmer();
	Programmer(std::string name, int experience, float salary, Language language);
};

