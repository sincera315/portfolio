#include "Customer.h"
#include "Order.h"
#include "Rating.h"
using namespace std;

Customer::Customer()
{
    for (int i = 0; i < 10; i++)
    {
        Table_reservation_arry[i] = false;
    }
    menu = new Menu();
    int choice1 = 0, choice2 = 0;
    int loop_variable = 1;
    cout << "You are now logged in as a customer. PRESS" << endl;
    cout << "" << endl;
    do {
        cout << "***********************************************" << endl;
        cout << "_______________________________________________" << endl;
        cout << "1 Student " << endl;
        cout << "2 Faculty" << endl;
        cout << "3 Nonfaculty" << endl;
        cout << "***********************************************" << endl;
        cout << "_______________________________________________" << endl;

        cin >> choice1;

        // Clear the input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // it is the choice menu for students
        if (choice1 == 1)
        {
            type = "student";
            do {
                cout << "*************************************************************" << endl;
                cout << "_____________________________________________________________" << endl;
                cout << "Enter the following number for the choice you want: " << endl;
                cout << "             " << "1 view menu  " << endl;
                cout << "             " << "2 place order" << endl;
                cout << "             " << "3 view_order_history" << endl;
                cout << "             " << "4 log_out" << endl;
                cout << "             " << "5 Table Reservation" << endl;
                cout << "             " << "6 Go back" << endl;
                cout << "_______________________________________________" << endl;
                cout << "***********************************************" << endl;
                cin >> choice2;

                switch (choice2)
                {
                    case 1:
                        ViewMenu();
                        break;
                    case 2:
                        PlaceOrder();
                        break;
                    case 3:
                        view_order_history();
                        break;
                    case 4:
                        log_out();
                        break;
                    case 5:
                        table_reservation();
                    case 6:
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (choice2 != 6);
        }
        // it is the choice menu for faculty.
        else if (choice1 == 2)
        {
            type = "faculty";
            do
            {
                cout << "_____________________________________________________________" << endl;
                cout << "Enter the following number for the choice you want: " << endl;
                cout << "             " << "1 view menu  " << endl;
                cout << "             " << "2 place order" << endl;
                cout << "             " << "3 view_order_history" << endl;
                cout << "             " << "4 log_out" << endl;
                cout << "             " << "5 Go back" << endl;
                cout << "_______________________________________________" << endl;
                cout << "***********************************************" << endl;
                cin >> choice2;

                switch (choice2)
                {
                    case 1:
                        ViewMenu();
                        break;
                    case 2:
                        PlaceOrder();
                        break;
                    case 3:
                        view_order_history();
                        break;
                    case 4:
                        log_out();
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (choice2 != 5);
        }
        // it is the choice menu for non faculty.
        else if (choice1 == 3)
        {
            type = "nonfaculty";
            do {
                cout << "************************************************************" << endl;
                cout << "_____________________________________________________________" << endl;
                cout << "Enter the following number for the choice you want: " << endl;
                cout << "             " << "1 view menu  " << endl;
                cout << "             " << "2 place order" << endl;
                cout << "             " << "3 view_order_history" << endl;
                cout << "             " << "4 log_out" << endl;
                cout << "             " << "5 Go back" << endl;
                cout << "_______________________________________________" << endl;
                cout << "************************************************************" << endl;

                cin >> choice2;

                switch (choice2)
                {
                    case 1:
                        ViewMenu();
                        break;
                    case 2:
                        PlaceOrder();
                        break;
                    case 3:
                        view_order_history();
                        break;
                    case 4:
                        log_out();
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (choice2 != 5);
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Do you want to continue? Enter 1 to continue, 0 to stop: ";
        cin >> loop_variable;

    } while (loop_variable == 1);
}

Customer::~Customer() {}

////first initializing so we can call the add remove and view functions

void Customer::ViewMenu() const
{
    this->menu->ViewMenu(type);
}


void Customer::PlaceOrder() const
{
    Order order1(this->userID);
    int choice = 0;
    int itemID;
    MenuItem* ptr = nullptr;

    do {
        cout << "************************************************************" << endl;
        cout << "_____________________________________________________________" << endl;
        cout << "Enter the following number for the choice you want: " << endl;
        cout << "             " << "1 Add Items  " << endl;
        cout << "             " << "2 View Order History" << endl;
        cout << "             " << "3 View Payment from File" << endl;
        cout << "             " << "4 Exit" << endl;
        cout << "_______________________________________________" << endl;
        cout << "************************************************************" << endl;

        cin >> choice;

        if (choice == 1) {
            // item is getting added
            cout << "Enter ItemID:";
            cin >> itemID;
            ptr = this->menu->getItemPtr(itemID);
            order1.AddItem(ptr);

            int next_move = -1;  // Declare next_move here

            do {
                int loop_runner = -1;
                // after adding an item we are letting the user if he wanna remove the item
                // or proceed to calculate the total

                cout << "             " << "1 add another item" << endl;
                cout << "             " << "2 Remove Item" << endl;
                cout << "             " << "3 Calculate Total" << endl;
                cout << "             " << "4 Exit" << endl;
                cin >> next_move;
                if (next_move == 1) {
                    cout << "Enter ItemID:";
                    cin >> itemID;
                    ptr = this->menu->getItemPtr(itemID);
                    order1.AddItem(ptr);
                }
                if (next_move == 2) {
                    cout << "Enter ItemID:";
                    cin >> itemID;
                    ptr = this->menu->getItemPtr(itemID);
                    order1.RemoveItem(ptr);
                }
                else if (next_move == 3) {
                    // Calculate total automatically when viewing
                    order1.CalculateTotal();
                    // After calculating the total, it will ask the user to confirm the order
                    cout << "do you wanna confirm order" << endl;
                    int confirmOrder_choice = 0; // Initialize confirmOrder_choice
                    int confirm_orderLooprunner = -1;
                    do {
                        cout << "             " << "1 Confirm Order" << endl;
                        cout << "             " << "2 Cancel Order" << endl;
                        cout << "             " << "3 Exit" << endl;
                        cin >> confirmOrder_choice;

                        if (confirmOrder_choice == 1)
                        {
                            order1.ConfirmOrder();
                            confirm_orderLooprunner = -1;

                        }
                        else if (confirmOrder_choice == 2)
                        {
                            order1.CancelOrder();
                            confirm_orderLooprunner = -1;
                        }
                        else if (confirmOrder_choice == 3) {
                            cout << "Exiting the order confirmation portion" << endl;
                            confirm_orderLooprunner = -1;
                        }
                        else {
                            cout << "Invalid choice. Try again." << endl;
                            // Add this line to initialize confirmOrder_choice
                        }
                    } while (confirm_orderLooprunner != -1);
                }
                else if (next_move == 4) {
                    cout << "exiting the add item portion" << endl;
                    next_move = 0;
                }
                else {
                    cout << "Invalid choice try again" << endl;
                    
                }
            } while (next_move != 0);
        }
        else if (choice == 2) {
            cout << "view order history" << endl;
            view_order_history();
        }
        else if (choice == 3) {
            cout << "view payment from file" << endl;
            order1.ViewPaymentsFromFile();
        }
        else if (choice == 4) {
            cout << "Exiting the order menu." << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}



void Customer::view_order_history() const
{
    Order order2(this->userID);
    cout << "Viewing order history for user: " << endl;
    order2.OrderHistory();
}

void Customer::log_out() const
{
    cout << "Logging out user: " << endl;
}

void Customer::rate() const
{
    Rating rating;
    rating.Rate();
    rating.SaveToFile();
}
void Customer::table_reservation() 
{
    cout << "we have 1-10 tables which one you wanna reserve?" << endl;
    int table_no = 0;
    cin >> table_no;
    if (Table_reservation_arry[table_no] == false)
    {
        cout << "booking is complete" << endl;
        Table_reservation_arry[table_no] = true;
    }
    else {
        cout << "Sorry this table is already reserved" << endl;
    }

}