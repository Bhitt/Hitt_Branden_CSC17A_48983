/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 8th, 2015, 5:10 PM
 *      Purpose: create an Inventory class
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Inventory.h"//I/O standard
//Global Constants

//Function Prototypes
void display(Inventory);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    Inventory def;
    Inventory con(33857,54.95,5);
    //display defaulted constructor
    cout<<"Defaulted Constructor"<<endl;
    display(def);
    //display constructor
    cout<<"Constructor #2"<<endl;
    display(con);
    //exit stage right
    return 0;
}
void display(Inventory c){
    cout<<"Item Number : "<<c.getItem()<<endl;
    cout<<"Quantity    : "<<c.getQuan()<<endl;
    cout<<"Cost        : $"<<c.getCost()<<endl;
    cout<<"Total Cost  : $"<<c.getTCst()<<endl;
    cout<<endl;
}