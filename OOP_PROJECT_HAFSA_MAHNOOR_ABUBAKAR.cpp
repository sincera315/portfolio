#include "User.h"
#include "Menu.h"
#include "Customer.h"
#include "Order.h"
#include "Rating.h"
#include "CafeStaff.h"
#include <iostream>
#include <limits>
#include "Administrator.h"
using namespace std;

int main() {
    // Aggregation
    Menu* globalMenu = new Menu(); // Dynamic allocation
    globalMenu->initializeFacultyMenu();
    globalMenu->initializeNonFacultyMenu();
    globalMenu->initializeStudentMenu();

   

    int choice = 0, select = 0;
    User newUser, loginUser;

    cout << "**********************************************************" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "             " << "Welcome to La Vida Cafe!" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "**********************************************************" << endl << endl;

    do {
        cout << "**********************************************************" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "             " << "Please choose an option:" << endl;
        cout << "             " << "1. Register as a new user" << endl;
        cout << "             " << "2. Login" << endl;
        cout << "             " << "0. Exit" << endl;
        cout << "**********************************************************" << endl;
        cout << "----------------------------------------------------------" << endl << endl;
        cout << "             " << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: {
                cout << "**********************************************************" << endl;
                cout << "----------------------------------------------------------" << endl;
                cout << "             " << "You are now registering as a new user to our cafe system: " << endl;
                string newUserName, newPassword, newUserType;
                cout << "Enter new username: ";
                cin >> newUserName;
                cout << "Enter new password: ";
                cin >> newPassword;
                cout << "----------------------------------------------------------" << endl;
                cout << "**********************************************************" << endl << endl;

                cout << "             " << "Please choose a user type:" << endl;
                cout << "             " << "1. Customer" << endl;
                cout << "             " << "2. Cafe Staff" << endl;
                cout << "             " << "3. Administrator" << endl;
                cout << "----------------------------------------------------------" << endl;
                cout << "**********************************************************" << endl << endl;
                cin >> select;

                switch (select) {
                case 1: {
                    newUserType = "Customer";
                    // Creating a Customer object
                    Customer c1;
                    break;
                }
                case 2: {
                    newUserType = "CafeStaff";
                    CafeStaff cafeStaff;
                    break;
                }
                case 3: {
                    newUserType = "Administrator";
                    Administrator ad(globalMenu);
                    ad.runAdministratorMenu();
                    break;
                }
                default: {
                    cout << "Invalid user type. Please try again." << endl;
                    continue;
                    // Go back to the main menu
                }
                }

                // Register the new user
                newUser.registerUser(newUserName, newPassword, newUserType);
                break;
            }
            case 2: {
                cout << "**********************************************************" << endl;
                cout << "----------------------------------------------------------" << endl;
                cout << "             " << "You are now logging in to our cafe system: " << endl;
                string enteredUserName, enteredPassword, enteredUsertype;
                cout << "             " << "Enter username for login: ";
                cin >> enteredUserName;
                cout << "             " << "Enter password for login: ";
                cin >> enteredPassword;
                cout << "----------------------------------------------------------" << endl;
                cout << "**********************************************************" << endl;
                cout << "             " << "Please choose a user type:" << endl;
                cout << "             " << "1. Customer" << endl;
                cout << "             " << "2. Cafe Staff" << endl;
                cout << "             " << "3. Administrator" << endl;
                cout << "----------------------------------------------------------" << endl;
                cout << "**********************************************************" << endl << endl;
                cin >> select;

                switch (select) 
                {
                    case 1:
                    {
                        enteredUsertype = "Customer";
                        break;
                    }
                    case 2: 
                    {
                        enteredUsertype = "CafeStaff";
                        break;
                    }
                    case 3: 
                    {
                        enteredUsertype = "Administrator";
                        break;
                    }
                    default: 
                    {
                        cout << "Invalid user type. Please try again." << endl;
                        continue;
                        // Go back to the main menu
                    }
                }
                // Test login
                if (loginUser.login(enteredUserName, enteredPassword, enteredUsertype)) 
                {
                    if (enteredUsertype == "Customer")
                    {
                        // Creating a Customer object
                        Customer c1;

                    }
                    else if (enteredUsertype == "CafeStaff")
                    {
                        // Creating a Cafestaff object
                        CafeStaff cafeStaff;
                    }
                    else if (enteredUsertype == "Administrator")
                    {
                        // Creating a Aministrator object
                        Administrator admin(globalMenu);
                        admin.runAdministratorMenu();
                    }
                }
                cout << "You have not registered as a user! You have to register first to login as one" << endl;
                break;
            }
        }

        // Clear the input buffer
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 0);

    // Deallocate memory for globalMenu
    delete globalMenu;

    return 0;
}
