/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 8th, 2015, 4:40 PM
 *      Purpose: Retail Item class
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries
#include "RetailItem.h"
//Global Constants

//Function Prototypes
void display(RetailItem );
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    RetailItem item1("Jacket",12,59.95);
    RetailItem item2("Designer Jeans",40,34.95);
    RetailItem item3("Shirt",20,24.95);
    //Output 
    display(item1);
    display(item2);
    display(item3);
    //Exit stage right
    return 0;
}
void display(RetailItem c){
    cout<<"Description   : "<<c.getDesc()<<endl;
    cout<<"Units on hand : "<<c.getUnit()<<endl;
    cout<<"Price         : $"<<c.getPrce()<<endl;
    cout<<endl;
}