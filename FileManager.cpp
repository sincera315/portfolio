#include "FileManager.h"
#include <iostream>

using namespace std;

void FileManager::SaveUserToFile()
{
    User user;

    cout << "*******************************************************" << endl;
    cout << "             Register as a new user" << endl;
    cout << "*******************************************************" << endl;

    string newUserName, newPassword, newUserType;

    cout << "Enter a new username: ";
    cin >> newUserName;

    cout << "Enter a new password: ";
    cin >> newPassword;

    cout << "Enter user type (Customer, CafeStaff, Administrator): ";
    cin >> newUserType;

    // Register the new user and save to file
    user.registerUser(newUserName, newPassword, newUserType);
}

void FileManager::SaveOrderToFile()
{
    Order order;

    cout << "*******************************************************" << endl;
    cout << "             Save Order to File" << endl;
    cout << "*******************************************************" << endl;

    // Save the order details to file
    order.SaveOrderToFile();
}

void FileManager::SaveRatingToFile()
{
    Rating rating;

    cout << "*******************************************************" << endl;
    cout << "             Save Rating to File" << endl;
    cout << "*******************************************************" << endl;

    // Save ratings to file
    rating.SaveToFile();

}
void FileManager::SaveMenuItemsToFile()
{
    Menu menu;

    cout << "*******************************************************" << endl;
    cout << "             Save Menuitems to File" << endl;
    cout << "*******************************************************" << endl;

    // Save ratings to file
    menu.SaveMenuItemsToFile();
}

void FileManager::SavePaymentToFile()
{
    Order order;

    cout << "*******************************************************" << endl;
    cout << "             View Payments and Save to File" << endl;
    cout << "*******************************************************" << endl;

    // View payments and save to file
    order.ViewPaymentsFromFile();
}
void FileManager::ViewRatingsFromFile()
{
    Rating rating;
    cout << "*******************************************************" << endl;
    cout << "                View Ratings from file                 " << endl;
    cout << "*******************************************************" << endl;
    //calling the specific function.
    rating.ViewRatingsFromFile();
}
void FileManager::ViewOrdersFromFile()
{
    Order order;

    cout << "*******************************************************" << endl;
    cout << "               View Orders from File" << endl;
    cout << "*******************************************************" << endl;

    // Read the order details from file
    order.OrderHistory();


}

void FileManager::ViewUsersFromFile()
{
    User info;

    cout << "*******************************************************" << endl;
    cout << "               View Users from File" << endl;
    cout << "*******************************************************" << endl;

    // Read the order details from file
    info.displayAllUsers();
}


void FileManager::ViewMenuItemsFromFile()
{
    Menu items;

    cout << "*******************************************************" << endl;
    cout << "               View Users from File" << endl;
    cout << "*******************************************************" << endl;

    // Read the order details from file
    items.ViewMenuItemsFromFile();
}

