#include "ContactBook.h"
#include "Contact.h"
#include "Address.h"
#include <iostream>

using namespace std;

//default constructor
ContactBook::ContactBook()
{
	ownerLastName = "";
	ownerFirstName = "";
	contacts = new Contact[capacity];
}

//parameterized constructor
ContactBook::ContactBook(string ownerLast, string ownerFirst)
{
	ownerLastName = ownerLast;
	ownerFirstName = ownerFirst;
	contacts = new Contact[capacity];
}

//Copy Constructor
ContactBook::ContactBook(const ContactBook& other)
{
	ownerFirstName = other.ownerFirstName;
	ownerLastName = other.ownerLastName;
	count = other.count;
	capacity = other.capacity;
	contacts = new Contact[capacity];
	for (int i = 0; i < count; i++)
	{
		contacts[i] = other.contacts[i];
	}
}

//Assignment Operator
ContactBook& ContactBook::operator= (const ContactBook& rhs)
{
	if (this != &rhs)
	{
		ownerFirstName = rhs.ownerFirstName;
		ownerLastName = rhs.ownerLastName;
		count = rhs.count;
		capacity = rhs.capacity;

		if (contacts != NULL)
		{
			delete [] contacts;
		}

		contacts = new Contact[capacity];

		for (int i = 0; i < count; i++)
		{
			contacts[i] = rhs.contacts[i];
		}
	}

	return *this;
}

//destructor
ContactBook::~ContactBook()
{
	if (contacts != NULL)
	{
		delete [] contacts;
		contacts = NULL;
	}
}

//function to search for a contact
int ContactBook::searchContact(string lastName, string firstName)
{
    // choose a random int not in the range of the array indexes
    int index = -1;

    for (int i = 0; i < count; i++)
    {
        //contact search is based on name therefore we will iterate through the array to see if entered first and last name match with any first and last name in the array
        if(contacts[i].getLastName() == lastName && contacts[i].getFirstName() == firstName)
        {
            //if there is a match we will set the index of the match in the array equal to the int index we will return and break out of the loop
            index = i;
        }
    }
    return index;
}

//function to delete a contact
void ContactBook::deleteContact()
{
	string lastName, firstName;
    
	cout << "******************************" << endl;
	cout << "***** Delete In Progress *****" << endl;
	cout << "******************************" << endl;
	cout << endl;
	cout << "Enter Last Name: ";
	cin >> lastName;
	cout << "Enter First Name: ";
	cin >> firstName;
	cout << endl;
	
	//we have to search for a contact to make sure it exists before we can delete it
	int index = searchContact(lastName, firstName);

	if (index == -1)
	{
		cout << "No existing contact to delete" << endl;
		cout << endl;
	}

	else 
	{
        //condition to delete a contact that is not the last contact
		if (index < (count - 1))
		{
			for (int i = 0; i < count - 1; i++)
			{
				//array shifts by 1 to "delete"
				contacts[index] = contacts[index + 1];
			}
		}

		count--;
		cout << "Contact " << (index + 1) << " Successfully Deleted" << endl;
		cout << endl;
	}
}

