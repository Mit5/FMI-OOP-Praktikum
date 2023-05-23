#pragma once
#include "Chocolate.h"
class MilkyChocolate : virtual public Chocolate<int>
{
protected:
	double milkProcentage;

public:
	MilkyChocolate();
	MilkyChocolate(int id, double milkProcentage);

	bool validateId() override;


};

