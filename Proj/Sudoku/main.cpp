/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 13th, 2015, 12:38 PM
 * Last edited: Oct 13,2015, 12:38 PM
 *      Purpose: Create a game of Sudoku
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>// string usage
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void prntTbl(int [][9], int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int DIMEN=9;
    char prompt1='0';
    //Greet the user and 
    cout<<"WELCOME TO SUDOKU"<<endl;
    cout<<"*******************"<<endl;
    cout<<endl;
    cout<<"Are you a returning player?"<<endl;
    cout<<"Enter in Y for yes or N for new player now:"<<endl;
    cin>>prompt1;
    //Create Table to be solved
    int table[DIMEN][DIMEN]={{4,3,5,2,6,9,7,8,1},
                             {6,8,2,5,7,1,4,9,3},
                             {1,9,7,8,3,4,5,6,2},
                             {8,2,6,1,9,5,3,4,7},
                             {3,7,4,6,8,2,9,1,5},
                             {9,5,1,7,4,3,6,2,8},
                             {5,1,9,3,2,6,8,7,4},
                             {2,4,8,9,5,7,1,3,6},
                             {7,6,3,4,1,8,2,5,9}
    
                                };
    //Output 
    prntTbl(table,9);
    //Exit stage right
    return 0;
}
//print the table
void prntTbl(int a[][9], int rC){
    cout<<"      A B C D E F G H I"<<endl;
    //cout<<"    _____________________"<<endl;
 for (int x=0;x<rC;x++){
    cout<<"    ";
    for (int y=0;y<rC;y++){
        if(y==0){
            if(x==0)cout<<"a ";
            if(x==1)cout<<"b ";
            if(x==2)cout<<"c ";
            if(x==3)cout<<"d ";
            if(x==4)cout<<"e ";
            if(x==5)cout<<"f ";
            if(x==6)cout<<"g ";
            if(x==7)cout<<"h ";
            if(x==8)cout<<"i ";
        }
        cout<<a[x][y] << " ";
        //if(((y+1)==3)||((y+1)==6))cout<<"| ";
    }
    cout<<endl;
    //if(((x+1)==3)||((x+1)==6))cout<<"    _____________________"<<endl;
 }
}