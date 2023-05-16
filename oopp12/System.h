#pragma once
#include "User.h"
#include "PremiumUser.h"
class System
{
public:

    static System& getInstance()
    {
        static System instance; // Ще се създаде инстанция по време на първото извикване.
        return instance;
    }

    void addUser(User user);

    void addPremiumUser(PremiumUser premiumUser);

    bool doesUserExist(std::string username, std::string password);

    void becomePremium(int id);

private:
    std::vector<User> users;
    std::vector<PremiumUser> premiumUsers;

    void RemoveUserById(int id);

    User& getUserById(int id);

    System() {};
};

