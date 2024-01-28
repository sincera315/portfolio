#pragma once
#include "Order.h"
#include "Rating.h"
#include "User.h"
class FileManager
{
public:
	void SaveUserToFile();
	void SaveOrderToFile();
	void SaveRatingToFile();
	void SaveMenuItemsToFile();
	void SavePaymentToFile();// this does both reading and writing the files.
	// now these are the files which will be viewed in the Administrator file.
	void ViewRatingsFromFile();
	void ViewOrdersFromFile();
	void ViewUsersFromFile();
	void ViewMenuItemsFromFile();
};

