/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 29, 2015, 11:26 PM
 *      Purpose: Employee and Production Worker Classes (inheritance)
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries
#include "Employee.h"
#include "ProductionWorker.h"
//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Object
    ProductionWorker tim(2,8.25);
    //set variables
    tim.setName("Tim");
    tim.setNum(45320);
    tim.setHire("11/29/15");
    //Output 
    cout<<"Object : ProductionWorker tim"<<endl;
    cout<<"Name            : "<<tim.getName()<<endl;
    cout<<"Employee Number : "<<tim.getNum()<<endl;
    cout<<"Hire Date       : "<<tim.getHire()<<endl;
    cout<<"Shift           : "<<tim.getShft()<<endl;
    cout<<"PayRate         : $"<<tim.getPayR()<<endl;
    //Exit Stage right
    return 0;
}