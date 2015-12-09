/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on November 27th, 2015, 8:28 PM
 *      Purpose: Bulwark (project #2, adventure game)
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>//string library
#include <cstdlib>//rand
using namespace std;

//User Libraries
#include "Player.h"//player library
#include "Weapon.h"//weapon library
#include "EnemyUnit.h"//enemy library
#include "CrapUnit.h"//weapon library

//Global Constants

//Function Prototypes
void newWave(Player &);
short pickMov(Player &);
bool duelEn(Player &);
bool duelEEn(Player &);
bool duelBos(Player &);
void pauseG();
//Execution Begins Here!
int main(int argc, char** argv) {
    //declare variables
    string cName;       //character name
    short archPic;      //archetype choice
    bool rep=false;     //repeat
    srand(static_cast<unsigned int>(time(0))); //set random seed
    //greet the user
    
    //set up player file
    cout<<"Before we begin, let's create your character."<<endl;
    cout<<"What would you like your avatar's name to be? (Ex. Alexander the Great)"<<endl;
    getline(cin,cName);
    cout<<"Next, we must choose an archetype."<<endl;
    do{
        rep=false;
        cout<<"Enter in 1 for Ranger, 2 for Warlock, 3 for a Paladin,"<<endl;
        cout<<"     or 4 for Beserker."<<endl;
        cin>>archPic;
        if(archPic>4||archPic<1){
            cout<<"Invalid Entry"<<endl;
            rep=true;
        }
    }while(rep==true);
    cin.ignore();
    //create player object
    Player user(cName,archPic);
    //start waves
    newWave(user);
    //Output Stats to File
    cout<<"Char name: "<<user.getName()<<endl;
    cout<<"char arch: "<<user.getArch()<<endl;
    cout<<"helth    : "<<user.getHel()<<endl;
    cout<<"dps      : "<<user.getDps()<<endl;
    cout<<"maxhlth  : "<<user.getMaxH()<<endl;
    cout<<"wep name : "<<user.getWepn().getWNam()<<endl;
    cout<<"wep type : "<<user.getWepn().getWTyp()<<endl;
    cout<<"waves    : "<<user.getWave()<<endl;
    //Exit Stage Right
    return 0;
}
//*******************************//
//           pause               //
//*******************************//
void pauseG(){
    string trash;
    cout<<"Enter to Continue..."<<endl;
    getline(cin,trash);
}
//*******************************//
//         new wave              //
//*******************************//
void newWave(Player &user){
    //declare variables
    unsigned short wCount=0;    //wave count
    bool cont=true;             //continue playing
    do{
        //enemy1
        if(cont) cont=duelEn(user);
        user.addHel(50);
        //enemy2
        if(cont) cont=duelEn(user);
        user.addHel(50);
        //elite enemy
        if(cont) cont=duelEEn(user);
        user.addHel(100);
        //enemy 4
        if(cont) cont=duelEn(user);
        user.addHel(50);
        //enemy 5
        if(cont) cont=duelEn(user);
        user.addHel(50);
        //boss
        if(cont) cont=duelBos(user);
        if(cont){
            user.addMaxH(25);
            user.addHel(100);
        }
        if(cont) wCount++;
    }while(cont);
    cout<<"You have fought bravely"<<endl;
    user.setWave(wCount);
}
//*******************************//
//        pick move              //
//*******************************//
short pickMov(Player &user){
    short cho;
    do{
        cout<<"Your Current Health: "<<user.getHel()<<endl;
        cout<<"1.Attack      : "<<user.getDps()<<" (damage)"<<endl;
        cout<<"2.Self-Heal   : "<<user.getSlfH()<<" (health)"<<endl;
        cout<<"3.Special     : "<<user.getSpec()<<" ("<<user.getSpC()<<" left)"<<endl;
        cin>>cho;
        if(cho==3 && user.getSpC()<=0) cho=6;
    }while(cho<1 || cho>3);
    return cho;
}
//*******************************//
//        duel enemy             //
//*******************************//
bool duelEn(Player &user){
    //declare variables
    short hitCh=0, userCho=0;
    //create enemy
    CrapUnit enemy;
    //introduce enemy
    cout<<"Before you stands an enemy "<<enemy.getName()<<endl;
    //find who hits first
    if(user.getWepn().getWBon()=="First Strike"){
        //user hits first
        hitCh=rand()%10+1;
        if(hitCh==1) cout<<"You missed your attack."<<endl;
        else enemy.takeDmg(user.getDps());
    }
    do{
        //enemy attacks player
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            hitCh=rand()%10+1;
            if(hitCh==1) cout<<"The enemy missed."<<endl;
            else user.takeDam(enemy.getDps());
        }
        //player attacks enemy
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            userCho=pickMov(user);
            hitCh=rand()%10+1;
            if(userCho==1){
               if(hitCh==1) cout<<"You weapon has missed. No damage done."<<endl;
               else enemy.takeDmg(user.getDps()); 
            }else if(userCho==2){
               user.healS(); 
            }else{
               enemy.setHlth(user.useSpec(enemy.getHlth())); 
            }
            
        }
    }while((user.getHel()>0) && (enemy.getHlth()>0)); //continue until one dead
    //check for user death
    if(user.getHel()==0){
        cout<<"You have died"<<endl;
        pauseG();
        return false;
    }
    else{
        cout<<"You have slain the enemy"<<endl;
        pauseG();
        return true;
    }
}
//*******************************//
//     duel elite enemy          //
//*******************************//
bool duelEEn(Player &user){
    cout<<"Elite fight goes here"<<endl;
}
//*******************************//
//         duel boss             //
//*******************************//
bool duelBos(Player &user){
    cout<<"Boss fight here"<<endl;
}