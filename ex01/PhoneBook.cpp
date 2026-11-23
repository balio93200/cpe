#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : _count(0), _next(0) {}

bool PhoneBook::add()
{
    if (!_contacts[_next].fill())
        return false;
    _next = (_next + 1) % 8;
    if (_count < 8)
        _count++;
    return true;
}

bool PhoneBook::search() const
{
    if (_count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return true;
    }
    for (int i = 0; i < _count; i++)
        _contacts[i].displayRow(i);
    std::cout << "Index: ";
    std::string line;
    if (!std::getline(std::cin, line))
        return false;
    if (line.length() != 1 || line[0] < '0' || line[0] >= '0' + _count)
    {
        std::cout << "Invalid index." << std::endl;
        return true;
    }
    _contacts[line[0] - '0'].displayFull();
    return true;
}
