// Menu.h
#pragma once
#include "MenuItem.h"

class Menu
{
private:
    MenuItem** itemList;  // 2D pointer array 
    int itemCount;  // item counter 

public:
    Menu();
    ~Menu(); // Destructor to free resources
    void AddMenuItem();
    void AddMenuItem(string, string, int, int, string);
    void RemoveItem(int);
    void UpdateStock(int, int);
    void ViewMenu(string customerType);
    void initializeStudentMenu();
    void initializeFacultyMenu();
    void initializeNonFacultyMenu();
    MenuItem* getItemPtr(int);
    void SaveMenuItemsToFile();
    void ViewMenuItemsFromFile();
};
