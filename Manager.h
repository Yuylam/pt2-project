#ifndef MANAGER_H
#define MANAGER_H

#include "User.h"
#include "Member.h"
#include "Item.h"

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

extern vector<Member> members;
extern vector<Item> items;

void writeItems(string filename){
    fstream itemFile(filename);
    if (!itemFile.is_open())    {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    for(auto &item:items){
        itemFile 
        << item.getCode() << endl
        << item.getDescription() << endl
        << setprecision(2) << fixed << item.getPrice() << endl
        << item.getQuantity() << endl << endl;
    }
}

void writeMembers(string filename){
    fstream memberFile(filename);
    if (!memberFile.is_open())    {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    for(auto &member:members){
        memberFile 
        << member.getMemberName() << endl
        << member.getMemberID() << endl
        << member.getPoints() << endl << endl;
    }
}

class Manager{
    private: 
        int choice;

    public:
    
    //Constructor 
    Manager(int _choice = 0){ 
        choice = _choice;
    }

     void getChoice(){
            do{
                cout << "**************************************************" << endl
                     << setw(36) << right << "The Perfect Grocery Shop" << endl
                     << "**************************************************" << endl
                     << "\t1. Display Current Day Sales\n"
                     << "\t2. Display Member Information\n"
                     << "\t3. Display Item\n"
                     << "\t4. Update Items\n"
                     << "\t5. Add Items\n"
                     << "\t6. Quit Program\n"
                     << "\t7. Back to Home\n"
                     << "Choice: ";
                cin  >> choice;
                cout << endl;

                switch (choice){
                    case 1:
                        daySales();
                        break;
                    case 2:
                        displayMemberInfo();
                        break;
                    case 3:
                        displayItems();
                        break;
                    case 4:
                        updateItems();
                        break;
                    case 5:
                        addItem();
                        break;
                    case 6:
                        cout << "Saving information...\n";
                        writeItems("items.txt");
                        writeMembers("members.txt");
                        cout << "Exiting program...\n";
                        exit (0);
                    case 7:
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
            }while (choice != 7);
        }
    
    void daySales(){
        cout << "Total Sales: RM " << User::totalSales << endl;   //take it from user class
        cout << "Total Items: " << User::totalItems << endl;   //take it from user class
        cout << "Total Transactions: " << User::totalTransactions << endl;   //take it from user class
        cout << "Average Amount per Transaction: RM " << User::totalSales / User::totalTransactions << endl << endl;
    }

    void displayMemberInfo(){
        
            cout << left << setw(30) << "Member Name" 
                 << left << setw(8) << "ID"
                 << left << setw(8) << "Points" << endl;

        //for (auto iter = members.begin(); iter != members.end(); iter++){
        for (auto& member:members){
            cout << left << setw(30) << member.getMemberName().substr(0,29)    //take from member class
                 << left << setw(8) << member.getMemberID()    //take from member class
                 << left << setw(8) << member.getPoints() << endl;   //take from member class 
        }
    }

    void displayItems(){
        cout 
        << left << setw(5) << "Code"
        << left << setw(25) << "Description"
        << right << setw(10) << "Price"
        << right << setw(10) << "Quantity" << endl;
        for(auto &item:items){
            item.display();
        }
    }

    void updateItems(){
        int code;
        double newPrice;
        int newQuantity;
        bool found = false;

        cout << "Enter the code of the item to update: ";
        cin >> code;

        for (auto& item:items){
            if (item.getCode() == code && found == false){
                cout 
                << "Item: " << item.getDescription() << endl
                << "Price: " << item.getPrice() << endl
                << "Quantity: " << item.getQuantity() << endl;
                //update price
                cout << "Enter the new price: ";
                cin >> newPrice;
                item.updatePrice(newPrice);

                //update quantity
                cout << "Enter the new quantity: ";
                cin >> newQuantity;
                item.updateQuantity(newQuantity);
                cout << endl;

                //Display updated infomation
                cout 
                << left << setw(5) << "Code"
                << left << setw(25) << "Description"
                << right << setw(10) << "Price"
                << right << setw(10) << "Quantity" << endl;
                item.display();

                //update flag
                found = true;
                break;
            }
        }
    }

    void addItem(){
        int code, quantity;
        string description;
        double price;

        cout << "Enter the code of the new item: ";
        cin >> code;
        bool found = false;
        do{
            found = false;
            for (auto& item:items){
                if (item.getCode() == code){
                    found = true;
                    cout << "Item already exist\n";
                    cout << "Enter the code of the new item: ";
                    cin >> code;
                    break;
                }
            }
        } while(found);

        cout << "Enter the description of the new item: ";
        cin.ignore();
        getline(cin, description);

        cout << "Enter the price of the new item: ";
        cin >> price;

        cout << "Enter the quantity of the new item: ";
        cin >> quantity;

        items.push_back(Item(code, description, price, quantity));

    }
    //Destructor
    ~Manager(){};
};

#endif
