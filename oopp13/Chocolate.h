#pragma once
template <typename T>
class Chocolate
{
protected:
	T id;

public:

	virtual bool validateId() = 0;
};
