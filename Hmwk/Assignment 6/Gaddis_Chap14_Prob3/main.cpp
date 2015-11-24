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
//string month[12]={"January","February","March","April","May","June",
//                  "July","August","September","October","November","December"};

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int user,temp;
    string month;
    char repeat;
    //Prompt the user for inputs
    cout<<"What month would you like to input: "<<endl;
    cin>>month;
    cout<<"What day would you like to input: "<<endl;
    cin>>user;
    //Output 
    DayOfYear output(month,user);
    cout<<endl;
    cout<<"The number of the year:"<<endl;
    output.print();
    cout<<endl;
    do{
        cout<<"To Decrement enter D, or to Increment enter I"<<endl;
        cout<<"E to exit:"<<endl;
        cin>>repeat;
        if(repeat=='D'||repeat=='d') output.operator --();
        else if(repeat=='I'||repeat=='i') output.operator ++();
        cout<<"DAY:"<<output.getDay()<<endl;
    }while(repeat!='E'&&repeat!='e');
    //Exit stage right
    return 0;
}