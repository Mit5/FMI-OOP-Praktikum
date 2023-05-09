#pragma once
#include "Landmark.h"
class HistoricalLandmark : public Landmark
{
private:
	int yearOfEvent;
public:
	void setYearOfEvent(int year);

	friend std::ostream& operator<<(std::ostream& os, HistoricalLandmark& landmark);

	friend std::istream& operator>>(std::istream& is, HistoricalLandmark& landmark);

	void writeToFile();
};

