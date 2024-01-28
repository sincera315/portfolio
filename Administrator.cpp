#include "Administrator.h"
#include <iostream>
#include "FileManager.h"
using namespace std;
FileManager file;

Administrator::Administrator(Menu* menu) : adminMenu(menu) 
{
    
}

Administrator::~Administrator() 
{
    // Clean up allocated memory for adminMenu
    delete adminMenu;
}

void Administrator::ViewMenu() 
{
    this->adminMenu->ViewMenu("admin");
}

void Administrator::AddMenuItem()
{
    string Nameofitem=" ";
    int price= 0;
    int quantities= 0;
    string CustomType = " ";
    cout << "The name of item is: "<< endl;
    cin >> Nameofitem;
    cout << "The price of item is: $" << endl;
    cin >> price;
    cout << "The quantities are as follows: " << endl;
    cin >> quantities;
    cout << "The customer type is as follows: " << endl;
    cin>>CustomType;

    // Check if adminMenu is initialized
    if (this->adminMenu != nullptr)
    {
        // Call the Menu::AddMenuItem function
        this->adminMenu->AddMenuItem(Nameofitem, "", price, quantities, CustomType);
    }
    else
    {
        // Handle the case where adminMenu is not initialized
        cerr << "Error: Administrator menu not initialized." << endl;
    }
}

void Administrator::RemoveMenueItem() 
{
    int item_id;
    std::cout << "Enter Item ID you want to remove: ";
    std::cin >> item_id;
    this->adminMenu->RemoveItem(item_id);
}

void Administrator::ManageInventory() 
{
    int item_id, quantity;
    std::cout << "Enter Item ID to Update Stock: ";
    std::cin >> item_id;
    std::cout << "Enter Quantity to Update Stock (+ve to add and -ve to Subtract): ";
    std::cin >> quantity;
    this->adminMenu->UpdateStock(item_id, quantity);
}

void Administrator::ViewPaymentToFile()
{
    file.SavePaymentToFile();
}

void Administrator::ViewRatingsFromFile()
{
    file.ViewRatingsFromFile();
}

void Administrator::ViewOrdersFromFile()
{
    file.ViewOrdersFromFile();
}

void Administrator::ViewUsersFromFile()
{
    file.ViewUsersFromFile();
}

void Administrator::ViewMenuItemsFromFile()
{
    file.ViewMenuItemsFromFile();
}



void Administrator::runAdministratorMenu()
{
    int adminChoice = -1;

    do {
        cout << "**********************************************************" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "             " << "Administrator Menu:" << endl;
        cout << "             " << "1. View Menu" << endl;
        cout << "             " << "2. Add Menu Item" << endl;
        cout << "             " << "3. Remove Menu Item" << endl;
        cout << "             " << "4. Manage Inventory" << endl;
        cout << "             " << "5. View Rating from file" << endl;
        cout << "             " << "6. View Payments from file" << endl;
        cout << "             " << "7. View Ratings from file" << endl;
        cout << "             " << "8. View Orders from file" << endl;
        cout << "             " << "9. View Users from file" << endl;
        cout << "             " << "10. View Menu Items from file" << endl;
        cout << "             " << "0. Exit" << endl;
        cout << "**********************************************************" << endl;
        cout << "Enter your choice: ";
        cin >> adminChoice;

        switch (adminChoice) {
        case 1:
            ViewMenu();
            break;
        case 2:
            AddMenuItem();
            break;
        case 3:
            RemoveMenueItem();
            break;
        case 4:
            ManageInventory();
            break;
        case 5:
        {
            ViewRatingsFromFile();
            break;
        }
        case 6:
            ViewPaymentToFile();
            break;
        case 7:
            ViewRatingsFromFile();
            break;
        case 8:
            ViewOrdersFromFile();
            break;
        case 9:
            ViewUsersFromFile();
            break;
        case 10:
            ViewMenuItemsFromFile();
            break;
        case 0:
            cout << "Exiting Administrator menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (adminChoice != 0);
}
