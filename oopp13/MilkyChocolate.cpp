#include "MilkyChocolate.h"

MilkyChocolate::MilkyChocolate() : Chocolate(), milkProcentage(35)
{
}

MilkyChocolate::MilkyChocolate(int id, double milkProcentage)
{
	if (!validateId())
	{
		id = 0;
	}

	this->id = id;
	this->milkProcentage = milkProcentage;

}

bool MilkyChocolate::validateId()
{
	return id >= 0;
}
