#include "Dog.h"

Dog::Dog() : Animal()
{
}

Dog::Dog(std::string name, std::string type) : Animal(name,type)
{
}

void Dog::talk()
{
	std::cout << "\nbark\n";
}
