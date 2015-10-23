/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 22, 2015, 4:10 PM
 *      Purpose: Create Binary Files for Storage of Structures
 */

//System Libraries
#include <iostream>//I/O standard
#include <fstream>//file I/O
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
    float calc;
    //open a file for binary output
    fstream fout("Records.dat", ios::out | ios::binary);
    //Output 
    do{
        cout<<"Enter the following data:"<<endl;
        cout<<"Name: "<<endl;
        cin.getline(data.name, SIZE);
        cout<<"Total Games Played: "<<endl;
        cin>>data.ttlG;
        cout<<"Easy Games Won:"<<endl;
        cin.ignore();
        cin>>data.easyG;
        cout<<"Medium Games Won:"<<endl;
        cin>>data.mediG;
        cout<<"Hard Games Won:"<<endl;
        cin>>data.hardG;
        data.winR=((data.easyG + data.mediG + data.hardG)*100.0f/ data.ttlG);
        //write the contents to the file
        fout.write(reinterpret_cast<char*>(&data),sizeof(data));
        //ask for repeat
        cout<<"Would you like to enter another record?"<<endl;
        cin>>again;
        cin.ignore();
        
    }while(again=='Y'||again=='y');
    //close the file
    fout.close();
    //exit stage right
    return 0;
}