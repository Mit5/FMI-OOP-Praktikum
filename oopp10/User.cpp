#include "User.h"

std::ostream& operator<<(std::ostream& os, User& user)
{
    os << user.username << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, User& user)
{
    char* buffer = new char[1024];
    is.getline(buffer, 1024,'_');
    is >> user.username;
    return is;
}

void User::setUsername(std::string username)
{
    this->username = username;
}
