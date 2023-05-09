#pragma once
#include<string>
#include<iostream>
class Question
{
private:
	std::string question;
	int points;

protected:
	std::string answerInput;

public:

	Question(std::string question, int points);

	void printQuesiton();
	int getPoints();

	virtual void ask() = 0;
	virtual int grade() = 0;
};

