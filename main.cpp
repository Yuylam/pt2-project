#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

#include "Item.h"
#include "User.h"
#include "Member.h"
#include "Manager.h"

using namespace std;

vector<Item> items;

// to read members.txt and push into vector
void readMembers(vector<Member>& members, const string& filename)
{
    fstream memberFile(filename);
    if (!memberFile.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        exit;
    }
    
    string name;
    int memberCode, memberPoint;

    while (getline(memberFile, name)) 
    {
        memberFile >> memberCode >> memberPoint;
        memberFile.ignore(); // Ignore the remaining newline after memberPoint
        members.push_back(Member(name, memberCode, memberPoint));
    }
    memberFile.close();
}

// to read item.txt and push into vector
void readItems(vector<Item>& items, const string& filename)
{
    fstream itemFile(filename);
    if (!itemFile.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        exit;
    }
    
    int itemCode, quantity;
    string description;
    double price;

    while (itemFile >> itemCode) 
    {
        itemFile.ignore();
        getline(itemFile,description);
        itemFile >> price >> quantity;
        itemFile.ignore(); // Ignore the remaining newline after quantity
        items.push_back(Item(itemCode,description,price,quantity));

        //testing
        cout << "Read item - Code: " << itemCode << ", Description: " << description 
             << ", Price: " << price << ", Quantity: " << quantity << endl;
    }
    itemFile.close();
}


int main()
{
    // variable and vector declaration
    int memberID;
    vector<Member> members;
    vector<Item> items;

    // pass the vector and filename to read input file function
    readMembers(members, "C:/Users/Teh/Downloads/members.txt");
    readItems(items, "C:/Users/Teh/Downloads/items.txt");

    //testing
    // cout << "Items loaded:\n";
    // for (const auto& item : items) {
    //     cout << "Code: " << item.getCode() << ", Description: " << item.getDescription() 
    //          << ", Price: " << item.getPrice() << ", Quantity: " << item.getQuantity() << endl;
    // }
    
    // print the header and prompt user to enter the member ID
    cout << "**************************************************" << endl;
    cout << setw(38) << "The Perfect Grocery Shop" << endl;
    cout << "**************************************************" << endl;
    cout << "Member ID (Enter -1 if not a member): ";
    cin >> memberID;

    //testing
    cout << "Entered Member ID: " << memberID << endl;

    // case non-member
    if (memberID == -1) 
    {
        User user;
        cout << "Welcome!" << endl;
        user.getItemCode();
        user.printReceipt();
    }
    
    // case member
    else if (memberID > 0)
    {
        // initialize memberIndex to -1
        int memberIndex = -1;

        // loop through each member in the members vector
        for (size_t i = 0; i < members.size(); ++i)
        {
            // check if the member's ID == the memberID entered
            if (members[i].getMemberID() == memberID)
            {
                // if found, update memberIndex with the index of the memberID
                memberIndex = static_cast<int>(i);
                break;
            }
        }

        // after we found the memberID in vector, the numberIndex change, != -1
        if (memberIndex != -1)
        {
            members[memberIndex].getItemCode();
            members[memberIndex].updateMemberPoints();
            double discount = members[memberIndex].calcDiscount();
            members[memberIndex].print();
        }
        else
        {
            cout << "Member not found." << endl;
        }
    }

    // case manager
    else
    {
        Manager mana;
        mana.getChoice();
    }
    return 0;
}
