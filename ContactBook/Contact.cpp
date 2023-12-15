#include "Contact.h"
#include "Address.h"
#include <iostream>

using namespace std;

//default constructor
Contact::Contact()
{
    lastName = "";
    firstName = "";
    address = Address();
    phone = "";
    email = "";
}

//parameterized constructor
Contact::Contact(string l, string f, Address a, string p, string e)
{
    lastName = l;
    firstName = f;
    address = a;
    phone = p;
    email = e;
}

//accessors
string Contact::getLastName() const
{
    return lastName;
}

string Contact::getFirstName() const
{
    return firstName;
}

Address Contact::getAddress() const
{
    return address;
}

string Contact::getPhone() const
{
    return phone;
}

string Contact::getEmail() const
{
    return email;
}

//mutators
void Contact::setLastName(const string& l)
{
    lastName = l;
}

void Contact::setFirstName(const string& f)
{
    firstName = f;
}

void Contact::setAddress(const Address& a)
{
    address = a;
}

void Contact::setPhone(const string& p)
{
    if (validPhone(p))
    {
        phone = p;
    }
    
    else
    {
        cout << "Invalid phone number" << endl;
        exit(1);
    }
}

void Contact::setEmail(const string& e)
{
    if (validEmail(e))
    {
        email = e;
    }
    
    else
    {
        cout << "Invalid email" << endl;
        exit(1);
    }
}

//solicit info
void Contact::input()
{
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter first name: ";
    cin >> firstName;
    address.input();;
    cout << "Enter phone number: ";
    cin >> phone;
    
    while (!(validPhone(phone)))
    {
        cout << "Invalid phone number please re-enter: ";
        cin >> phone;
    }
    
    cout << "Enter email: ";
    cin >> email;
    
    while (!(validEmail(email)))
    {
        cout << "Invalid email address please re-enter: ";
        cin >> email;
    }
}

//print info
void Contact::output()
{
    cout << "Last name: " << lastName << endl;
    cout << "First name: " << firstName << endl;
    cout << "Address: ";
    address.output();
    cout << "Phone number: " << phone << endl;
    cout << "Email: " << email << endl;
}

//validate phone number
bool validPhone(string p)
{
    if (p.length() != 10)
    {
        return false;
    }
    
    for (int i = 0; i < p.length(); i++)
    {
        if (!(isdigit(p[i])))
        {
            return false;
        }
    }
    return true;
}

//validate email
bool validEmail(string e)
{
    int atLocation = 0;
    int dotLocation = 0;
    int afterAt = 0;
    int afterDot = 0;
    bool atPresent = false;
    bool dotPresent = false;

    if (e == "")
    {
        return false;
    }

    //check if an '@' is present, get index of where '@' is. get index of char after '@'
    for (int i = 0; i < e.length() - 1; i++)
    {
        if (e[i] == '@')
        {
            atPresent = true;
            atLocation = i;
            afterAt = i + 1;
        }
    }

    //check if '.' is present, get index of where '.' is, index of char after '.', get index of char before '.'
    //e.length - 1 is used so i + 1 does not go out of bounds
    for (int i = 0; i < e.length() - 1; i++)
    {
        if (e[i] == '.')
        {
            dotPresent = true;
            dotLocation = i;
            afterDot = i + 1;
        }
    }

    //first letter must be a char
    if (!(isalpha(e[0])))
    {
        return false;
    }

    //if there is anything except alpha chars in between '@' and '.' the email is invalid
    for (int i = afterAt; i < dotLocation; i++)
    {
        if (!(isalpha(e[i])))
        {
            return false;
        }
    }

    //if there is not a letter of the alphabet after the '.' then the email is invalid
    if (!(isalpha(e[afterDot])))
    {
        return false;
    }

    // if there is no '@' or '.' present, the email is invalid
    if (atPresent == false || dotPresent == false)
    {
        return false;
    }

    return true;
}

//overloaded assignment operators
//if lastnames are not equal then compare, else conpare first names
bool Contact::operator< (const Contact& c) const
{
    if (lastName != c.lastName)
    {
        return lastName < c.lastName;
    }

    return firstName < c.firstName;
}

bool Contact::operator> (const Contact& c) const
{
    if (lastName != c.lastName)
    {
        return lastName > c.lastName;
    }
    
    return firstName > c.firstName;
}

//last name and first name must be equal
bool Contact::operator== (const Contact& c) const
{
    return (lastName == c.lastName) && (firstName == c.firstName);
}

//either first names do not match or last nammes do not match
bool Contact::operator!= (const Contact& c) const
{
    return (lastName != c.lastName) || (firstName != c.firstName);
}

//check if invoking object lastname is less than parameter lastname or last names are equal and invokinh object first name is less than or equal to parameter last name
bool Contact::operator<= (const Contact& c) const
{
    return (lastName < c.lastName) || (lastName == c.lastName && firstName <= c.firstName);
}

bool Contact::operator>= (const Contact& c) const
{
    return (lastName > c.lastName) || (lastName == c.lastName && firstName >= c.firstName);
}

//friends
ostream& operator<< (ostream& out, const Contact& c)
{
    out << "Last name: " << c.lastName << endl;
    out << "First name: " << c.firstName << endl;
    out << "Address: ";
    c.address.output();
    out << "Phone number: " << c.phone << endl;
    out << "Email: " << c.email << endl;
    return out;
}

istream& operator>> (istream& in, Contact& c)
{
    cout << "Enter last name: ";
    in >> c.lastName;
    cout << "Enter first name: ";
    in >> c.firstName;
    c.address.input();
    cout << "Enter phone number: ";
    in >> c.phone;

    while (!(validPhone(c.phone)))
    {
        cout << "Invalid phone number please re-enter: ";
        in >> c.phone;
    }

    cout << "Enter email: ";
    in >> c.email;

    while (!(validEmail(c.email)))
    {
        cout << "Invalid email address please re-enter: ";
        in >> c.email;
    }
    
    return in;
}