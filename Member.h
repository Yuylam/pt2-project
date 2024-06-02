#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
//#include "Manager.h"
//#include "Item.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Member : public User {
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

    Member(string name, int id, int point){
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

    string getMemberName()const{
        return memberName;
    }

    void setPoints(int point){
        points = point;
    }

    int getPoints()const{
        return points;
    }

    int calcDiscount() {
        int disc = points / 100;
        price -= disc;
        return disc;
    }
    void updateMemberPoints(){
        points %= 100;
        int newPoints = static_cast<int>(price);
        points += newPoints;
    }
    
    void print(int d){
        printReceipt(d);
        cout << setw(30) << left << "Member point: " << setw(15) << right << getPoints() << endl; 

    }
};

#endif