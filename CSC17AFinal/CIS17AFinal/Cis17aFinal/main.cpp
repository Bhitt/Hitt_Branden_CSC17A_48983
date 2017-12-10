/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  Final
 * Created on December 14th, 2015 at 5:50 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "SavingsAccount.h"
#include "Employee.h"
//Global Constants

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
//Execution Begins Here
int main(int argc, char** argv) {
    //General Menu Format
    bool repeat=true;
    srand(static_cast<unsigned int>(time(0)));
    //Display the selection
    do{
        cout<<"Type 1 to solve problem 1"<<endl;
        cout<<"Type 2 to solve problem 2"<<endl;
        cout<<"Type 3 to solve problem 3"<<endl;
        cout<<"Type 4 to solve problem 4"<<endl;
        cout<<"Type 5 to solve problem 5"<<endl;
        cout<<"Type 6 to solve problem 6"<<endl;
        cout<<"Type 7 to Exit the program"<<endl;
        //Read the choice
        char choice;
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
            case '1':{
                cout<<"*****************************"<<endl;
                prob1();
                cout<<"*****************************"<<endl;
                    break;
                }
            case '2':{
                cout<<"*****************************"<<endl;
                prob2();
                cout<<"*****************************"<<endl;
                    break;
                }
            case '3':{
                cout<<"*****************************"<<endl;
                prob3();
                cout<<"*****************************"<<endl;
                    break;
                }
            case '4':{
                cout<<"*****************************"<<endl;
                prob4();
                cout<<"*****************************"<<endl;
                    break;
                }
            case '5':{
                cout<<"*****************************"<<endl;
                prob5();
                cout<<"*****************************"<<endl;
                    break;
                }
            case '6':{
                cout<<"*****************************"<<endl;
                prob6();
                cout<<"*****************************"<<endl;
                    break;
                }
            case '7':{
                cout<<"*****************************"<<endl;
                cout<<"Exit Stage Right."<<endl;
                repeat=false;
                cout<<"*****************************"<<endl;
                    break;
                }
            default:{
                        cout<<"Incorrect Menu Choice"<<endl;
                }      
        };
    }while(repeat==true); 
    return 0;
}
//***********************************//
//          problem 1                //
//***********************************//
void prob1(){
    char n=5;
    char rndseq[]={16,34,57,79,127};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++){
            a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++){
            cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}
//***********************************//
//          problem 2                //
//***********************************//
void prob2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=true;
    int count=0;
    ifstream infile;
    //I had to remove spaces from text file for it to correctly input into 
    //the array. I changed the beginning output accordingly.
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*15];
    char *ch2p=ch2;
    while(infile.get(*ch2)){
        cout<<*ch2;ch2++;
        count++;
        if(count%15==0) cout<<endl;
    }
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,15,column,ascending);
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            cout<<zc[i*15+j];
        }
        cout<<endl;
    }
    delete []zc;
    cout<<endl;
}
//***********************************//
//          problem 3                //
//***********************************//
void prob3(){
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    cout<<"Input Table: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Augmented Table"<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    
}
//***********************************//
//          problem 4                //
//***********************************//
void prob4(){
    cout<<"Entering problem number 4"<<endl;
    cout<<endl;
    SavingsAccount mine(-300);

	for(int i=1;i<=10;i++)
	{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));
	}
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
}
//***********************************//
//          problem 5                //
//***********************************//
void prob5(){
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    

    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    Mary.toString();
}
//***********************************//
//          problem 6                //
//***********************************//
void prob6(){
    cout<<"Conversion"<<endl;
    cout<<"Number : 0.125 base 10"<<endl;
    cout<<"       : 0.001 base 2"<<endl;
    cout<<"       : 0.1   base 8"<<endl;
    cout<<"       : 0.2   base 16"<<endl;
    cout<<endl;
    cout<<"Number : 0.3             base 10"<<endl;
    cout<<"       : 0.0100110011-   base 2"<<endl;
    cout<<"       : 0.231463146314- base 8"<<endl;
    cout<<"       : 0.4CCCC-        base 16"<<endl;
    cout<<"       : 0.0100110 01100110 01100110 00000000 HexFloat"<<endl;
    cout<<"       ->:  266666 x 2^0"<<endl;
    cout<<endl;
    cout<<"Number : 89.3                 base 10"<<endl;
    cout<<"       : 1011001.010011 0011- base 2"<<endl;
    cout<<"       : 131.23146314 6314-   base 8"<<endl;
    cout<<"       : 59.4CCC C-           base 16"<<endl;
    cout<<"       : 0.1011001 01001100 11001100 00000111 Hex Float"<<endl;
    cout<<"       ->:  594CCC x 2^7"<<endl;
    cout<<endl;
}