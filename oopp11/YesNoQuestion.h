#pragma once
#include "Question.h"
class YesNoQuestion : public Question
{
private:
	std::string answer;
public:
	YesNoQuestion(std::string question, int points, std::string answer);
	void ask() override;
	int grade() override;
};

