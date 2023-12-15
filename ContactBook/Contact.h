#ifndef CONTACT_H
#define CONTACT_H

#include "Address.h"
#include <iostream>
#include <string>

class Contact
{
    private:
    std::string lastName;
    std::string firstName;
    Address address;
    std::string phone;
    std::string email;

    public:
    //default constructor
    Contact();

    //parameterized constructor
    Contact(std::string l, std::string f, Address a, std::string p, std::string e);
    
    //accessors
    std::string getLastName() const;
    std::string getFirstName() const;
    Address getAddress() const;
    std::string getPhone() const;
    std::string getEmail() const;
    
    //mutators
    void setLastName(const std::string& l);
    void setFirstName(const std::string& f);
    void setAddress(const Address& a);
    void setPhone(const std::string& p);
    void setEmail(const std::string& e);

    //solicit and print info
    void input();
    void output();

    //overloaded comparison operators
    bool operator< (const Contact& c) const;
    bool operator> (const Contact& c) const;
    bool operator== (const Contact& c) const;
    bool operator!= (const Contact& c) const;
    bool operator<= (const Contact& c) const;
    bool operator>= (const Contact& c) const;

    //friends
    friend std::ostream& operator<< (std::ostream& out, const Contact& c);
    friend std::istream& operator>> (std::istream& in, Contact& c);
};

//additional functions to verify phone number is all digits and of length 10 and to verify email is in the correct format
bool validEmail(std::string e);
bool validPhone(std::string p);

#endif
