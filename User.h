#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include "Item.h"
using namespace std;

extern vector <Item> items;

int findItemIndex(int code){
    for (int i = 0; i < 10; i++){
        if(items[i].getCode() == code){
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

        void reset(){
            itemsIndex.clear();
            quantity = 0;
            price = 0;
        }

        void getItemCode(){
            int code, index = -1;
            cout << "Item code: ";
            cin >> code;
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
                     cout << setw(30) << left <<  "Subtotal" << setw(20) << right << price << endl << endl;
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
            double temp = price;
            price = round(price * 20.0) / 20.0;
            return price - temp;
        }

        void printItems(){
            cout << left << setprecision(2) << fixed
            << setw(5) << "Code" 
            << setw(25) << "Product Name"
            << setw(20) << right << "Unit Price(RM)" << endl;
            for (int i = 0; i < quantity; i++){
                cout 
                << setw(5) << left << items[itemsIndex[i]].icode 
                << setw(25) << left << items[itemsIndex[i]].description.substr(0,25) 
                << setw(20) << right << items[itemsIndex[i]].price << endl;
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
            << setw(30) << left << "Item Count" << setw(20) << right << quantity << endl
            << setw(30) << left << "Subtotal" << setw(20) << right << price + discount << endl
            << setw(30) << left << "Discount" << setw(20) << right << setprecision(2) << fixed << static_cast<double>(discount) << endl
            << setw(30) << left << "SST(6%)" << setw(20) << right << calcTax() << endl
            << setw(30) << left << "Rounding Adjustment" << setw(20) << right << rounding() << endl
            << setw(30) << left << "Total" << setw(20) << right << price << endl;

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
int User::totalItems = 0;
int User::totalTransactions = 0;

#endif