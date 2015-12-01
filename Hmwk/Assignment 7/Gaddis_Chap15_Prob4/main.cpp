/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on December 1, 2015, 12:20 AM
 *      Purpose: Time Format
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries
#include "MilTime.h"
#include "Time.h"
//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Object
    MilTime test(900,30);
    //Output military time
    cout<<"Military Time: "<<endl;
    cout<<test.getMHour()<<" hours, "<<test.getSec()<<" seconds"<<endl;
    cout<<endl;
    //output standard time
    cout<<"Standard Time: "<<endl;
    cout<<test.getStHr()<<":"<<test.getMin()<<":"<<test.getSec()<<endl;
    return 0;
}