//function to update contact
void ContactBook::updateContactInfo()
{
	string lastName, firstName;
	int option, contactIndex = 0;
    bool contactExists = false;

	cout << "**************************************" << endl;
	cout << "***** Contact Update In Progress *****" << endl;
	cout << "**************************************" << endl;
	cout << endl;
	cout << "Enter Last Name: ";
	cin >> lastName;
	cout << "Enter First Name: ";
	cin >> firstName;
	cout << endl;

	for (int i = 0; i < count; i++)
    {
        if (lastName == contacts[i].getLastName() && firstName == contacts[i].getFirstName())
        {
            contactIndex = i;
           	contactExists = true;
           	break;
        }
	}

	if (contactExists)
	{
		cout << "What information would you like to change? " << endl;
		cout << endl;
		cout << "1 : Change Last Name" << endl;
		cout << "2 : Change First Name" << endl;
		cout << "3 : Change Address " << endl;
		cout << "4 : Change Phone Number" << endl;
		cout << "5 : Change Email" << endl;
		cout << "Option: ";
		cin >> option;
		cout << endl;
	
		if (option == 1)
		{
			string newLast;
			cout << "Enter New Last Name: ";
			cin >> newLast;
			contacts[contactIndex].setLastName(newLast);
			cout << endl;
			cout << "Last Name Successfully Updated" << endl;
			cout << endl;
		}
	
		else if (option == 2)
		{
			string newFirst;
            cout << "Enter New First Name: ";
            cin >> newFirst;
            contacts[contactIndex].setFirstName(newFirst);
			cout << endl;
            cout << "First Name Successfully Updated" << endl;
            cout << endl;
        }
	
		else if (option == 3)
		{
			Address newAddress;
			cout << "Enter New Address: " << endl;
			newAddress.input();
			contacts[contactIndex].setAddress(newAddress);
			cout << endl;
			cout << "Address Successfully Updated" << endl;
            cout << endl;
		}

		else if (option == 4)
		{
			string newPhone;
			cout << "Enter New Phone Number: ";
			cin >> newPhone;

			if (validPhone(newPhone))
			{
				contacts[contactIndex].setPhone(newPhone);
				cout << endl;
				cout << "Phone Number Successfully Updated" << endl;
                cout << endl;
			}
			
			else
			{
				cout << "Invalid Phone Number" << endl;
				cout << endl;
			}
		}

        else if (option == 5)
        {
            string newEmail;
            cout << "Enter New Email: ";
            cin >> newEmail;

            if (validEmail(newEmail))
            {
                contacts[contactIndex].setEmail(newEmail);
                cout << endl;
                cout << "Email Successfully Updated" << endl;
                cout << endl;
            }
                	
            else
            {
                cout << "Invalid Email" << endl;
                cout << endl;
            }
        }
	
        else
        {
            cout << "Invalid Entry" << endl;
            cout << endl;
        }
}

	else 
	{
		cout << "No Existing Contact To Update" << endl;
		cout << endl;
	}
}

//function to get size of list/count
int ContactBook::getCount() const
{
	return count;
}

//function to get particular contact at particular index
Contact ContactBook::getContactAtIndex(int index)
{
	if (index < 0 || index > count - 1)
	{
		cout << "Contact Does Not Exist" << endl;
		cout << endl;
	}
    
    	return contacts[index];
}

void ContactBook::grow()
{
    int newCapacity = capacity * 2;
    Contact* newContacts = new Contact[newCapacity];

    for (int i = 0; i < count; i++)
    {
        newContacts[i] = contacts[i];
    }

    delete[] contacts;

    capacity = newCapacity;
    contacts = newContacts;
}

void ContactBook::merge(ContactBook& other)
{
	while (count + other.count > capacity)
    {
        grow();
    }

    // Merge contacts into the current contact book
    for (int i = 0; i < other.count; ++i)
    {
        contacts[count] = other.contacts[i];
        count++;
    }

    // Sort the merged contacts to maintain a sorted order
    sort();
}

void ContactBook::sort()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (contacts[i] > contacts[j])
			{
				Contact temp = contacts[i];
				contacts[i] = contacts[j];
				contacts[j] = temp;
			}
		}
	}
}

string ContactBook::getOwnerLastName() const
{
	return ownerLastName;
}

string ContactBook::getOwnerFirstName() const
{
	return ownerFirstName;
}

void ContactBook::addContact(Contact contact)
{
	 // Check if there is enough space in the contacts array
    if (count < capacity) 
	{
        // Add the new contact to the end of the array
        contacts[count] = contact;
        count++;
        // You might want to sort the contacts array after adding a new contact
        sort();
    } 
	
	else 
	{
        // Handle the case where the contacts array is full
        cout << "Contact book is full. Cannot add more contacts." << endl;
    }
}

//friends
ostream& operator<< (ostream& out, const ContactBook& cb)
{
    if (cb.count == 0)
    {
        out << "Contact Book is Empty" << endl;
        out << endl;
    }
    
    else
    {
        for (int i = 0; i < cb.count; i++)
        {
            out << "Contact #" << (i + 1) << endl;
            out << cb.contacts[i];
            out << endl;
        }
    }

	return out;
}

istream& operator>> (istream& in, ContactBook& cb)
{
    cout << "****************************************" << endl;
    cout << "***** Contact Creation in Progress *****" << endl;
    cout << "****************************************" << endl;
    cout << endl;
    in >> cb.contacts[cb.count];
    cout << endl;
    cout << "Contact " << (cb.count + 1) << " Successfully Created" << endl;
    cout << endl;
    cb.count++;
	
    if (cb.count == cb.capacity)
    {
        cb.grow();
    }
    
	cb.sort();

	return in;
}