/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 13th, 2015, 12:38 PM
 * Last edited: Oct 23,2015, 11:12 AM
 *      Purpose: Create a game of Sudoku
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>// string usage
#include <cstring>// string length and string cat
#include <fstream>// file I/O
using namespace std;

//User Libraries
#include "PlayerData.h"
//Global Constants

//Function Prototypes
short menu(short &);//menu for player
void instruc();//instructions on how to play
void showRec();//show the record of player on file
void entRec();//enter the record of player into a file
Records filHi(int);//fill the high score records
void showStr(Records *,int);//display the high scores
short newGame(short &);//start a new game
void filTbl(int [][9], int, short);//fill the table with the correct puzzle
void filKey(int [][9], int, short);//fill the key with the correct key
void prntTbl(int [][9], int, int &);//print sudoku table
void entNum(int [][9],int **,int);//enter a number into table
short assign(char);//assign a number to a char input
bool check(int [][9],int [][9],int,int &);//check table for win or errors
void gEdit(char [],char [],int);//greetings edit
int **findGiv(int [][9], int &);//find the givens of the current puzzle
bool isGiven(int **,int, int, int);//prevent editing givens
void destGiv(int **,int);//de-allocate the array for givens
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int GLENGTH=25;//greeting array length
    const int ILENGTH=9;//second part to be added
    char greet[GLENGTH]={'w','E','L','C','O','M','E',' ','T','O',' '};//greeting message
    char ing[ILENGTH]={'S','U','D','O','K','U'};
    short stats=0;//holds a value for win or loss
    //Greet the user and pull data
    gEdit(greet,ing,GLENGTH);//edit the greeting
    for(int i=0;i<GLENGTH;i++){
        cout<<greet[i];
    }
    cout<<endl;
    //send the player to the main menu
    menu(stats);
    //record player stats
    
    //Exit stage right
    return 0;
}
//*******menu*******//
short menu(short &stats){
    //declare variables
    char cho,repeat;
    short result=0;
    bool skip=false;
    const int CHAMPS=5;//top five players recorded
    //create an array of structures
    Records hiScore[CHAMPS]={{{'B','r','a','n','d','e','n',' ','H','i','t','t'},20,5,5,10,100.00},
                             {{'D','o','n','n','i','e',' ','D','a','r','k','o'},20,5,5,9,95.00},
                             {{'A','m','e','l','i','e',' ','P','o','u','l','a','i','n'},20,5,5,8,90.00},
                             {{'A','n','d','r','e','w',' ','R','y','a','n'},20,5,5,7,85.00},
                             {{'L','o','u',' ','C','o','s','t','e','l','l','o'},20,5,5,0,50.00}
    };
    //prompt for menu
    do{
        cout<<"MAIN MENU"<<endl;
        cout<<"Enter 1: Instructions on how to play"<<endl;
        cout<<"      2: View High Scores"<<endl;
        cout<<"      3: View Player Scores"<<endl;
        cout<<"      4: Start a game"<<endl;
        cout<<"      5: Exit the program"<<endl;
        cin>>cho;
        cout<<"********************************"<<endl;
        //menu
        switch(cho){
            case '1':{
                instruc();//game instructions
                break;
            }
            case '2':{
                //create high scores
//                for(int i;i<CHAMPS;i++){
//                    hiScore[i]=filHi(i);
//                }
                //display the high scores
                showStr(hiScore,CHAMPS);
                break;
            }
            case '3':{
                showRec();//show player record
                break;
            }
            case '4':{
                newGame(stats);//start a new game
                
                break;
            }
            case '5':{
                skip=true;
                repeat='X';
                break;
            }
            default:{
                cout<<"Invalid Entry"<<endl;
                skip=true;
                repeat='R';
                break;
            }
        }
        //prompt for repeat
        cout<<"********************************"<<endl;
        if(!skip){
            cout<<"Would you like to return to the menu or exit the program?"<<endl;
            cout<<"Enter in R to return to the menu or X for exit:"<<endl;
            cin>>repeat;
        }
    }while(repeat=='R'||repeat=='r');
    //exit the program
    return result;
}
//**********how to play***********************//
void instruc(){
    //explain the rules
    cout<<"There is only one simple rule:"<<endl;
    cout<<"Fill in the spaces so that each of the nine rows,"<<endl;
    cout<<"each of the nine columns, and each of the nine"<<endl;
    cout<<"3x3 sections contain all the numbers from 1 to 9."<<endl;
    cout<<endl;
    cout<<"There are 3 difficulties to choose from, and the only way to lose is to"<<endl;
    cout<<"either quit early or reach a total of 5 errors on the table before winning."<<endl;
    cout<<endl;
    cout<<"During the game you will be prompted for index of the row first"<<endl;
    cout<<"followed by the column, and then you input the number you believe"<<endl;
    cout<<"to be correct. Good Luck"<<endl;
    cout<<endl;
}
//************display the structure*******//
void showStr(Records *a,int s){
    char pause;
    cin.ignore();
    for(int i=0;i<s;i++){
        cout<<endl;
        cout<<"RANK "<<i+1<<endl;
        cout<<"Name             : "<<a[i].name<<endl;
        cout<<"Total Games      : "<<a[i].ttlG<<endl;
        cout<<"Easy Games Won   : "<<a[i].easyG<<endl;
        cout<<"Medium Games Won : "<<a[i].mediG<<endl;
        cout<<"Hard Games Won   : "<<a[i].hardG<<endl;
        cout<<"Win Rate         : "<<a[i].winR<<"%"<<endl;
        //pause
        cout<<"Press the Enter key to continue."<<endl;
        cin.get(pause);
    }
    cout<<endl;
}
//*******new Game*******//
short newGame(short &stats){
    //Declare Variables
    const int DIMEN=9;//table dimensions
    int errors=0;//counter for errors in puzzle
    bool win=false, loss=false;//win condition to exit loop
    short diff=0;//difficulty level
    int count=0;//counter for givens
    //create 2D array for table
    int table[DIMEN][DIMEN]={};
    int tableK[DIMEN][DIMEN]={};
    //find difficulty level
    cout<<"What difficulty would you like?"<<endl;
    cout<<"1) Easy  2) Medium  3)Hard"<<endl;
    cin>>diff;
    //Create Table to be solved
    filTbl(table,DIMEN,diff);
    //create key
    filKey(tableK,DIMEN,diff);
    //find the givens
    int **arrayG=findGiv(table,count);
    //Output
    do{
        prntTbl(table,DIMEN,errors);
        //user enters in number
        entNum(table,arrayG,count);
        //check for errors or win
        win=check(table,tableK,DIMEN,errors);
        if(errors>=5) loss=true;
        //output array of givens <-- testing purposes
    //    for(int x=0;x<count;x++){
    //        for(int y=0;y<2;y++){
    //            cout<<arrayG[x][y];
    //            if((y+1)%2==0)cout<<endl;
    //        }
    //    }
    }while(win==false && loss==false);
    //de-allocate the givens array
    destGiv(arrayG,2);
    //Exit stage right
    return stats;
}
//*******fill the table*******//
void filTbl(int a[][9],int rC, short fNum){
    //declare variables
    ifstream fin;
    //open file
    if(fNum==1) fin.open("puzzle1.txt");
    else if(fNum==2) fin.open("puzzle2.txt");
    else fin.open("puzzle3.txt");
    //fill table with files contents
    for(int x=0;x<rC;x++){
        for(int y=0;y<rC;y++){
            fin>>a[x][y];
        }
    }
    //close file
    fin.close();
}
//*******fill the key*******//
void filKey(int a[][9], int rC, short fNum){
    //declare variables
    ifstream fin;//file input
    //open file
    if(fNum==1) fin.open("key1.txt");
    else if(fNum==2) fin.open("key2.txt");
    else fin.open("key3.txt");
    //fill table with files contents
    for(int x=0;x<rC;x++){
        for(int y=0;y<rC;y++){
            fin>>a[x][y];
        }
    }
    //close file
    fin.close();
}
//*******print the table*******//
void prntTbl(int a[][9], int rC,int &err){
    cout<<"        A B C   D E F   G H I"<<endl;//format 
    cout<<endl;
    //cout<<"    _____________________"<<endl;
 for (int x=0;x<rC;x++){
    cout<<"    ";
    for (int y=0;y<rC;y++){//loop for format and display table
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
        if(a[x][y]==0) cout<<"_ ";
        else cout<<a[x][y] << " ";
        if(y==2||y==5)cout<<"  ";
        if((x==2&&y==8)||(x==5&&y==8))cout<<endl;
        //if(((y+1)==3)||((y+1)==6))cout<<"| ";
    }
    cout<<endl;
    //if(((x+1)==3)||((x+1)==6))cout<<"    _____________________"<<endl;
 }
    cout<<"Total Errors: ("<<err<<")"<<endl;
}
//*******enter a number into a table*******//
void entNum(int a[][9],int **b,int count){
    char rowIn='0',colIn='0';
    short row=10,col=10,guess=10;
    bool gChk=false;
    do{
        //input row
        do{
            cout<<"What is the letter of the row (ex: a)"<<endl;
            cin>>rowIn;
            if(!(isalpha(rowIn)))cout<<"Input needs to be a letter from a-i."<<endl;
            row=assign(rowIn);
            if(!(row>=0&&row<=9))cout<<"Invalid Entry"<<endl;
        }while(row<0||row>9);
        //input col
        do{
            cout<<"What is the letter of the column (ex: A)"<<endl;
            cin>>colIn;
            if(!(isalpha(colIn)))cout<<"Input needs to be a letter from A-I."<<endl;
            col=assign(colIn);
            if(!(col>=0&&col<=9))cout<<"Invalid Entry"<<endl;
        }while(col<0||col>9);
        gChk=isGiven(b,count,row,col);
        if(gChk==true){
            cout<<"Cannot edit a Given"<<endl;
            cout<<endl;
        }
    }while(gChk==true);
    //enter in the number to table
    do{
        cout<<"What is the number you wish to input (1-9)"<<endl;
        cin>>guess;
        if(guess<1||guess>9)cout<<"Invalid Entry"<<endl;
    }while(guess<1||guess>9);
    a[row][col]=guess;
}
//*******assign a number to a char*******//
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
//*******check the table for win or errors*******//
bool check(int a[][9],int b[][9],int rC,int &e){
    int ttlE=0;//total errors counter
    int winC=0;//win counter
    //loop to find errors
    for(int x=0;x<rC;x++){
        for(int y=0;y<rC;y++){
            if(a[x][y]!=b[x][y]){
                if(a[x][y]!=0) ttlE++;
            }
        }
    }
    e=ttlE;
    if(ttlE==0){//if no errors
        //loop and check for win
        for(int x=0;x<rC;x++){
            for(int y=0;y<rC;y++){
                if(a[x][y]==b[x][y]) winC++;
            }
        }
        if(winC==81)return true;
    } 
    return false;
}
//*******greeting's editor*******//
void gEdit(char a[],char b[],int c){
    //put both strings together
    if( c >=(strlen(a)+strlen(b)+1)){
        strcat(a,b);
    }else{
        cout<<"Greetings array is not large enough for both strings."<<endl;
    }
    //set the first letter to uppercase
    if(islower(a[0])){
        a[0]=toupper(a[0]);
    }else if(isupper(a[0])){
        //do nothing
    }else{
        cout<<"error"<<endl;
    }
}
//*******find the givens of the current puzzle*******//
int **findGiv(int p[][9],int &row){
    //declare variables
    int fill=0,col=2;
    //find how many givens
    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            if(p[x][y]!=0)row++;//rows = number of givens
        }
    }
    //cout<<"count : "<<row; <-- test purposes
    if(row>0){
        //create the number of rows
        int **array=new int*[row];
        //loop and create the columns
        for(int i=0;i<row;i++){
            array[i]=new int[col];
        }
        //fill the array
        for(int x=0;x<9;x++){
            for(int y=0;y<9;y++){
               if(p[x][y]!=0){
                   //cout<<"x: "<<x<<" y: "<<y<<endl; <-- test purposes
                   array[fill][0]=x;
                   array[fill][1]=y;
                   fill++;
                   //cout<<"fill: "<<fill<<endl; <-- test purposes
               } 
            }
        }
        //return the array
        return array;
    }else{
        //do nothing - no givens
        cout<<"No Givens in puzzle"<<endl;
    }
}
//*******check to make sure player isn't editing givens*******//
bool isGiven(int **b, int count, int row, int col){
    //declare variables
    bool stop=false;
    //loop to check givens
    for(int x=0;x<count;x++){
        if((row==b[x][0])&&(col==b[x][1])) stop=true;
    }
    //return the boolean
    return stop;
}
//*******de-allocate the array for givens*******//
void destGiv(int **a,int c){
    //Loop and destroy the columns
    for(int i=0;i<c;i++){
        delete [] a[i];
    }
    //Destroy the rows
    delete []a;
}
//*******show player record*******//
void showRec(){
    //Declare Variables
    Records data;
    char again;
    fstream fin;
    //Open the file in binary
    fin.open("Records.dat", ios::in | ios::binary);
    //test for errors
    if(!fin){
        cout<<"Error opening File. No such file exists."<<endl;
        return;
    }
    //read the first record
    fin.read(reinterpret_cast<char *>(&data),sizeof(data));
    //display while file isnt at the end
    while(!fin.eof()){
        //Display the record
        cout<<"Name               : "<<data.name<<endl;
        cout<<"Total Games Played : "<<data.ttlG<<endl;
        cout<<"Easy Games Won     : "<<data.easyG<<endl;
        cout<<"Medium Games Won   : "<<data.mediG<<endl;
        cout<<"Hard Games Won     : "<<data.hardG<<endl;
        cout<<"Win Rate           : "<<data.winR<<"%"<<endl;
        //wait for enter
        cout<<"Press the Enter key to continue."<<endl;
        cin.get(again);
        //read the next record from the file
        fin.read(reinterpret_cast<char *>(&data),sizeof(data));
    }
    fin.close();
    //Exit stage right
    
}
//******enter player record*********//
void entRec(){
    
}