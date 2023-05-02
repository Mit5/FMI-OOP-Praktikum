#include "NormalUser.h"

void NormalUser::writeToFile()
{
	std::ofstream file("Normans.txt", std::ios::app);

	file << *this;

	file.close();
}

void NormalUser::addLandmark(Landmark& landmark)
{
	landmarks.push_back(landmark);
}
