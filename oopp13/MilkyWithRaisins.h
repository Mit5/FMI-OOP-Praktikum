#pragma once
#include "MilkyChocolate.h"
#include "Raisins.h"
#include <math.h>
class MilkyWithRaisins : public MilkyChocolate, public Raisins<int>
{
private:
	int getLength(int number);
public:
	MilkyWithRaisins() = default;
	MilkyWithRaisins(int id, double milkPercantage, double raisinsPercantage);

	bool validateId() override;
};

