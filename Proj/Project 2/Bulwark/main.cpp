/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 27th, 2015, 8:28 PM
 *      Purpose: Bulwark (project #2, adventure game)
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>//string library

using namespace std;

//User Libraries
#include "Player.h"//player library
#include "Weapon.h"//weapon library

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //declare variables
    string cName,archee;    //character name /archetype
    short archPic;           //archetype choice
    bool rep=false;         //repeat
    int hltT,deeps;         //health total and dps
    //greet the user
    
    //set up player file
    cout<<"Before we begin, let's create your character."<<endl;
    cout<<"What would you like your avatar's name to be? (Ex. Alexander the Great)"<<endl;
    getline(cin,cName);
    cout<<"Next, we must choose an archetype."<<endl;
    do{
        cout<<"Enter in 1 for Ranger, 2 for Warlock, or 3 for a Paladin"<<endl;
        cin>>archPic;
        if(archPic>3||archPic<1){
            cout<<"Invalid Entry"<<endl;
            rep=true;
        }
    }while(rep==true);
    //set player values
    if(archPic==1) hltT=300,deeps=50,archee="Ranger";
    else if(archPic==2) hltT=250,deeps=70,archee="Warlock";
    else hltT=350,deeps=30,archee="Paladin";
    Player user(cName,hltT,deeps,archee);
    //output test
    
    //Output Stats to File
    
    //Exit Stage Right
    return 0;
}