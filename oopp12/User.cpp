#include "User.h"

int User::id_gen = 0;

std::string User::encodePass(std::string password)
{
	std::string newPassword = password;
	for (int i = 0; i < password.size(); i++)
	{
		if ((password[i] >= 'a' && password[i] < 'z') || (password[i] >= 'A' && password[i] < 'Z'))
		{
			newPassword[i]++;
		}
		else if (password[i] == 'z')
		{
			newPassword[i] = 'a';
		}
		else if (password[i] == 'Z')
		{
			newPassword[i] = 'A';
		}
		else if(password[i]>='1' && password[i]<='9')
		{
			newPassword[i]--;
		}
		else
		{
			newPassword[i] = '?';
		}

	}
	return newPassword;
}

bool User::comparePasswords(std::string firstPass, std::string secondPass)
{
	return firstPass == secondPass;
}

std::string User::getPassword()
{
	return password;
}

std::string User::getUsername()
{
	return username;
}

int User::getId()
{
	return id;
}

User::User(std::string username, std::string password) : id(id_gen++), username(username), password(User::encodePass(password))
{
	
}

User::User(User& user) : id(user.id), username(user.username), password(user.password)
{

}