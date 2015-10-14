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
void prntTbl(int [][9], int, int &);//print sudoku table
void entNum(int [][9]);//enter a number into table
short assign(char);//assign a number to a char input
bool check(int [][9],int [][9],int,int &);//check table for win or errors
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int DIMEN=9;
    char prompt1='0';
    int errors=0;
    bool win=false;
    //Greet the user and 
    cout<<"WELCOME TO SUDOKU"<<endl;
    cout<<"*******************"<<endl;
    cout<<endl;
    cout<<"Are you a returning player?"<<endl;
    cout<<"Enter in Y for yes or N for new player now:"<<endl;
    cin>>prompt1;
    //Create Table to be solved
    int table[DIMEN][DIMEN]={{0,0,0,2,6,0,7,0,1},
                             {6,8,0,0,7,0,0,9,0},
                             {1,9,0,0,0,4,5,0,0},
                             {8,2,0,1,0,0,0,4,0},
                             {0,0,4,6,0,2,9,0,0},
                             {0,5,0,0,0,3,0,2,8},
                             {0,0,9,3,0,0,0,7,4},
                             {0,4,0,0,5,0,0,3,6},
                             {7,0,3,0,1,8,0,0,0}
                                };
    //answer key
    int tableK[DIMEN][DIMEN]={{4,3,5,2,6,9,7,8,1},
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
    prntTbl(table,DIMEN,errors);
    //user enters in number
    entNum(table);
    //check for errors or win
    win=check(table,tableK,DIMEN,errors);
    //output
    prntTbl(table,DIMEN,errors);
    //Exit stage right
    return 0;
}
//print the table
void prntTbl(int a[][9], int rC,int &err){
    cout<<"        A B C D E F G H I"<<endl;
    cout<<endl;
    //cout<<"    _____________________"<<endl;
 for (int x=0;x<rC;x++){
    cout<<"    ";
    for (int y=0;y<rC;y++){
        if(y==0){
            if(x==0)cout<<"a   ";
            if(x==1)cout<<"b   ";
            if(x==2)cout<<"c   ";
            if(x==3)cout<<"d   ";
            if(x==4)cout<<"e   ";
            if(x==5)cout<<"f   ";
            if(x==6)cout<<"g   ";
            if(x==7)cout<<"h   ";
            if(x==8)cout<<"i   ";
        }
        cout<<a[x][y] << " ";
        //if(((y+1)==3)||((y+1)==6))cout<<"| ";
    }
    cout<<endl;
    //if(((x+1)==3)||((x+1)==6))cout<<"    _____________________"<<endl;
 }
    cout<<"Total Errors: ("<<err<<")"<<endl;
}
//enter a number into a table
void entNum(int a[][9]){
    char rowIn='0',colIn='0';
    short row=10,col=10,guess=10;
    //input row
    do{
        cout<<"What is the letter of the row (ex: a)"<<endl;
        cin>>rowIn;
        row=assign(rowIn);
        if(!(row>=0&&row<=9))cout<<"Invalid Entry"<<endl;
    }while(row<0||row>9);
    //input col
    do{
        cout<<"What is the letter of the column (ex: A)"<<endl;
        cin>>colIn;
        col=assign(colIn);
        if(!(col>=0&&col<=9))cout<<"Invalid Entry"<<endl;
    }while(col<0||col>9);
    //enter in the number to table
    do{
        cout<<"What is the number you wish to input (1-9)"<<endl;
        cin>>guess;
        if(guess<1||guess>9)cout<<"Invalid Entry"<<endl;
    }while(guess<1||guess>9);
    a[row][col]=guess;
}
//assign a number to a char
short assign(char c){
    if(c=='A'||c=='a')return 0;
    else if(c=='B'||c=='b')return 1;
    else if(c=='C'||c=='c')return 2;
    else if(c=='D'||c=='d')return 3;
    else if(c=='E'||c=='e')return 4;
    else if(c=='F'||c=='f')return 5;
    else if(c=='G'||c=='g')return 6;
    else if(c=='H'||c=='h')return 7;
    else if(c=='I'||c=='i')return 8;
    else return 10;//for incorrect input
}
//check the table for win or errors
bool check(int a[][9],int b[][9],int rC,int &e){
    int ttlE=0;
    for(int x=0;x<rC;x++){
        for(int y=0;y<rC;y++){
            if(a[x][y]!=b[x][y]){
                if(a[x][y]!=0) ttlE++;
            }
        }
    }
    e=ttlE;
    if(ttlE==0)return true;
    else return false;
}
