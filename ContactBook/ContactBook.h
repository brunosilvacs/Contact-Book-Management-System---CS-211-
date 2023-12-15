#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "Contact.h"
#include "Address.h"
#include <iostream>
#include <string>

class ContactBook
{
	private:
	std::string ownerLastName;
	std::string ownerFirstName;
   	int count = 0;
	int capacity = 10;
	Contact *contacts;
	void sort();

	public:
	//default constructor
	ContactBook();
	//Constructor
	ContactBook(std::string ownerLast, std::string ownerFirst);
	//Copy Constructor
	ContactBook(const ContactBook& other);
	//Assignment Operator
	ContactBook& operator= (const ContactBook& rhs);
	//destructor
	~ContactBook();

	//menu functions
	void addContact();
	void deleteContact();
	int searchContact(std::string lastName, std::string firstName);
	void updateContactInfo();
	void displayAllContacts();

	//additional functions
	Contact getContactAtIndex(int index);
	int getCount() const;
    void grow();
	void merge(ContactBook& cb);
	std::string getOwnerLastName() const;
	std::string getOwnerFirstName() const;
	void addContact(Contact contact);

	//friends
    friend std::ostream& operator<< (std::ostream& out, const ContactBook& cb);
    friend std::istream& operator>> (std::istream& in, ContactBook& cb);
};

#endif

