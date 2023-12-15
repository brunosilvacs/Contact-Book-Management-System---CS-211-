#include "Address.h"
#include <iostream>

using namespace std;

// Default constructor
Address::Address() : home(""), street(""), apt(""), city(""), state(""), zip("") {}

// Parameterized constructor
Address::Address(const string& _home, const string& _street,
                 const string& _apt, const string& _city,
                 const string& _state, const string& _zip)
    : home(_home), street(_street), apt(_apt), city(_city), state(_state), zip(_zip) {}

string Address::getHome() const 
{
    return home;
}

string Address::getStreet() const 
{
    return street;
}

string Address::getApt() const 
{
    return apt;
}

string Address::getCity() const 
{
    return city;
}

string Address::getState() const 
{
    return state;
}

string Address::getZip() const 
{
    return zip;
}

void Address::output() const 
{
    cout << "Home: " << home << ", Street: " << street;
    if (!apt.empty()) 
    {
        cout << ", Apt: " << apt;
    }
    cout << ", City: " << city << ", State: " << state << ", Zip: " << zip << endl;
}

void Address::input() {
    cout << "House or apart (h/a): ";
    cin >> home;
    cout << "Enter street: ";
    cin >> street;
    cout << "Enter apt: ";
    cin >> apt;
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter state: ";
    cin >> state;
    cout << "Enter zip: ";
    cin >> zip;
}
