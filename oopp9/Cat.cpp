#include "Cat.h"

void Cat::talk()
{
	std::cout << "\n|\\---/|\n| ^_^ |\n\\__w__/    meow\n";
}

Cat::Cat() : Animal()
{
}

Cat::Cat(std::string name, std::string type) : Animal(name,type)
{
}
