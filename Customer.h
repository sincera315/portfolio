#pragma once
#include "User.h"
#include "Menu.h"
#include<string>
using namespace std;

class Customer : protected User
{
protected:
    string type;
public:
   
    Customer();
    ~Customer();
    void ViewMenu() const;
    void PlaceOrder() const;
    void view_order_history() const;
    void log_out() const;
    void rate() const;
    void table_reservation();
    bool Table_reservation_arry[10];
};