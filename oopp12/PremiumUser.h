#pragma once
#include "User.h"
class PremiumUser : public User
{
private:
	std::string planDescription;
	std::vector<std::string> dates;
public:
	PremiumUser(std::string username, std::string password, std::string planDescription);
	PremiumUser(User user, std::string planDescription);

	void addPaymentDate(std::string date);
};

