/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 23rd, 2015, 9:10 PM
 *      Purpose: create a NumDays class and overload the operators 
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries
#include "NumDays.h"
//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int hrs,hrs2;
    //Prompt the user for inputs
    cout<<"How many hours to start with?: "<<endl;
    cin>>hrs;
    cout<<"And for the second object?"<<endl;
    cin>>hrs2;
    //create object
    NumDays person(hrs);
    NumDays person2(hrs2);
    NumDays test(0);
    //Output 
    cout<<"Person 1"<<endl;
    cout<<"Hours: "<<person.getHrs()<<endl;
    cout<<"Days : "<<person.getDays()<<endl;
    cout<<endl;
    cout<<"Person 2"<<endl;
    cout<<"Hours: "<<person2.getHrs()<<endl;
    cout<<"Days : "<<person2.getDays()<<endl;
    cout<<endl;
    cout<<"Person 1 Hours - Person 2 Hours (overloaded -)"<<endl;
    test=person-person2;
    cout<<test.getHrs()<<endl;
    cout<<"Person 1 Hours + Person 2 Hours (overloaded +)"<<endl;
    //cout<<person.operator +(person2)<<endl;
    test=person+person2;
    cout<<test.getHrs()<<endl;
    cout<<endl;
    cout<<"Person 1 Hours after increment (overloaded ++)"<<endl;
    person.operator ++();
    cout<<"Hours : "<<person.getHrs()<<endl;
    cout<<"Days : "<<person.getDays()<<endl;
    cout<<endl;
    cout<<"Person 2 Hours after decrement (overloaded --)"<<endl;
    person2.operator --();
    cout<<"Hours : "<<person2.getHrs()<<endl;
    cout<<"Days : "<<person2.getDays()<<endl;
    cout<<endl;
    //Exit stage right
    return 0;
}