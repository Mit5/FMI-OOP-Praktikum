#pragma once
#include <string>
#include <iostream>
class Animal
{
private:
	std::string name;
	std::string type;

public:
	virtual void talk() = 0;

	Animal();
	Animal(std::string name, std::string type);
	Animal(Animal& other);
	Animal& operator=(Animal& other);
	~Animal();
};

