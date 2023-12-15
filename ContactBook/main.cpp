#include "ContactBook.h"
#include "Contact.h"
#include "Address.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main ()
{
    const int size = 5;
    int numCB = 0;
    ContactBook* cbArray = new ContactBook[size];

    cout << endl;
    cout << "********************************************************************" << endl;
    cout << "***** Welcome To Your Personal Contact Book Management System! *****" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;

    while (true)
    {
        string choice;
        cout << "*********************" << endl;
        cout << "* Contact Book Menu *" << endl;
        cout << "*********************" << endl;
        cout << endl;
        cout << "1. Create a new Contact Book" << endl;
        cout << "2. Remove a Contact Book" << endl;
        cout << "3. Display all Contact Books" << endl;
        cout << "4. Merge Contact Books" << endl;
        cout << "5. Select a Contact Book" << endl;
        cout << "6. Exit Program" << endl;
        cout << "Choice: ";
        cin >> choice;
        cout << endl;
            
        if (choice == "1")
        {
            if (numCB < 5)
            {
                string lastName, firstName;
                cout << "****************************" << endl;
                cout << "* Creating new Contact Book *" << endl;
                cout << "****************************" << endl;
                cout << endl;
                cout << "Enter your last name: " << endl;
                cin >> lastName;
                cout << "Enter your first name: " << endl;
                cin >> firstName;
                cout << endl;
                cbArray[numCB] = {lastName, firstName};
                numCB++;
            }

            else
            {
                cout << "There can only be a maximum of 5 Contact Books!" << endl;
                cout << endl;
            }
        }
        
        else if (choice == "2")
        {
            string lastName, firstName;
            cout << "***************************" << endl;
            cout << "* Removing a Contact Book *" << endl;
            cout << "***************************" << endl;
            cout << endl;
            cout << "Enter owner's last name: ";
            cin >> lastName;
            cout << "Enter owner's first name: ";
            cin >> firstName;
            cout << endl;

            int index = -1;

            for (int i = 0; i < numCB; i++)
            {
                if (cbArray[i].getOwnerLastName() == lastName && cbArray[i].getOwnerFirstName() == firstName)
                {
                    index = i;
                    break; // Found the Contact Book, no need to continue searching
                }
            }

            if (index == -1)
            {
                cout << "Contact Book not found to delete" << endl;
                cout << endl;
            }

            else
            {
                // Shift the Contact Books to remove the one at the found index
                for (int i = index; i < numCB - 1; i++)
                {
                    cbArray[i] = cbArray[i + 1];
                }

                numCB--;

                cout << "Contact Book removed successfully!" << endl;
                cout << endl;
            }
        }

        else if (choice == "3")
        {
            cout << "****************************************" << endl;
            cout << "***** Displaying All Contact Books *****" << endl;
            cout << "****************************************" << endl;
            cout << endl;
            for (int i = 0; i < numCB; i++)
            {
                cout << "***** Contact Book " << (i+1) << " {" << cbArray[i].getOwnerLastName() << ", " << cbArray[i].getOwnerFirstName() << "} *****" << endl;
                cout << endl;
                cout << cbArray[i];
                cout << endl;
            }
        }
            
        else if (choice == "4")
        {
            if (numCB >= 2)
            {
                int index1, index2;
                cout << "*************************" << endl;
                cout << "* Merging Contact Books *" << endl;
                cout << "*************************" << endl;
                cout << endl;
                cout << "Enter index of first Contact Book you want to merge (0-4): ";
                cin >> index1;
                cout << "Enter index of second Contact Book you would like to merge (0-4): ";
                cin >> index2;
                cout << endl;

                if (index1 >= 0 && index1 < numCB && index2 >= 0 && index2 < numCB && index1 != index2)
                {
                    cbArray[index1].merge(cbArray[index2]);

                    for (int i = index2; i < numCB - 1; i++)
                    {
                        cbArray[i] = cbArray[i + 1];
                    }

                    numCB--;
                    cout << "Contact Books merged successfully!" << endl;
                    cout << endl;
                }

                else
                {
                    cout << "Invalid indices. Please try again." << endl;
                    cout << endl;
                }
            }

            else
            {
                cout << "Insufficient Contact Books to perform a merge. Create more Contact Books first." << endl;
                cout << endl;
            }
        }
        
        else if (choice == "5")
        {
            string lastName, firstName;
            
            cout << "*************************" << endl;
            cout << "* Select a Contact Book *" << endl;
            cout << "*************************" << endl;
            cout << endl;
            cout << "Enter Contact Book last name: " << endl;
            cin >> lastName;
            cout << "Enter Contact Book first name: " << endl;
            cin >> firstName;
            cout << endl;

            for (int i = 0; i < numCB; i++)
            {
                if (cbArray[i].getOwnerLastName() == lastName && cbArray[i].getOwnerFirstName() == firstName)
                {
                    while (true)
                    {
                        string choice;

                        cout << "************************" << endl;
                        cout << "***** Contact Menu *****" << endl;
                        cout << "************************" << endl;
                        cout << endl;
                        cout << "1. Add New Contact" << endl;
                        cout << "2. Delete Old Contact" << endl;
                        cout << "3. Search/Display Contact" << endl;
                        cout << "4. Update Contact" << endl;
                        cout << "5. Display Entire Contact List" << endl;
                        cout << "6. Exit" << endl;
                        cout << "Choice: ";
                        cin >> choice;
                        cout << endl;

                        if (choice == "1")
                        {
                            cin >> cbArray[i];
                        }
        
                        else if (choice == "2")
                        {

                            cbArray[i].deleteContact();
                        }
        
                        else if (choice == "3")
                        {   
                            int search;
                            string lastName, firstName;
                  
                            cout << "******************************" << endl;
                            cout << "***** Search In Progress *****" << endl;
                            cout << "******************************" << endl;
                            cout << endl;
                            cout << "Enter Last Name: ";
                            cin >> lastName;
                            cout << "Enter First Name: ";
                            cin >> firstName;
                            cout << endl;
                            search = cbArray[i].searchContact(lastName, firstName);
            
                            if (search == -1)
                            {
                                cout << "This Contact Does Not Exist " << endl;
                                cout << endl;
                            }

                            else
                            {
                                cout << "****************************************************" << endl;
                                cout << "***** Here Is The Contact Based On Your Search *****" << endl;
                                cout << "****************************************************" << endl;
                                cout << endl;
                                cout << "Contact #" << (search + 1) << endl;
                
                                //search function returns an index
                                //the returned index is passed into particularIndex function which returns a contact object
                                //output function is performed on returned contact object
                                (cbArray[i].getContactAtIndex(search)).output();
                                cout << endl;
                            }
                        }
        
                        else if (choice == "4")
                        {
                            cbArray[i].updateContactInfo();
                        }
    
                        else if (choice == "5")
                        {
                            cout << cbArray[i];
                        }
    
                        else if (choice == "6")
                        {
                            break;
                        }
    
                        else
                        {
                            cout << "Invalid Entry Please Try Again" << endl;
                            cout << endl;
                        }
                    }
                }

                else
                {
                    cout << "No existing Contact Book" << endl;
                    cout << endl;
                    break;
                }
            }
        }

        else if (choice == "6")
        {
            return 0;
        }

        else
        {
            cout << "Invalid entry please try again!" << endl;
            cout << endl;
        }
    }

    delete[] cbArray;

    return 0;
}