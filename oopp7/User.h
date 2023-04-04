#ifndef USER_H
#define USER_H
#include <cstring>
#include <iostream>
#include <fstream>


class User
{
private:
	char* username;
	char* password;

public:
	void setName(char* string);
	void setPassword(char* string);

	char* getName() const;
	char* getPassword() const;

	User();
	User(User& const other);
	User& operator=(User& const other);
	User(User&& other);
	User& operator=(User&& other);
	~User();

	bool operator==(User& other);

	bool checkUser();
	void writeUser();
};

void readAllUsers();


#endif // !USER_H
