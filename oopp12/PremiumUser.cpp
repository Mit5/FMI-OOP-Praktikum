#include "PremiumUser.h"

PremiumUser::PremiumUser(std::string username, std::string password, std::string planDescription) : User(username,password), planDescription(planDescription)
{
}

PremiumUser::PremiumUser(User user, std::string planDescription) : User(user), planDescription(planDescription)
{
}

void PremiumUser::addPaymentDate(std::string date)
{
	dates.push_back(date);
}
