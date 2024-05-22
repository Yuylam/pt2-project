#ifndef MANAGER_H
#define MANAGER_H

#include "User.h"
#include "Member.h"
#include "Item.h"

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;


class Manager{
    private: 
        int choice;
        vector<Member> members;
        vector<Item> items;

    public:
    
    //Constructor 
    Manager(int _choice = 0){ 
        choice = _choice;
    }

     void getChoice(){
            do{
                cout << "******************************************\n"
                     << "         The Perfect Grocery Shop         \n"
                     << "******************************************\n"
                     << " 1. Display Current Day Sales\n"
                     << " 2. Display Menber Information\n"
                     << " 3. Update Items\n"
                     << " 4. Quit Program\n"
                     << " Choice: ";
                cin  >> choice;

                switch (choice){
                    case 1:
                        daySales();
                        break;
                    case 2:
                        displayMemberInfo();
                        break;
                    case 3:
                        updateItems();
                        break;
                    case 4:
                        addItem();
                        break;
                    case 5:
                        cout << "Exiting program...\n";
                        break;

                    default:
                        cout << "Invalid choice. Please try again.\n";

                }
                // if (choice == 1){
                //    daySales();
                // }
                // else if (choice == 2){
                //     displayMemberInfo();
                // }
                // else if (choice == 3){
                //     updateItems();
                // }
            }while (choice < 6);
        }
    
    void daySales(){
        cout << "Total Sales: RM " << User::totSales << endl;   //take it from user class
        cout << "Total Sales: RM " << User::totItems << endl;   //take it from user class
        cout << "Total Sales: RM " << User::totTransactions << endl;   //take it from user class
        cout << "Average Amount per Transaction: RM " << User::totSales / User::totTransactions << endl;
    }

    void displayMemberInfo(){
        
            cout << left << setw(20) << "Member Name: " 
                 << left << setw(8) << "ID"  
                 << left << setw(8) << "Points";

        //for (auto iter = members.begin(); iter != members.end(); iter++){
        for (auto& member:members){
            cout << left << setw(20) << member.memberName    //take from member class
                 << left << setw(8) << member.memberID    //take from member class
                 << left << setw(8) << member.points;   //take from member class 
        }
    }

    void updateItems(){
        int code;
        double newPrice;
        int newQuantity;

        cout << "Enter the code of the item to update:";
        cin >> code;

        for (auto& item:items){
            if (item.getCode() == code){

                //update price
                cout << "Enter the new price: ";
                cin >> newPrice;
                item.updatePrice(newPrice);

                //update quantity
                cout << "Enter the new quantity: ";
                cin >> newQuantity;
                item.updateQuantity(newQuantity);

                //Display updated infomation
                item.display();
            }
            else 
                cout << "The code is not found.";
        }


    }

    void addItem(){
        int code, quantity;
        string description;
        double price;

        cout << "Enter the code of the new item:";
        cin >> code;

        cout << "Enter the description of the new item:";
        cin >> description;

        cout << "Enter the price of the new item:";
        cin >> price;

        cout << "Enter the quantity of the new item:";
        cin >> quantity;

        items.push_back(Item(code, description, price, quantity));

    }
    //Destructor
    ~Manager(){};
};

#endif
