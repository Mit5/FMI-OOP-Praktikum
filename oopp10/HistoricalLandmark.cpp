#include "HistoricalLandmark.h"

void HistoricalLandmark::setYearOfEvent(int year)
{
	yearOfEvent = year;
}

void HistoricalLandmark::writeToFile()
{
	std::ofstream file("HistoricalLandmarks.txt",std::ios::app);

	file << *this;

	file.close();
}

std::ostream& operator<<(std::ostream& os, HistoricalLandmark& landmark)
{
	return os << landmark.ToString() << " " << landmark.yearOfEvent << "\n";
}
