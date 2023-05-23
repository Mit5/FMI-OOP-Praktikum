#include "DarkChocolate.h"

DarkChocolate::DarkChocolate() : Chocolate(), cacaoProcentage(80)
{
}

DarkChocolate::DarkChocolate(std::string id, double cacaoProcentage)
{
	if (!validateId())
	{
		id = "";
	}
	this->id = id;
	this->cacaoProcentage = cacaoProcentage;
}

bool DarkChocolate::validateId()
{
	for (int i = 0; i < id.size(); i++)
	{
		char currLetter = id[i];
		if (!(currLetter >= 'a' && currLetter <= 'z') || !(currLetter >= 'A' && currLetter <= 'Z'))
		{
			return false;
		}
	}
	return true;
}
