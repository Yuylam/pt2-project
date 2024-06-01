#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
//#include "Member.h"
#include "Item.h"
using namespace std;

extern vector <Item> items;

int findItemIndex(int code){
    cout << "Searching for item code: " << code << endl; //testing
    for (int i = 0; i < 10; i++){
        cout << "Comparing input code: " << code << " with item code: " << items[i].getCode() << endl;  //testing
        if(items[i].getCode() == code){
            cout << "Item found at index: " << i << endl; //testing
            return i;
        }
    }
    return -1;
}

class User{
    private:
        static double totalSales;
        static int totalItems;
        static int totalTransactions;

    protected:
        vector <int> itemsIndex;
        int quantity;
        double price;

    public:
        User(){
            quantity = 0;
            price = 0.0;
        }

        void getItemCode(){
            int code, index = -1;
            cout << "Item code: ";
            cin >> code;
            cout << "Entered code: " << code << endl; //testing
            while(code == -1){
                cout << "Invalid code\n";
                cout << "Enter the item code: ";
                cin >> code;
            }
            while(code != -1){
                index = findItemIndex(code);
                if(index == -1){
                    cout << "Item not found\n\n";
                    cout << "Enter -1 to proceed to payment\n";
                    cout << "Enter the item code: ";
                    cin >> code;
                    cout << endl;
                    if(code == -1) break;

                    index = findItemIndex(code);
                }
                if (index != -1){
                     quantity ++;
                     itemsIndex.push_back(index);
                     price += items[index].price;
                     items[index].quantity--;


                     printItems();
                     cout << setw(30) << left <<  "Subtotal" << setw(15) << right << price << endl << endl;
                }
               
                
                

                cout << "Enter -1 to proceed to payment\n";
                cout << "Enter the item code: ";
                cin >> code;
                cout << endl;
            }
        }

        double calcTax(){
            double tax = price * 0.06;
            price += tax;
            return tax;
        }

        double rounding(){
            int temp = price * 100;
            int remainder = temp % 5;
            double rounding;
            if (remainder <= 2)
                rounding = - remainder / 100.0;
            else
                rounding = remainder / 100.0;

            price += rounding;
            return rounding;
        }

        void printItems(){
            cout << left << setprecision(2) << fixed
            << setw(5) << "Code" 
            << setw(25) << "Product Name"
            << setw(15) << right << "Unit Price(RM)\n";
            for (int i = 0; i < quantity; i++){
                cout 
                << setw(5) << left << items[itemsIndex[i]].icode 
                << setw(25) << left << items[itemsIndex[i]].description.substr(0,25) 
                << setw(15) << right << items[itemsIndex[i]].price << endl;
            }
        }

        void printReceipt(int discount = 0){
            cout 
            << "**************************************************\n"
            << "            The Perfect Grocery Shop\n"
            << "           Jalan Computing, Taman UTM,\n"
            << "            Skudai, 12234 Johor Bahru\n"
            << "                No.Tel: 051233523\n"
            << "         Email: support@perfectgrocery.com\n"
            << "**************************************************\n";

            printItems();
            cout << endl
            << setw(30) << left << "Item Count" << setw(15) << right << quantity << endl
            << setw(30) << left << "Subtotal" << setw(15) << right << price + discount << endl
            << setw(30) << left << "Discount" << setw(15) << right << discount << endl
            << setw(30) << left << "SST(10%)" << setw(15) << right << calcTax() << endl
            << setw(30) << left << "Rounding Adjustment" << setw(15) << right << rounding() << endl
            << setw(30) << left << "Total" << setw(15) << right << price << endl;

            totalSales += price;
            totalItems += quantity;
            totalTransactions ++;
        }


        // Test Values
        double getTotalSales(){ return totalSales; };
        int getTotalItems() { return totalItems; };
        int getTotalTransactions() { return totalTransactions; };

        friend class Manager;
};

// Static member initialisation
double User::totalSales = 0;
double User::totalItems = 0;
int User::totalTransactions = 0;

#endif