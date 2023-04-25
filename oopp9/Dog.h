#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog();
	Dog(std::string name, std::string type);

	void talk();
};

