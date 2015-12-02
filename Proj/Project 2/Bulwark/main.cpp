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
    //first object test
    Player player1();
    Player player2("Branden",500,30,"Badass");
    cout<<"Default Player"<<endl;
    //cout<<"name       :"<<player1.getName()<<endl;
    //cout<<"health     :"<<player1.getHel()<<endl;
    //cout<<"dps        :"<<player1.getDps()<<endl;
    //cout<<"archetype  :"<<player1.getArch()<<endl;
    //cout<<"weapon name:"<<player1.getWepn().getWNam()<<endl;
    //second object test
    cout<<endl;
    cout<<"Constructed Player"<<endl;
    cout<<"name       :"<<player2.getName()<<endl;
    cout<<"health     :"<<player2.getHel()<<endl;
    cout<<"dps        :"<<player2.getDps()<<endl;
    cout<<"archetype  :"<<player2.getArch()<<endl;
    cout<<"weapon name:"<<player2.getWepn().getWNam()<<endl;
    //Output 
    
    //Exit Stage Right
    return 0;
}