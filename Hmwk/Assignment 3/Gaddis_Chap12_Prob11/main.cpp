/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 5th, 2015, 5:10 PM
 *      Purpose: Write a structure to store data
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>//
#include <fstream>// file i/o
using namespace std;

//User Libraries
#include "ComData.h"
//Global Constants

//Function Prototypes
void getData(ComData);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    fstream file;
    //open the file in binary mode
    file.open("CompanyData.txt", ios::binary | ios::out);
    //check to see if file opened
    if(!file){
        cout<<"Error opening file. Program aborting"<<endl;
        return 0;
    }
    //Prompt the user for inputs
    cout<<"This program stores the quarterly sale of each division of a company"<<endl;
    cout<<"Let's start with the North division"<<endl;
    //declare more variables
    ComData div1q1,div1q2,div1q3,div1q4;//division 1 (North)
    ComData div2q1,div2q2,div2q3,div2q4;//division 2 (South)
    ComData div3q1,div3q2,div3q3,div3q4;//division 3 (East)
    ComData div4q1,div4q2,div4q3,div4q4;//division 4 (West)
    //North
    div1q1.name="North";
    div1q1.qtr=1;
    div1q2.name="North";
    div1q2.qtr=2;
    div1q3.name="North";
    div1q3.qtr=3;
    div1q4.name="North";
    div1q4.qtr=4;
    //South
    div2q1.name="South";
    div2q1.qtr=1;
    div2q2.name="South";
    div2q2.qtr=2;
    div2q3.name="South";
    div2q3.qtr=3;
    div2q4.name="South";
    div2q4.qtr=4;
    //East
    div3q1.name="East";
    div3q1.qtr=1;
    div3q2.name="East";
    div3q2.qtr=2;
    div3q3.name="East";
    div3q3.qtr=3;
    div3q4.name="East";
    div3q4.qtr=4;
    //West
    div4q1.name="West";
    div4q1.qtr=1;
    div4q2.name="West";
    div4q2.qtr=2;
    div4q3.name="West";
    div4q3.qtr=3;
    div4q4.name="West";
    div4q4.qtr=4;
    //Output 
    getData(div1q1);
    getData(div1q2);
    getData(div1q3);
    getData(div1q4);
    getData(div2q1);
    getData(div2q2);
    getData(div2q3);
    getData(div2q4);
    getData(div3q1);
    getData(div3q2);
    getData(div3q3);
    getData(div3q4);
    getData(div4q1);
    getData(div4q2);
    getData(div4q3);
    getData(div4q4);
    //output to file
    file.write(reinterpret_cast<char *>(&div1q1),sizeof(div1q1));
    file.write(reinterpret_cast<char *>(&div1q2),sizeof(div1q2));
    file.write(reinterpret_cast<char *>(&div1q3),sizeof(div1q3));
    file.write(reinterpret_cast<char *>(&div1q4),sizeof(div1q4));
    file.write(reinterpret_cast<char *>(&div2q1),sizeof(div2q1));
    file.write(reinterpret_cast<char *>(&div2q2),sizeof(div2q2));
    file.write(reinterpret_cast<char *>(&div2q3),sizeof(div2q3));
    file.write(reinterpret_cast<char *>(&div2q4),sizeof(div2q4));
    file.write(reinterpret_cast<char *>(&div3q1),sizeof(div3q1));
    file.write(reinterpret_cast<char *>(&div3q2),sizeof(div3q2));
    file.write(reinterpret_cast<char *>(&div3q3),sizeof(div3q3));
    file.write(reinterpret_cast<char *>(&div3q4),sizeof(div3q4));
    file.write(reinterpret_cast<char *>(&div4q1),sizeof(div4q1));
    file.write(reinterpret_cast<char *>(&div4q2),sizeof(div4q2));
    file.write(reinterpret_cast<char *>(&div4q3),sizeof(div4q3));
    file.write(reinterpret_cast<char *>(&div4q4),sizeof(div4q4));
    //close the file
    file.close();
    //exit stage right
    return 0;
}
//get data
void getData(ComData p){
    do{
        cout<<"What are the quarterly sales for "<<p.name<<" quarter "<<p.qtr<<endl;
        cin>>p.qtSales;
    }while(p.qtSales<0);
}