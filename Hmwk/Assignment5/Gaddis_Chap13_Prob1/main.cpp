/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 3rd, 2015, 3:10 PM
 *      Purpose: Make my first class
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries
#include "Date.h"
//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    Date userD;
    int d,m,y;
    //Prompt the user for inputs
    cout<<"What is the day?:"<<endl;
    cin>>d;
    cout<<"What is the month?: (1 for January, 2 for February...)"<<endl;
    cin>>m;
    cout<<"What is the year?:"<<endl;
    cin>>y;
    cout<<endl;
    //fill in class
    userD.setDay(d);
    userD.setMonth(m);
    userD.setYear(y);
    //Output 
    userD.display1();
    userD.display2();
    userD.display3();
    //Exit stage right
    return 0;
}