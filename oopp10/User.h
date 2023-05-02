#pragma once
#pragma warning(disable:4996)
#include <string>
#include <fstream>
class User
{
private:
	std::string username;
	
public:
	void setUsername(std::string username);

	virtual void writeToFile() = 0;

	friend std::ostream& operator<<(std::ostream& os, User& user);

	friend std::istream& operator>>(std::istream& is, User& user);
};

