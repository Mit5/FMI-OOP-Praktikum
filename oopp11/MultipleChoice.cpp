#include "MultipleChoice.h"

MultipleChoice::MultipleChoice(std::string question, int points, std::string answers[],int answersAmount, int correctIndexes[], int correctAnswersAmount) : Question(question,points)
{
	this->correctAnswersAmount = correctAnswersAmount;
	this->answersAmount = answersAmount;
	for (int i = 0; i < answersAmount; i++)
	{
		this->answers[i] = answers[i];
	}
}
