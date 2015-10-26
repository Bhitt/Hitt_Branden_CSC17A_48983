/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 13th, 2015, 12:38 PM
 * Last edited: Oct 25,2015, 9:00 PM
 *      Purpose: Create a game of Sudoku
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>// string usage
#include <cstring>// string length and string cat
#include <fstream>// file I/O
using namespace std;

//User Libraries
#include "PlayerData.h"//holds structure 
//Global Constants

//Function Prototypes
void menu(Records &);//menu for player
void instruc();//instructions on how to play
void showRec(Records);//show the record of player on file
Records entRec(string);//enter the record of player into a structure
Records readRec();//read the record of a player from a file
void writRec(Records);//write the record of a player to a file
void showStr(Records *,int);//display the high scores
short newGame();//start a new game
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
    cout<<"********************************"<<endl;
    char prompt1='X';//is the player new or returning
    string prompt="What is your name?";//prompt to be passed
    Records user;//structure of user data initialization
    //Greet the user and pull data
    gEdit(greet,ing,GLENGTH);//edit the greeting
    for(int i=0;i<GLENGTH;i++){//loop and output greeting
        cout<<greet[i];
    }
    cout<<endl;
    //set up player file
    do{
        cout<<"Before we begin, are you a new player?"<<endl;
        cout<<"Enter in Y for yes or N for no:"<<endl;
        cin>>prompt1;//ask if the player is new
    }while((prompt1!='Y')&&(prompt1!='y')&&(prompt1!='N')&&(prompt1!='n'));
    if(prompt1=='Y'||prompt1=='y'){
        user=entRec(prompt);// if the player is new, fill the structure
        writRec(user);//create the file
    }else{
        ofstream fout;
        fout.open("user.dat", ios::in);
        if(fout.fail()){//if a returning player, check for file
            fout.close();
            cout<<"No previous user file exists."<<endl;
            cout<<"Creating a new file now...."<<endl;
            user=entRec(prompt);//if no file exists, then create one
            writRec(user);
        }else{
            fout.close();
            user=readRec();//if a file exists, fill structure with files contents
        }
    }
    //send the player to the main menu
    cout<<"********************************"<<endl;
    menu(user);
    //Exit stage right
    return 0;
}
//*******menu*******//
void menu(Records &user){
    //declare variables
    char cho,repeat;//choice and repeat
    bool skip=false;//boolean for menu skipping
    const int CHAMPS=5;//size of high score array
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
        cout<<"      3: View Player Stats"<<endl;
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
                //display the high scores
                showStr(hiScore,CHAMPS);
                break;
            }
            case '3':{
                showRec(user);//show player stats
                break;
            }
            case '4':{
                short stats=0;
                //start a new game
                user.ttlG++;
                stats=newGame();
                //record stats
                if(stats==1)user.easyG++;
                if(stats==2)user.mediG++;
                if(stats==3)user.hardG++;
                //write stats to file
                writRec(user);
                break;
            }
            case '5':{
                skip=true;//set to skip to end
                repeat='X';
                break;
            }
            default:{//account for default entry
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
            cout<<"********************************"<<endl;
        }
    }while(repeat=='R'||repeat=='r');
    //exit the program
}
//**********how to play***********************//
void instruc(){
    //explain the rules
    cout<<"There is only one simple rule:"<<endl;
    cout<<"Fill in the spaces so that each of the nine rows,"<<endl;
    cout<<"each of the nine columns, and each of the nine"<<endl;
    cout<<"3x3 sections contain all the numbers from 1 to 9."<<endl;
    cout<<endl;
    cout<<"There are 3 difficulty levels to choose from, and the only way to lose"<<endl;
    cout<<"is to reach a total of 5 errors on the table before winning."<<endl;
    cout<<endl;
    cout<<"During the game you will be prompted for index of the row first,"<<endl;
    cout<<"followed by the column, and then you input the number you believe"<<endl;
    cout<<"to be correct. Good Luck"<<endl;
    cout<<endl;
}
//************display the structure*******//
void showStr(Records *a,int s){
    char pause;//pause variable
    cin.ignore();
    for(int i=0;i<s;i++){//loop through array of structures
        cout<<endl;//display current structure
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
short newGame(){
    //Declare Variables
    const int DIMEN=9;//table dimensions
    int errors=0;//counter for errors in puzzle
    bool win=false, loss=false;//win condition to exit loop
    short diff=0;//difficulty level
    int count=0;//counter for givens
    short stats=0;//determined outcome for stats
    //create 2D array for table
    int table[DIMEN][DIMEN]={};
    int tableK[DIMEN][DIMEN]={};
    //find difficulty level
    cout<<"What difficulty would you like?"<<endl;
    cout<<"1) Easy  2) Medium  3)Hard"<<endl;
    cin>>diff;
    cout<<"********************************"<<endl;
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
    }while(win==false && loss==false);
    //after exiting current game
    if(win==true){//if win
        if(diff==1)stats=1;//tally which level diff is won
        if(diff==2)stats=2;
        if(diff==3)stats=3;
        cout<<endl;
        cout<<"****************************"<<endl;
        cout<<"*CONGRATS!! YOU HAVE WON!!!*"<<endl;//give congrats message
        cout<<"****************************"<<endl;
        cout<<endl;
    }else{
        cout<<"Too many errors. YOU LOSE"<<endl;
        stats=4;//if loss, record loss
    }
    //de-allocate the givens array
    destGiv(arrayG,2);
    //Exit stage right
    return stats;
}
//*******fill the table*******//
void filTbl(int a[][9],int rC, short fNum){
    //declare variables
    ifstream fin;
    //open file according to difficulty level
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
    //open file according to difficulty level
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
 }
    cout<<"Total Errors: ("<<err<<")"<<endl;//keep track of errors on table
}
//*******enter a number into a table*******//
void entNum(int a[][9],int **b,int count){
    //declare variables
    char rowIn='0',colIn='0';//variables to hold selection
    short row=10,col=10,guess=10;//variables to hold translated selection
    bool gChk=false;//boolean for isGiven
    do{
        //input row
        do{
            cout<<"What is the letter of the row (ex: a)"<<endl;
            cin>>rowIn;//select row (ex: a)
            if(!(isalpha(rowIn)))cout<<"Input needs to be a letter from a-i."<<endl;//input validation
            row=assign(rowIn);//assign number to choice (ex: a=0)
            if(!(row>=0&&row<=9))cout<<"Invalid Entry"<<endl;
        }while(row<0||row>9);
        //input col
        do{
            cout<<"What is the letter of the column (ex: A)"<<endl;
            cin>>colIn;//select col (ex: A)
            if(!(isalpha(colIn)))cout<<"Input needs to be a letter from A-I."<<endl;//input validation
            col=assign(colIn);//assign a number to choice (ex: A=0)
            if(!(col>=0&&col<=9))cout<<"Invalid Entry"<<endl;
        }while(col<0||col>9);
        gChk=isGiven(b,count,row,col);//check to make sure its not a given
        if(gChk==true){
            cout<<"Cannot edit a Given"<<endl;
            cout<<endl;
        }
    }while(gChk==true);
    //enter in the number to table
    do{
        cout<<"What is the number you wish to input (1-9)"<<endl;
        cin>>guess;//enter in guess
        if(guess<1||guess>9)cout<<"Invalid Entry"<<endl;//input validation
    }while(guess<1||guess>9);
    a[row][col]=guess;//enter in guess into table
}
//*******assign a number to a char*******//
short assign(char c){
    if(c=='A'||c=='a')return 0;//'A' returns 0 and so on...
    else if(c=='B'||c=='b')return 1;
    else if(c=='C'||c=='c')return 2;
    else if(c=='D'||c=='d')return 3;
    else if(c=='E'||c=='e')return 4;
    else if(c=='F'||c=='f')return 5;
    else if(c=='G'||c=='g')return 6;
    else if(c=='H'||c=='h')return 7;
    else if(c=='I'||c=='i')return 8;
    else return 10;//default case for incorrect input
}
//*******check the table for win or errors*******//
bool check(int a[][9],int b[][9],int rC,int &e){
    int ttlE=0;//total errors counter
    int winC=0;//win counter
    //loop to find errors
    for(int x=0;x<rC;x++){
        for(int y=0;y<rC;y++){
            if(a[x][y]!=b[x][y]){
                if(a[x][y]!=0) ttlE++;//if error is found, incriment error
            }
        }
    }
    e=ttlE;//set reference variable = current errors
    if(ttlE==0){//if no errors
        //loop and check for win
        for(int x=0;x<rC;x++){
            for(int y=0;y<rC;y++){
                if(a[x][y]==b[x][y]) winC++;//counter for correct answers
            }
        }
        if(winC==81)return true;//if all correct, return true
    } 
    return false;//if not finished, return false
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
        //fill the array with givens positions
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
        cout<<"No Givens in puzzle"<<endl;//error case
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
//******enter player record*********//
Records entRec(string p){
    //declare struct
    Records temp;
    cout<<p<<endl;//prompt for name in record
    cin.ignore();
    cin.getline(temp.name,30);
    temp.ttlG=0;//set all other values to zer0
    temp.easyG=0;
    temp.mediG=0;
    temp.hardG=0;
    temp.winR=0.00;
    //return struct
    return temp;
}
//******write player record to a file******//
void writRec(Records p){
    //open file
    fstream fout;
    fout.open("user.dat", ios::out || ios::binary);
    //write to file
    fout.write(reinterpret_cast<char *>(&p),sizeof(p));
    //close file
    fout.close();
}
//*******read player record from file*******//
Records readRec(){
    //create structure
    Records temp;
    //open file
    fstream fin;
    fin.open("user.dat", ios::in || ios::binary);
    //read file into structure
    fin.read(reinterpret_cast<char *>(&temp),sizeof(temp));
    //close file
    fin.close();
    //return struct
    return temp;
}
//*********show player record*********//
void showRec(Records p){
    //calculate win rate
    float winRate;
    if(p.ttlG>0)winRate = ((p.easyG)+(p.mediG)+(p.hardG))*100.0f/ p.ttlG;
    else winRate=0;
    //output all of structure
    cout<<"Name               : "<<p.name<<endl;
    cout<<"Total Games Played : "<<p.ttlG<<endl;
    cout<<"Easy Games Won     : "<<p.easyG<<endl;
    cout<<"Medium Games Won   : "<<p.mediG<<endl;
    cout<<"Hard Games Won     : "<<p.hardG<<endl;
    cout<<"Win Rate           : "<<winRate<<"%"<<endl;
    
}