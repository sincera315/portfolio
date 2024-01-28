#pragma once
#include<iostream>
#include "Menu.h"
#include "User.h"
#include "Order.h"
#include <fstream>
#include <iomanip>
class CafeStaff : public User
{
private:
    int choice;
    int view_choice;
    int add_choice;
    int remove_choice;
    int loop_variable;
protected:
    string customer_type;
public:
    // Other functions in CafeStaff
    CafeStaff();
    void ViewMenus();
    void AddToMenu();
    void RemoveFromMenu();
    void Choosecustomertype(int view_choice);
    void processOrders();
};
// its cafestaff.h