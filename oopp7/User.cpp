#include "User.h"
#pragma warning(disable:4996)

int MAX_SIZE = 32;

void User::setName(char* string)
{
	if (strlen(string) >= MAX_SIZE)
	{
		throw std::exception("Input exceeds name size!");
	}
	else
	{
		char* cpy = new char[strlen(string)+1];
		strcpy(cpy, string);
		username = cpy;
	}
}

void User::setPassword(char* string)
{
	if (strlen(string) >= MAX_SIZE)
	{
		throw std::exception("Input exceeds password size!");
	}
	else
	{
		char* cpy = new char[strlen(string) + 1];
		strcpy(cpy, string);
		password = cpy;
	}
}

char* User::getName() const
{
	char* cpy = new char[strlen(username)];
	strcpy(cpy, username);
	return cpy;
}

char* User::getPassword() const
{
	char* cpy = new char[strlen(password)];
	strcpy(cpy, password);
	return cpy;
}

User::User()
{
	setName((char*)"No_name");
	setPassword((char*)"Password");

}

User::User(User& const other)
{
	setName(other.username);
	setPassword(other.password);
}

User& User::operator=(User& const other)
{
	if (this != &other)
	{
		delete[] username;
		delete[] password;
		setName((char*)other.username);
		setPassword((char*)other.password);
	}
	return *this;
}

User::User(User&& other)
{
	setName((char*)other.username);
	setPassword((char*)other.password);
	delete[] other.username;
	delete[] other.password;
}

User& User::operator=(User&& other)
{
	if (this != &other)
	{
		delete[] username;
		delete[] password;
		setName((char*)other.username);
		setPassword((char*)other.password);
		delete[] other.username;
		delete[] other.password;
	}

	return *this;
}

User::~User()
{
	delete[] username;
	delete[] password;
}

bool User::operator==(User& other)
{
	bool nameCheck = !strcmp(this->username, other.username);
	bool passCheck = !strcmp(this->password, other.password);
	return nameCheck && passCheck;
}

void User::writeUser()
{
	std::ofstream file("Users.txt", std::ios::app, std::ios::binary);

	if (!file.is_open())
	{
		throw std::exception("File cannot be open!");
	}

	if (!checkUser())
	{
		file.write((char*)this, sizeof(*this));
	}

	file.close();
}

bool User::checkUser()
{
	std::ifstream file("Users.txt",std::ios::binary);

	if (!file.is_open())
	{
		throw std::exception("File cannot be open!");
	}


	User user;
	while (!file.eof())
	{
		file.read((char*)&user, sizeof(user));
		if (user == *this)
		{
			file.close();
			return true;
		}
	}

	file.close();
	return false;
}

void readAllUsers()
{
	std::ifstream file("Users.txt",std::ios::binary);

	if (!file.is_open())
	{
		throw std::exception("File cannot be open!");
	}

	User user;
	while (!file.eof())
	{
		std::cout << "hi";
		file.read((char*)&user, sizeof(user));
		std::cout << user.getName()<<" "<< user.getPassword()<<"\n";
	}

	file.close();
}
