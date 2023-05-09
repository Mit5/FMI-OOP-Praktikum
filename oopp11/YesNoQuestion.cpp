#include "YesNoQuestion.h"

YesNoQuestion::YesNoQuestion(std::string question, int points, std::string answer) : Question(question,points), answer(answer)
{
}

void YesNoQuestion::ask()
{
	printQuesiton();
	std::cin >> answerInput;
}

int YesNoQuestion::grade()
{
	return getPoints() * (answer == answerInput);
}
