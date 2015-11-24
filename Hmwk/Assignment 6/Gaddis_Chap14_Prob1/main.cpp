/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 8th, 2015, 8:10 PM
 *      Purpose: Translate numbers to whole numbers with a class
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries
#include "Numbers.h"
//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //declare
    int user=0;
    //Prompt the user for inputs
    do{
        cout<<"What number would you like to translate? (0 to 9999)"<<endl;
        cin>>user;
        if(user<0||user>9999)cout<<"Invalid entry : Out of range"<<endl;
    }while(user<0||user>9999);
    //Output 
    Numbers trans(user);
    trans.print();
    //Exit stage right
    return 0;
}