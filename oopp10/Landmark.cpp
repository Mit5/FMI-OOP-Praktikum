#include "Landmark.h"

void Landmark::setCoordinates(double coorinates)
{
	this->coordinates = coordinates;
}

void Landmark::setDescription(std::string description)
{
	this->description = description;
}

std::string Landmark::ToString()
{
	std::string output = std::to_string(coordinates) + " " + description;
}