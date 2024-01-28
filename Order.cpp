#include "Order.h"
#include <iostream>
#include<fstream>
using namespace std;

int Order::orderCount = 1;
Order::Order(){}
Order::Order(int _CustomerID)
{
    OrderID = orderCount++;
    CustomerID = _CustomerID;
    itemCount = 0;
    TotalPrice = 0;
    OrderStatus = "False";
    
}
Order::~Order()
{
    // Perform any cleanup or deallocation of resources here
    // The destructor is automatically called when an Order object goes out of scope or is explicitly deleted
}

void Order::AddItem(MenuItem* item)
{
    this->ItemsOrdered[itemCount] = item;
    this->itemCount++;
}

// now is the function to remove the items from order list
void Order::RemoveItem(MenuItem* item)
{
    for (int i = 0; i < this->itemCount; i++)
    {
        if (ItemsOrdered[i]->getItemId() == item->getItemId())
        {
            for (int j = i; j < this->itemCount - 1; j++)
            {
                this->ItemsOrdered[j] = this->ItemsOrdered[j + 1];
            }
            break;
        }
    }
}

void Order::CalculateTotal()
{
    this->TotalPrice = 0;
    for (int i = 0; i < this->itemCount; i++)
    {
        this->TotalPrice += this->ItemsOrdered[i]->getItemPrice();
    }
    cout << "The Total price is as follows:" << TotalPrice << endl;
}

void Order::ConfirmOrder()
{
    OrderStatus = "True";
    cout << "Order confirmed. Order ID: " << OrderID << endl;
    SaveOrderToFile();
}

void Order::CancelOrder()
{
    OrderStatus = "False";
    cout << "Order canceled. Order ID: " << OrderID << endl;
}

// In Order class:

void Order::SaveOrderToFile() const
{
    // Save to "orders.txt"
    ofstream outputFile("orders.txt", ios::app);

    if (!outputFile.is_open())
    {
        cerr << "Error opening the file." << endl;
        return;
    }

    // Write order details to "orders.txt"
    outputFile << "Order ID: " << OrderID << endl;
    outputFile << "Order Status: " << OrderStatus << endl;

    // Write item details
    for (int i = 0; i < this->itemCount; i++)
    {
        outputFile << "Item " << i + 1 << ": " << ItemsOrdered[i]->getItemName() << " - $" << ItemsOrdered[i]->getItemPrice() << endl;
    }

    outputFile << "Total Price: $" << TotalPrice << endl;
    outputFile << "------------------------------------------" << endl;

    outputFile.close();

    // Save to "process_orders.txt"
    ofstream processOutputFile("process_orders.txt", ios::app);

    if (!processOutputFile.is_open())
    {
        cerr << "Error opening the process file." << endl;
        return;
    }

    processOutputFile << "Order ID: " << OrderID << endl;
    processOutputFile << "Order Status: " << OrderStatus << endl;

    // Write item details
    for (int i = 0; i < this->itemCount; i++)
    {
        processOutputFile << "Item " << i + 1 << ": " << ItemsOrdered[i]->getItemName() << " - $" << ItemsOrdered[i]->getItemPrice() << endl;
    }

    processOutputFile << "Total Price: $" << TotalPrice << endl;
    processOutputFile << "------------------------------------------" << endl;

    processOutputFile.close();

    cout << "Order details saved to both files." << endl;
}


void Order::OrderHistory()
{
    cout << "*******************************************************" << endl;
    ifstream file("orders.txt");

    if (file.is_open())
    {
        cout << "Order History:" << endl;
        string line;
        double totalOrdersPrice = 0.0;  // Variable to store the total price of all orders

        while (getline(file, line))
        {
            cout << line << endl;

            // Check if the line contains the total price information
            if (line.find("Total Price: $") != string::npos)
            {
                // Extract the total price value from the line and add it to the totalOrdersPrice
                double orderTotalPrice = stod(line.substr(line.find("$") + 1));
                totalOrdersPrice += orderTotalPrice;
            }
        }

        file.close();

        // Display the total price of all orders
        cout << "Total Price of All Orders: $" << totalOrdersPrice << endl;
    }
    else
    {
        cout << "Unable to open the file for reading order history." << endl;
    }
    cout << "*******************************************************" << endl;
}
void Order::ViewPaymentsFromFile()
{
    cout << "*******************************************************" << endl;
    ifstream file("orders.txt");

    ofstream paymentFile("payment.txt", ios::app); // Open payment.txt in append mode

    if (file.is_open() && paymentFile.is_open())
    {
        cout << "User Payments:" << endl;
        string line;
        double totalOrdersPrice = 0.0;  // Variable to store the total price of all orders

        while (getline(file, line))
        {
            cout << line << endl;

            // Check if the line contains the order ID and extract it
            if (line.find("Order ID: ") != string::npos)
            {
                int orderID = stoi(line.substr(line.find(": ") + 2));

                // Assuming user ID is the same as the order ID for simplicity
                int userID = orderID;

                // Extract the total price value from the "Total Price" line
                double orderTotalPrice = 0.0;
                while (getline(file, line) && line.find("Total Price: $") == string::npos)
                {
                    // Assuming the line contains item prices
                    if (line.find("$") != string::npos)
                    {
                        orderTotalPrice += stod(line.substr(line.find("$") + 1));
                    }
                }

                // Update totalOrdersPrice
                totalOrdersPrice += orderTotalPrice;

                // Display user's payment
                cout << "User ID: " << userID << " - Total Payment: $" << orderTotalPrice << endl;

                // Save user's payment to payment.txt
                paymentFile << "User ID: " << userID << " - Total Payment: $" << orderTotalPrice << endl;
            }
        }

        file.close();
        paymentFile.close();

        // Display the total price of all orders
        cout << "Total Price of All Orders: $" << totalOrdersPrice << endl;
    }
    else
    {
        cerr << "Error opening the file." << endl;
    }
}


