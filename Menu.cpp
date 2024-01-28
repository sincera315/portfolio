// Menu.cpp
#include "Menu.h"
#include<iostream>
# include<fstream>
using namespace std;
//updated version.
Menu::Menu()
{
    this->itemList = new MenuItem * [1000];
    for (int i = 0; i < 1000; i++)
    {
        this->itemList[i] = nullptr; // Initialize each pointer to null
    }

    this->itemCount = 0;
    this->initializeStudentMenu();
    this->initializeFacultyMenu();
    this->initializeNonFacultyMenu();
}


Menu::~Menu() {
    for (int i = 0; i < itemCount; ++i)
    {
        delete itemList[i];
    }
    delete[] itemList;
}

void Menu::ViewMenu(string userType)
{
    if (userType == "student")
    {
        cout << "Now displaying the student specific menu:" << endl;
        for (int i = 0; i < this->itemCount; i++)
        {
            if (this->itemList[i]->getCustomerType() == userType)
            {
                cout << "*****************************************" << endl;
                cout << *this->itemList[i];
            }
        }
    }
    else if (userType == "nonfaculty")
    {
        cout << "Now displaying the nonfaculty specific menu:" << endl;
        for (int i = 0; i < this->itemCount; i++)
        {
            if (this->itemList[i]->getCustomerType() == userType)
            {
                cout << "*****************************************" << endl;
                cout << *this->itemList[i];
            }
        }
    }
    else if (userType == "faculty")
    {
        cout << "Now displaying the faculty specific menu:" << endl;
        for (int i = 0; i < this->itemCount; i++)
        {
            if (this->itemList[i]->getCustomerType() == userType)
            {
                cout << "*****************************************" << endl;
                cout << *this->itemList[i];
            }
        }
        //then putting usertype == student we will redisplay it.
        cout << "As faculty can view student menu as well Therefore, Now displaying the student specific menu:" << endl;
        userType = "student";
        for (int i = 0; i < this->itemCount; i++)
        {
            if (this->itemList[i]->getCustomerType() == userType)
            {
                cout << "*****************************************" << endl;
                cout << *this->itemList[i];
            }
        }
        //then putting usertype == nonfaculty we will redisplay it.
        cout << "As faculty can view Nonfaculty menu as well Therefore, Now displaying the student specific menu:" << endl;
        userType = "nonfaculty";
        for (int i = 0; i < this->itemCount; i++)
        {
            if (this->itemList[i]->getCustomerType() == userType)
            {
                cout << "*****************************************" << endl;
                cout << *this->itemList[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < this->itemCount; i++)
        {
            cout << "*****************************************" << endl;
            cout << *this->itemList[i];
            if (userType == "admin" || userType == "staff") {

                cout << "Available Quantity:" << this->itemList[i]->getQuantity() << endl;
                cout << "Customer Type:" << this->itemList[i]->getCustomerType() << endl;
            }
        }
    }
    cout << endl;
}

void Menu::AddMenuItem() {
    if (this->itemCount < 1000)
    {
        this->itemList[this->itemCount] = new MenuItem();
        this->itemCount++;
    }
    else {
        cout << "Cannot add more items. Maximum capacity reached." << endl;
    }
}

void Menu::AddMenuItem(string _itemName, string _itemDescription, int _price, int _quantityInStock, string _customerType) {
    if (this->itemCount < 1000)
    {
        this->itemList[this->itemCount] = new MenuItem(_itemName, _itemDescription, _price, _quantityInStock, _customerType);
        this->itemCount++;
    }
    else
    {
        cout << "Cannot add more items. Maximum capacity reached." << endl;
    }
}

void Menu::RemoveItem(int itemId) {
    bool itemFound = false;

    for (int i = 0; i < this->itemCount; i++) {
        if (this->itemList[i]->getItemId() == itemId) {
            delete this->itemList[i];

            // Shift the remaining elements to remove the gap
            for (int j = i; j < this->itemCount - 1; j++) {
                this->itemList[j] = this->itemList[j + 1];
            }

            itemFound = true;
            break;
        }
    }

    if (itemFound) {
        cout << "Item removed successfully" << endl;
        itemCount--; // Decrementing
    }
    else {
        cout << "Item not found" << endl;
    }
}

MenuItem* Menu::getItemPtr(int itemID) {
    for (int i = 0; i < this->itemCount; i++) {
        if (this->itemList[i]->getItemId() == itemID) {
            return this->itemList[i];
        }
    }
    cout << "Item not found!" << endl;
    return nullptr;
}

void Menu::UpdateStock(int itemID, int quantity) {
    bool itemFound = false;
    for (int i = 0; i < this->itemCount; i++) {
        if (this->itemList[i]->getItemId() == itemID) {
            this->itemList[i]->UpdateStock(quantity);
            itemFound = true;
            break;
        }
    }
    if (!itemFound) {
        cout << "Item ID not found!" << endl;
    }
}
void Menu::initializeStudentMenu() {

    this->AddMenuItem("Bbq Pizza", "", 1200, 5, "student");
    this->AddMenuItem("Zinger Burger", "", 360, 7, "student");
    this->AddMenuItem("Tikka Boti", "", 200, 3, "student");
    this->AddMenuItem("Chow Mein", "", 360, 1, "student");
    this->AddMenuItem("Loaded Fries", "", 150, 6, "student");
    this->AddMenuItem("Afghani Burger", "", 180, 6, "student");
}
void Menu::initializeFacultyMenu() {
    this->AddMenuItem("Pizza", "", 800, 5, "faculty");
    this->AddMenuItem("Zinger Burger", "", 360, 7, "faculty");
    this->AddMenuItem("Tikka Boti", "", 200, 3, "faculty");
    this->AddMenuItem("Shrimp Fried Rice", "", 360, 1, "faculty");
    this->AddMenuItem("Loaded Fries", "", 150, 6, "faculty");

}
void Menu::initializeNonFacultyMenu() {

    this->AddMenuItem("Pizza", "", 800, 5, "nonfaculty");
    this->AddMenuItem("Zinger Burger", "", 360, 7, "nonfaculty");
    this->AddMenuItem("Tikka Boti", "", 200, 3, "nonfaculty");
    this->AddMenuItem("Shrimp Fried Rice", "", 360, 1, "nonfaculty");
    this->AddMenuItem("Loaded Fries", "", 150, 6, "nonfaculty");
    this->AddMenuItem("Chocolate Cake", "", 220, 6, "nonfaculty");
    this->AddMenuItem("Egg Fried Rice", "", 330, 6, "nonfaculty");
}

void Menu::SaveMenuItemsToFile() 
{
    ofstream outFile("menu.txt", ios::app);

    if (!outFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        outFile << "Item ID: " << itemList[i]->getItemId() << endl;
        outFile << "Item Name: " << itemList[i]->getItemName() << endl;
        outFile << "Price: $" << itemList[i]->getItemPrice() << endl;
        outFile << "Quantity In Stock: " << itemList[i]->getQuantity() << endl;
        outFile << "Customer Type: " << itemList[i]->getCustomerType() << endl;
        outFile << "------------------------------------------" << endl;
    }

    outFile.close();
}

void Menu::ViewMenuItemsFromFile()
{
    ifstream inFile("menu.txt", ios::in);

    if (!inFile.is_open())
    {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;  // Print each line (you can modify this part based on your needs)
    }

    inFile.close();
    cout << "All menu item details saved to file: " << endl;
}


