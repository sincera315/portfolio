#include <iostream>
#include "Menu.h"
#include "CafeStaff.h"
using namespace std;

CafeStaff::CafeStaff()
{
    // Ensure menu is initialized before using it
    this->menu = new Menu();
    //calling the initializing functions 
    this->menu->initializeFacultyMenu();
    this->menu->initializeStudentMenu();
    this->menu->initializeNonFacultyMenu();
    choice = 0;
    view_choice = 0;
    add_choice = 0;
    remove_choice = 0;
    loop_variable = 1;

    cout << "You are now logged in as a staff member. PRESS" << endl;
    cout << "" << endl;
    do {
        //cout << "Enter the type of " << endl;
        cout << "_________________" << endl;

        cout << "1 View Menu" << endl;
        cout << "2 Add items to menu" << endl;
        cout << "3 Remove menu items" << endl;
        cout << "4 process orders"    << endl;
        cout << " 0 Exit" << endl;
        cout << "_________________"   << endl;
        //empty line
        cout << "" << endl;

        cin >> choice;
        // Clear the input buffer
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 1)
        {
            // Assuming ViewMenus is a member function of CafeStaff
            ViewMenus();
        }
        else if (choice == 2)
        {
            // Assuming ViewMenus is a member function of CafeStaff
            AddToMenu();
        }
        else if (choice == 3)
        {
            // Assuming ViewMenus is a member function of CafeStaff
            RemoveFromMenu();
        }
        else if (choice == 4)
        {
            processOrders();
        }
        else if (choice == 0)
        {
            cout << "exiting the staff section" << endl;
            loop_variable = 0;
        }
        else
        {
            cout << "invalid choice try again" << endl;
        }
    } while (loop_variable == 1);
    //now to confirm the customertype in which user shall work.
    int loop_run = 1;
    do {


    } while (loop_run == 1);


    cout << "Do you want to continue? Enter 1 to continue, 0 to stop: ";
    cin >> loop_variable;
}

void CafeStaff::ViewMenus()
{
    int view_choice = 0;
    cout << "*-*You are now in menu section. PRESS" << endl;

    //variable which we are using to make loop run until user wanna exit
    int loop_run = 1;
    do {
        cout << "_________________" << endl;
        cout << "1 Faculty Menu" << endl;
        cout << "2 Student Menu" << endl;
        cout << "3 NonFaculty Menu" << endl;
        cout << "0 EXIT" << endl;
        cout << "_________________" << endl;
        cin >> view_choice;
        // Clear the input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (view_choice == 1 || (view_choice == 2) || (view_choice == 3))
        {
            Choosecustomertype(view_choice);
            this->menu->ViewMenu(customer_type);
        }
        else if (view_choice == 0)
        {
            cout << "exiting the view menu section" << endl;
            loop_run = 0;
        }
        else
        {
            cout << "invalid choice try again" << endl;
        }
    } while (loop_run == 1);
}

void CafeStaff::AddToMenu()
{
    int view_choice = 0;
    cout << "*-*You are now in item ADD section. PRESS" << endl;
    // variable which we are using to make loop run until user wanna exit
    int loop_run = 1;
    int add_choice;
    do {
        cout << "_________________" << endl;
        cout << "1 Faculty Menu ITEM ADD" << endl;
        cout << "2 Student Menu ITEM ADD" << endl;
        cout << "3 NonFaculty Menu ITEM ADD" << endl;
        cout << "0 EXIT" << endl;
        cout << "_________________" << endl;
        cin >> add_choice;
        // Clear the input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (add_choice == 1 || (add_choice == 2) || (add_choice == 3))
        {
            Choosecustomertype(add_choice);
            this->menu->AddMenuItem();
        }
        else if (add_choice == 0)
        {
            cout << "exiting the view menu section" << endl;
            loop_run = 0;
        }
        else
        {
            cout << "invalid choice try again" << endl;
        }
    } while (loop_run == 1);
}

void CafeStaff::RemoveFromMenu()
{
    int view_choice = 0, itemId = 0;
    // Variable used to make the loop run until the user wants to exit
    cout << "- You are now in item REMOVE section. PRESS" << endl;
    int loop_run = 1;
    do {
        cout << "_________________" << endl;
        cout << "1 Faculty Menu ITEM REMOVE" << endl;
        cout << "2 Student Menu ITEM REMOVE" << endl;
        cout << "3 NonFaculty Menu ITEM REMOVE" << endl;
        cout << "0 EXIT" << endl;
        cout << "_________________" << endl;

        cin >> remove_choice;
        // Clear the input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (remove_choice == 1 || (remove_choice == 2) || (remove_choice == 3))
        {
            Choosecustomertype(remove_choice);
            cout << "Enter the number of item you want to remove" << endl;
            cin >> itemId;
            this->menu->RemoveItem(itemId);
        }
        else if (remove_choice == 0)
        {
            cout << "exiting the view menu section" << endl;
            loop_run = 0;
        }
        else
        {
            cout << "invalid choice try again" << endl;
        }

    } while (loop_run != 0);
}
void CafeStaff::processOrders() {
    ifstream file("process_orders.txt");

    if (file.is_open()) {
        cout << "*******************************************************" << endl;
        cout << "Reading Process Orders:" << endl;
        string line;
        ofstream tempFile("temp_orders.txt");

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();

        cout << "*******************************************************" << endl;

        int orderId;
        cout << "Enter the Order ID you want to process: ";
        cin >> orderId;

        file.open("process_orders.txt");

        if (file.is_open()) {
            bool orderFound = false;
            while (getline(file, line)) {
                if (line.find("Order ID: " + to_string(orderId)) != string::npos) {
                    cout << "Order " << orderId << " processed." << endl;
                    orderFound = true;
                    // Skip lines until the next Order ID or the end of the file
                    while (getline(file, line) && line.find("Order ID:") == string::npos) {}
                }
                else {
                    tempFile << line << endl;
                }
            }

            file.close();
            tempFile.close();

            if (remove("process_orders.txt") != 0) {
                perror("Error removing file");
            }

            if (rename("temp_orders.txt", "process_orders.txt") != 0) {
                perror("Error renaming file");
            }

            if (!orderFound) {
                cout << "Order ID not found." << endl;
            }
        }
        else {
            cout << "Unable to open the file for reading process orders." << endl;
        }
    }
    else {
        cout << "Unable to open the file for reading process orders." << endl;
    }
}


//now adding the type of customer the user wants to help with:
void CafeStaff::Choosecustomertype(int view_choice)
{
    if (view_choice == 1)
    {
        customer_type = "faculty";
    }
    else if (view_choice == 2)
    {
        customer_type = "student";

    }
    else if (view_choice == 3)
    {
        customer_type = "nonfaculty";
    }
}