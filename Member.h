#ifdef MEMBER_H
#define MEMBER_H

#include "User.h"
#include "Manager.h"
#include "Item.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Member : public User
{
private:
    int memberID;
    string memberName;
    int points;

public:
    Member(){
        setMemberID(0);
        setMemberName("");
        setPoints(0);
    }

    Member(int id, string name, int point){
        setMemberID(id);
        setMemberName(name);
        setPoints(point);
    }
    
    void setMemberID(int id){
        memberID = id;
    }

    int getMemberID() const {
        return memberID;
    }

    void setMemberName(string name){
        memberName = name;
    }

    string getMemberName(){
        return memberName;
    }

    void setPoints(int point){
        points = point;
    }

    int getPoints(){
        return points;
    }

    int calcDiscount() const {
        return points / 100;
    }
    void updateMemberPoints(){
        points %= 100;
    }
    void print(){
        printReceipt()
        cout << setw(30) << left << "Member point: " << getpoints() << endl; 

    }
};

