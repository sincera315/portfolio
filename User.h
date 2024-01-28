#pragma once
#include <iostream>
#include"Menu.h"
#include <string>
using namespace std;

class User
{
protected:
    Menu* menu;
    static int userCount;
    int userID;
    string userName;
    string password;
    string userType;
public:
    User();
    ~User();
    bool login(const std::string& enteredUserName, const std::string& enteredPassword, std::string& enteredUserType);
    // Function to perform user registration using file handling
    void registerUser(const std::string& newUserName, const std::string& newPassword, const std::string& newUserType);
    void displayAllUsers() const;
};