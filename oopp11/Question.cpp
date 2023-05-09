#include "Question.h"

Question::Question(std::string question, int points) : question(question), points(points)
{

}

void Question::printQuesiton()
{
	std::cout << question<<"\n";
}

int Question::getPoints()
{
	return points;
}
