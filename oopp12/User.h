#pragma once
#include<string>
#include<vector>
class User
{
private:

	static int id_gen;

	int id;
	std::string username;
	std::string password;


public:
	static std::string encodePass(std::string password);
	static bool comparePasswords(std::string firstPass, std::string secondPass);

	std::string getPassword();

	std::string getUsername();

	int getId();

	User(std::string username, std::string password);
	User(User& user);
};


