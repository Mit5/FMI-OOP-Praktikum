#include "Animal.h"

Animal::Animal() : name("Pesho"), type("Jivotno")
{

}

Animal::Animal(std::string name, std::string type) : name(name), type(type)
{
}

Animal::Animal(Animal& other) : name(other.name), type(other.type)
{
}

Animal& Animal::operator=(Animal& other)
{
	if(this != &other)
	{
		this->name = other.name;
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal()
{

}
