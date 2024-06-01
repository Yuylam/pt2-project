#ifndef ITEM_H
#define ITEM_H

//#include "User.h"
//#include "Member.h"

#include<iostream>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;

//vector<Item> items;

class Item {
    private:
        int icode;
        string description;
        double price;
        int quantity;
        //vector<Item> items;
    
    public:
        //Constructor
        Item(int _icode = 0, string _description = "",double _price = 0.0, int _quantity = 0 ){
            icode = _icode;
            description = _description;
            price = _price;
            quantity = _quantity;
        }
    
        //function is used to compare with the user input
        int getCode()const{
            return icode;
        }

        string getDescription()const{
            return description;
        }

        double getPrice()const{
            return price;
        }

        int getQuantity()const{
            return quantity;
        }


        void updatePrice(double newPrice){
            price = newPrice;
        }

        void updateQuantity(int newQuantity){
            quantity = newQuantity;
        }

        void display()const {
            cout << left << setw(10) << icode
                 << left << setw(30) << description
                 << left << setw(10) << price
                 << left << setw(10) << quantity << endl;

        }

        //Distructor
        ~Item(){};

        //add item
       friend class User;
};

#endif