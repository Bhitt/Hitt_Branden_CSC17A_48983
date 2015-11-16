/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 15th, 2015, 5:05 PM
 *      Purpose: static string usage
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>//string usage
using namespace std;

//User Libraries
#include "DayOfYear.h"
//Global Constants
string month[12]={"January","February","March","April","May","June",
                  "July","August","September","October","November","December"};
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int user;
    //Prompt the user for inputs
    cout<<"What day would you like to input: (range 1 - 365)"<<endl;
    cin>>user;
    //Output 
    DayOfYear output(user);
    output.print();
    //Exit stage right
    return 0;
}