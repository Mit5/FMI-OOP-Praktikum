#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
	void talk();

	Cat();
	Cat(std::string name, std::string type);
};

