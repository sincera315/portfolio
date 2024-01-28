#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

int User::userCount = 1;

User::User() : menu(nullptr), userID(++userCount), userName(""), password(""), userType("")
{
}
User::~User(){}
bool User::login(const std::string& enteredUserName, const std::string& enteredPassword, std::string& enteredUserType) {
    bool loginSuccessful = false;
    ifstream userFile("users.txt");
    string line;
    string namePrefix = "Name: ";
    string passwordPrefix = "Password: ";

    while (getline(userFile, line)) {
        size_t namePos = line.find(namePrefix);
        if (namePos != string::npos) {
            // Found a line starting with "Name: "
            string userNameFromFile = line.substr(namePos + namePrefix.length());

            // Read the next line (Password)
            getline(userFile, line);

            size_t passwordPos = line.find(passwordPrefix);
            if (passwordPos != string::npos) {
                // Found a line starting with "Password: "
                string passwordFromFile = line.substr(passwordPos + passwordPrefix.length());

                // Manually remove leading and trailing whitespaces
                userNameFromFile = userNameFromFile.substr(userNameFromFile.find_first_not_of(" \t\n\r\f\v"));
                userNameFromFile = userNameFromFile.substr(0, userNameFromFile.find_last_not_of(" \t\n\r\f\v") + 1);

                passwordFromFile = passwordFromFile.substr(passwordFromFile.find_first_not_of(" \t\n\r\f\v"));
                passwordFromFile = passwordFromFile.substr(0, passwordFromFile.find_last_not_of(" \t\n\r\f\v") + 1);

                // Compare entered username and password with stored values
                if (userNameFromFile == enteredUserName && passwordFromFile == enteredPassword) {
                    loginSuccessful = true; // Set flag to indicate successful login
                    getline(userFile, line); // Move to the line containing "UserType: "
                    userType = line.substr(line.find("UserType: ") + 10);

                    // Check if the entered user type matches the stored user type
                    if (userType == enteredUserType) {
                        cout << "You have successfully logged in!" << endl;
                        //setting loginsuccessful to true
                        loginSuccessful = true;
                    }
                    else {
                        cout << "Invalid user type. Please try again." << endl;
                    }

                    break; // No need to continue searching if login successful
                }
            }
        }
    }

    return loginSuccessful;
}





void User::registerUser(const std::string& newUserName, const std::string& newPassword, const std::string& newUserType)
{
    // Set the user attributes
    userName = newUserName;
    password = newPassword;
    userType = newUserType;

    // Open the file in append mode
    ofstream userFile("users.txt", ios::app);

    // Check if the file is open
    if (userFile.is_open())
    {
        // Save user information to the file
        userFile << "Name:     " <<"    " << userName << endl;
        userFile << "Password: " <<"    " << password << endl;
        //m.change
        userFile << "Usertype: " << "    " << userType << endl;
        userFile << "___________________________________" << endl;
        // Close the file
        userFile.close();
        // Print a message or perform other actions indicating successful registration.
        cout << "User registered successfully!" << endl;
    }
    else
    {
        // Handle the case where the file could not be opened
        cout << "Error: Unable to open the user file." << endl;
    }
}

void User::displayAllUsers() const 
{
    ifstream userFile("users.txt");
    string line;

    cout << "All User Information:" << endl;
    cout << "---------------------" << endl;

    while (getline(userFile, line)) 
    {
        cout << line << endl;
    }

    userFile.close();
}
