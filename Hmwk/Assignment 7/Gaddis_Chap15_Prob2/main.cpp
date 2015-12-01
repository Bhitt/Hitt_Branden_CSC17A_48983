/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 30, 2015, 11:10 PM
 *      Purpose: Inheritance practice
 */

//System Libraries
#include <iostream>

#include "Employee.h"
#include "ShiftSupervisor.h"//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Object
    ShiftSupervisor bob(45000,5000,"Billy Bob",37482,"11/30/15");
    
    //Output the object
    cout<<"Employee Details"<<endl;
    cout<<"Name          : "<<bob.getName()<<endl;
    cout<<"Number        : "<<bob.getNum()<<endl;
    cout<<"Hire Date     : "<<bob.getHire()<<endl;
    cout<<"Annual Salary : $"<<bob.getSal()<<endl;
    cout<<"Bonus         : $"<<bob.getBonus()<<endl;
    
    return 0;
}