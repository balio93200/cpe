#include "Contact.hpp"
#include <iostream>
#include <iomanip>

static bool ask(const std::string &prompt, std::string &out)
{
    out.clear();
    while (out.empty())
    {
        std::cout << prompt << ": ";
        if (!std::getline(std::cin, out))
            return false;
    }
    return true;
}

static std::string truncate(const std::string &s)
{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

bool Contact::fill()
{
    return ask("First name", _firstName)
        && ask("Last name", _lastName)
        && ask("Nickname", _nickname)
        && ask("Phone number", _phoneNumber)
        && ask("Darkest secret", _darkestSecret);
}

void Contact::displayRow(int index) const
{
    std::cout << std::right
        << std::setw(10) << index << '|'
        << std::setw(10) << truncate(_firstName) << '|'
        << std::setw(10) << truncate(_lastName) << '|'
        << std::setw(10) << truncate(_nickname) << std::endl;
}

void Contact::displayFull() const
{
    std::cout << "First name: " << _firstName << std::endl;
    std::cout << "Last name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone number: " << _phoneNumber << std::endl;
    std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
