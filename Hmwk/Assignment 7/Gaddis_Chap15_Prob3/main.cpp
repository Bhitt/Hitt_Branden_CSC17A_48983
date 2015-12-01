/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 30, 2015, 11:46 PM
 *      Purpose: Inheritance practice
 */

//System Libraries
#include <iostream>

#include "Employee.h"
#include "ProductionWorker.h"
#include "TeamLeader.h"//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Create Object
    TeamLeader joe("Joe Wilkinson",26473,"11/30/14",2,12.50,500,40,38);
    //Output object 
    cout<<"Employee Details"<<endl;
    cout<<"Name                     : "<<joe.getName()<<endl;
    cout<<"Number                   : "<<joe.getNum()<<endl;
    cout<<"Hire Date                : "<<joe.getHire()<<endl;
    cout<<"Shift                    : "<<joe.getShft()<<endl;
    cout<<"Pay Rate ($/hr)          : $"<<joe.getPayR()<<endl;
    cout<<"Monthly Bonus            : $"<<joe.getMonB()<<endl;
    cout<<"Required Hours (training): "<<joe.getRHrs()<<endl;
    cout<<"Hours Attended           : "<<joe.getHrAt()<<endl;
    return 0;
}