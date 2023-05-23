#pragma once
#include "Chocolate.h"

template<typename T>

class Raisins : virtual public Chocolate<T>
{
protected:
	double raisinsPercantage;

public:

	Raisins();
	
	virtual bool validateId() override = 0;
};

template<typename T>
inline Raisins<T>::Raisins() : raisinsPercantage(20)
{
};
