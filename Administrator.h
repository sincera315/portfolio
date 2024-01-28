#pragma once
#include "Menu.h"
#include "User.h"
#include "FileManager.h"
// inherit from user 
class Administrator : private User
{
private:
	Menu* adminMenu;

public:
	Administrator(Menu*);
	void runAdministratorMenu();
	~Administrator();
	void ViewMenu();
	void AddMenuItem();
	void RemoveMenueItem();
	void ManageInventory();
	void ViewPaymentToFile();
	void ViewRatingsFromFile();
	void ViewOrdersFromFile();
	void ViewUsersFromFile();
	void ViewMenuItemsFromFile();
	


};