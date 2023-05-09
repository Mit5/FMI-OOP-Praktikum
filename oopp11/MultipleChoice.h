#pragma once
#include "Question.h"
class MultipleChoice : public Question
{
private:
	std::string answers[10];
	int answersAmount;
	int correctAnswersAmount;

public:
	MultipleChoice(std::string question, int points, std::string answers[], int answersAmount, int correctIndexes[], int correctAnswersAmount);
};

