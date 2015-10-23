/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 22, 2015, 4:30 PM
 *      Purpose: Read from Binary File
 */

//System Libraries
#include <iostream>//I/O standard
#include <fstream>//file I/O
#include <iomanip>//format
using namespace std;

//User Libraries
const int SIZE=30;
struct Records{
    char name[SIZE];//name
    short ttlG;//total games played
    short easyG;//easy games won
    short mediG;//medium games won
    short hardG;//hard games won
    float winR;//win rate
};
//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    Records data;
    char again;
    fstream fin;
    //Open the file in binary
    fin.open("Records.dat", ios::in | ios::binary);
    //test for errors
    if(!fin){
        cout<<"Error opening File. Program Aborting"<<endl;
        return 0;
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
        cout<<"Press the Enter key to see the next record."<<endl;
        cin.get(again);
        //read the next record from the file
        fin.read(reinterpret_cast<char *>(&data),sizeof(data));
    }
    cout<<"That's all the data in the file!"<<endl;
    fin.close();
    //Exit stage right
    return 0;
}