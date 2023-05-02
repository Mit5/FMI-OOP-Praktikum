#pragma once
#include<string>
#include<fstream>
#include "HistoricalLandmark.h"
class Landmark
{
private:
	double coordinates;
	std::string description;

public:
	void setCoordinates(double coorinates);
	void setDescription(std::string description);

	std::string ToString();

	virtual void writeToFile() = 0;

};

