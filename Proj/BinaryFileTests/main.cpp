/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on October 21, 2015, 8:11 PM
 */

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

#include "PlayerData.h"
//Function Prototypes
PlyrDta getData();
void display(PlyrDta);
void outBin(PlyrDta );
void inBin(PlyrDta );
int main(int argc, char** argv) {
    //Declare struct array
//    PlyrDta hiScore[5]={};
//    //fill the structs
//    for(int i=0;i<5;i++){
//        hiScore[i]=getData();
//    }
//    //output to screen
//    for(int i=0;i<5;i++){
//        cout<<"Player "<<i+1<<endl;
//        display(hiScore[i]);
//        cout<<endl;
//    }
    PlyrDta test2;
    test2=getData();
    //output to file in binary
    outBin(test2);
    //input from file
    PlyrDta test;
    inBin(test);
    //display(test);
    //Exit stage right
    return 0;
}
//get data
PlyrDta getData(){
    PlyrDta temp; //temp structure
    string temp2;
    float temp3;
    unsigned short temp4,temp5,temp6;
    cout<<"What is the name"<<endl;
    getline(cin,temp2);
    cin.ignore();
    cout<<"What is the win rate?"<<endl;
    cin>>temp3;
    cout<<"What is the amount of easy games won?"<<endl;
    cin>>temp4;
    cout<<"What is the amount of medium games won?"<<endl;
    cin>>temp5;
    cout<<"What is the amount of hard games won?"<<endl;
    cin>>temp6;
    cin.ignore();
    //fill struct
    temp.name=temp2;
    temp.winRate=temp3;
    temp.easyG=temp4;
    temp.mediG=temp5;
    temp.hardG=temp6;
    //return temp structure
    return temp;
}
//display
void display(PlyrDta p){
    cout<<"Name: "<<p.name<<endl;
    cout<<"Win Rate: "<<p.winRate<<endl;
    cout<<"E Games won: "<<p.easyG<<endl;
    cout<<"M Games won: "<<p.mediG<<endl;
    cout<<"H Games won: "<<p.hardG<<endl;
}
//output to binary
void outBin(PlyrDta p){
    //open the file
    fstream fout("player1.dat",  ios::binary);
    //write to file
    cout<<"Writing the contents to a file..."<<endl;
    fout.write(reinterpret_cast<char *>(&p),sizeof(p));
    //close the file
    fout.close();
}
//input from binary
void inBin(PlyrDta p){
    //open the file
     fstream fin("player1.dat",  ios::binary);
    //read from file
    cout<<"Reading the contents of the file..."<<endl;
    fin.read(reinterpret_cast<char *>(&p),sizeof(p));
    //close the file
    fin.close();
}