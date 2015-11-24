/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 8th, 2015, 3:10 PM
 *      Purpose: 
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries
#include "PersonalInfo.h"
//Global Constants

//Function Prototypes
void filInfo(PrsInfo &);
void displyI(PrsInfo);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare classes
    PrsInfo me;
    PrsInfo him;
    PrsInfo her;
    //fill the classes
    filInfo(me);
    filInfo(him);
    filInfo(her);
    cout<<endl;
    //output the classes
    displyI(me);
    displyI(him);
    displyI(her);
    //Exit stage right
    return 0;
}
void filInfo(PrsInfo &c){
    string name, phone, add;
    unsigned short age;
    //Prompt the user for inputs
    cout<<"What is the name: "<<endl;
    getline(cin,name);
    cout<<"What is the address: "<<endl;
    getline(cin,add);
    cout<<"What is the age: "<<endl;
    cin>>age;
    cout<<"What is the phone number: "<<endl;
    cin.ignore();
    getline(cin,phone);
    //input into class
    c.setName(name);
    c.setAdd(add);
    c.setAge(age);
    c.setPhn(phone);
}
void displyI(PrsInfo c){
    //Output 
    cout<<"Name    :"<<c.getName()<<endl;
    cout<<"Address : "<<c.getAdd()<<endl;
    cout<<"Age     : "<<c.getAge()<<endl;
    cout<<"Phone   : "<<c.getPhone()<<endl;
    cout<<endl;
}