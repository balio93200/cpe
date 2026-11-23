#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook();
    bool add();
    bool search() const;

private:
    Contact _contacts[8];
    int     _count;
    int     _next;
};

#endif
