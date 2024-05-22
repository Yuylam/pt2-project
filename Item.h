#ifndef ITEM_H
#define ITEM_H

//#include "User.h"
//#include "Member.h"

#include<iostream>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;

class Item {
    private:
        int code;
        string description;
        double price;
        int quantity;
    
    public:
        //Constructor
        Item(int _code = 0, string _description = "",double _price = 0.0, int _quantity = 0 ){
            code = _code;
            description = _description;
            price = _price;
            quantity = _quantity;
        }
        
        //function is used to compare with the user input
        int getCode(){
            return code;
        }


        void updatePrice(double newPrice){
            price = newPrice;
        }

        void updateQuantity(int newQuantity){
            quantity = newQuantity;
        }

        void display()const {
            cout << left << setw(10) << code
                 << left << setw(30) << description
                 << left << setw(10) << price
                 << left << setw(10) << quantity << endl;

        }

        //Distructor
        ~Item(){};

        //add item
};

#endif