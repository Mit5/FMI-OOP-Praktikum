#include "System.h"

void System::addUser(User user)
{
	users.push_back(user);
}

void System::addPremiumUser(PremiumUser premiumUser)
{
	premiumUsers.push_back(premiumUser);
}

bool System::doesUserExist(std::string username, std::string password)
{
	for (int i = 0; i < premiumUsers.size(); i++)
	{
		if (username == premiumUsers[i].getUsername() && User::comparePasswords(User::encodePass(password), premiumUsers[i].getPassword()))
		{
			return true;
		}
	}

	for (int i = 0; i < users.size(); i++)
	{
		if (username == users[i].getUsername() && User::comparePasswords(User::encodePass(password), users[i].getPassword()))
		{
			return true;
		}
	}

	return false;
}

void System::becomePremium(int id)
{
	User user = getUserById(id);
	PremiumUser newUser(user,"Premium user");
	premiumUsers.push_back(newUser);
	RemoveUserById(id);
}

void System::RemoveUserById(int id)
{
	for (int i = 0; i = users.size(); i++)
	{
		if (users[i].getId() == id)
		{
			std::swap(users[i], users[users.size() - 1]);
			break;
		}
	}
	users.pop_back();
}

User& System::getUserById(int id)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (id == users[i].getId())
		{
			return users[i];
		}
	}

	throw "Incorrect ID";
}
