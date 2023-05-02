#pragma once
#include "User.h"
#include "Landmark.h"
#include <vector>
class NormalUser : public User
{
private:
	std::vector<Landmark> landmarks;
public:
	void writeToFile();

	void addLandmark(Landmark& landmark);
};

