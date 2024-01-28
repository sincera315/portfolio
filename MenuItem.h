#pragma once

#include<iostream>
#include<string>
using namespace std;
class MenuItem
{
public:
	int itemId;
	string itemName;
	string itemDescription;
	int price;
	int quantityInStock;
	string customerType;
	static int itemCount;
public:
	MenuItem(); // default constructor
	MenuItem(string _itemName, string _ItemDescription, int _price, int _quantityInStock, string _CustomerType);
	bool UpdateStock(int);
	friend ostream& operator<<(ostream& out, const MenuItem& obj) {
		cout << "Item ID: " << obj.itemId << endl;
		cout << "Item Name: " << obj.itemName << endl;
		cout << "Item Description: " << obj.itemDescription << endl;
		cout << "Price:" << obj.price << endl;
		return out;
	}
	string getCustomerType();
	int getItemId();
	void  setName(string);  // settee
	string getItemName();
	void setItemPrice(int);
	int getItemPrice();
	int getQuantity();
};
