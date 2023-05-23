#pragma once
#include <string>
#include "Chocolate.h"
class DarkChocolate : virtual public Chocolate<std::string>
{
protected:
	double cacaoProcentage;

public:

	DarkChocolate();
	DarkChocolate(std::string id, double cacaoProcentage);

	bool validateId() override;

	
};

