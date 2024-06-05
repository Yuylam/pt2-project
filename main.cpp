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
vector<Member> members;

// to read members.txt and push into vector
void readMembers(vector<Member>& members, const string& filename)
{
    fstream memberFile(filename);
    if (!memberFile.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    
    string name;
    int memberCode, memberPoint;

    while (getline(memberFile, name)) 
    {
        memberFile >> memberCode >> memberPoint;
        memberFile.ignore();
        memberFile.ignore();
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
        exit(1);
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
    }
    itemFile.close();
}

int main()
{
    // variable and vector declaration
    int memberID;

    // pass the vector and filename to read input file function
    readMembers(members, "members.txt");
    readItems(items, "items.txt");
    
    do{
        // print the header and prompt user to enter the member ID
        cout << "**************************************************" << endl;
        cout << setw(36) << right << "The Perfect Grocery Shop" << endl;
        cout << "**************************************************" << endl;
        cout << "Member ID (Enter -1 if not a member): ";
        cin >> memberID;

        // case non-member
        if (memberID == -1) 
        {
            User user;
            cout << "Welcome!" << endl;
            user.getItemCode();
            user.printReceipt();
            cout << endl;
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
                    cout 
                    << "Welcome " << members[i].getMemberName() << "!" << endl
                    << "ID: " << members[i].getMemberID() << endl
                    << "Points: " << members[i].getPoints() << endl << endl;
                    break;
                }
            }

            // after we found the memberID in vector, the numberIndex change, != -1
            if (memberIndex != -1)
            {
                members[memberIndex].getItemCode();
                double discount = members[memberIndex].calcDiscount();
                members[memberIndex].updateMemberPoints();
                members[memberIndex].print(discount);
                cout << endl;
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
    } while(1);
    return 0;
}
