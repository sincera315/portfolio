#pragma once
#include <string>
#include <iostream>
#include "User.h"
using namespace std;

class Rating : public User
{
protected:
    static int RatingID;// Completed.
    int MenuItemID;// this will be taken from menuitem class.
    int CustomerID;// Completed
    int Score; //completed
    string  Comment; // Completed.
    string rating;//completed

public:
    Rating(); // Default constructor
    ~Rating(); // Destructor

    // Method to rate a menu item
    void Rate();// It requires a part of menuitem class which is Abu Bakars part.
    void SaveToFile();
    void ViewRatingsFromFile();
};
