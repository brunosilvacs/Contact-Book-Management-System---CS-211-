// Address.h

/**
 * Declaration of class Address. It is used to store and retrieve 
 * information on Address such as home number, street, apt#, city,
 * state, and zip.
 *
 * Author: Yosef Alayev
 */


#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
   private:
      std::string home;
      std::string street;
      std::string apt;
      std::string city;
      std::string state;
      std::string zip;

   public:

      // Default constructor
      // Initializes all variable to empty string
      Address();

      // Initializes all variables to parameters
      Address(const std::string& _home, const std::string& _street,
	      const std::string& _apt, const std::string& _city,
	      const std::string& state, const std::string& zip);

      // Accessor method for the home instance variable
      std::string getHome() const;

      // Accessor method for the street instance variable
      std::string getStreet() const;

      // Accessor method that returns apartment number
      // if it is an apartment building, or empty string if
      // it is a private house.
      std::string getApt() const;

      // Accessor method for the city instance variable
      std::string getCity() const;

      // Accessor method for the state instance variable
      std::string getState() const;

      // Accessor method for the zip instance variable
      std::string getZip() const;

      // Method that prints Address to console
      void output() const;

      // Method that solicits the information 
      // Apartment will be set to empty string if it is a private house
      // If it is an Apartment Building, method will solicit
      // info about apartment 
      void input();
};
#endif
