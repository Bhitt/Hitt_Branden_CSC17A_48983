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
#include <fstream>//file i/o
#include <cstring>//strcpy
using namespace std;

//User Libraries
#include "Player.h"//player library
#include "Weapon.h"//weapon library
#include "EnemyUnit.h"//enemy library
#include "CrapUnit.h"//crap unit library
#include "CrapUnitElite.h"//crap unit elite library
#include "ModerateUnit.h"//moderate unit library
#include "ModerateUnitElite.h"//moderate unit elite library
#include "BossUnit.h"//boss unit library
#include "SimpleVector.h"//my vector library/template
#include "PlayerData.h"//vector library
#include "Unit.h"//unit abstract class
//Global Constants

//Function Prototypes
void newWave(Player &);     //new wave of enemies
short pickMov(Player &);    //pick char move
bool duelEn(Player &);      //duel enemy
bool duelEEn(Player &);     //duel elite enemy
bool duelMEn(Player &);     //duel moderate enemy
bool duelMEE(Player &);     //duel moderate elite enemy
bool duelBos(Player &);     //duel boss
void statBon(Player &);     //stat bonus for player
void pauseG();              //pause the game
void writeRec(PlayerData ,string);  //write records to a file
void writeHi(PlayerData);   //write record to highscore file
void readHi();              //read highscores to player
PlayerData retPD(Player);   //returns a structure from data
void vecFun();              //vector function
//Execution Begins Here!
int main(int argc, char** argv) {
    //declare variables
    string cName;       //character name
    short archPic=5,hi=0;//archetype choice
    bool rep=false;     //repeat
    srand(static_cast<unsigned int>(time(0))); //set random seed
    //greet the user
    cout<<"*****************************************************************"<<endl;
    cout<<"| Quickly soldier, we need your help to defend the gates!       |"<<endl;
    cout<<"| Cthulhu has brought a heinous army to destroy all of mankind! |"<<endl;
    cout<<"| Fight as long as you can and leave none standing!             |"<<endl;
    cout<<"*****************************************************************"<<endl;
    //set up player file
    cout<<"Before you go, what was your name? (Ex. Alexander the Great)"<<endl;
    getline(cin,cName);
    cout<<"Finally, what is your archetype."<<endl;
    do{
        rep=false;
        cout<<"Enter in 1 for Ranger: "<<endl;
        cout<<"         2 for Warlock:"<<endl;
        cout<<"         3 for Paladin:"<<endl;
        cout<<"         4 for Beserker:"<<endl;
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
    cout<<"God speed, "<<user.getArch()<<" "<<user.getName()<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    newWave(user);
    //set player data
    PlayerData records;
    records=retPD(user);
    //Output Stats to Player
    cout<<endl;
    cout<<"Character Name : "<<user.getName()<<endl;
    cout<<"Archetype      : "<<user.getArch()<<endl;
    cout<<"Health         : "<<user.getHel()<<endl;
    cout<<"Damage         : "<<user.getDps()<<endl;
    cout<<"Maximum Health : "<<user.getMaxH()<<endl;
    cout<<"Weapon Name    : "<<user.getWepn().getWNam()<<endl;
    cout<<"Weapon Bonus   : "<<user.getWepn().getWBon()<<endl;
    cout<<"Waves Completed: "<<user.getWave()<<endl;
    cout<<endl;
    cout<<endl;
    //write out data to txt
    writeRec(records,cName);
    //write out data to dat
    writeHi(records);
    //read in data for output
    do{
        cout<<"Would you like to view the High Scores?"<<endl;
        cout<<"Enter in 1 for yes or 2 for no:"<<endl;
        cin>>hi;
    }while(hi<1 || hi>2);
    if(hi==1) readHi();
    //vector fun
    vecFun();
    //Exit Stage Right
    return 0;
}
//*******************************//
//           pause               //
//*******************************//
void pauseG(){
    string trash;
    cout<<"******************************"<<endl;
    cout<<"*Enter to Continue...        *"<<endl;
    cout<<"******************************"<<endl;
    cin.ignore();
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
        cout<<"Wave : "<<wCount+1<<endl;
        //enemy1
        if(cont) cont=duelEn(user);
        if(cont) cout<<"(Kill Reward) ", user.addHel(50);
        //enemy2
        if(cont) cont=duelEn(user);
        if(cont) cout<<"(Kill Reward) ", user.addHel(50);
        //elite enemy
        if(cont) cont=duelEEn(user);
        if(cont){
            cout<<"(Kill Reward) ";
            user.addHel(100);
            statBon(user);
        }
        //enemy 4
        if(cont) cont=duelMEn(user);
        if(cont) cout<<"(Kill Reward) ", user.addHel(50);
        //enemy 5
        if(cont) cont=duelMEn(user);
        if(cont) cout<<"(Kill Reward) ", user.addHel(50);
        //enemy 6
        if(cont) cont=duelMEE(user);
        if(cont){
            cout<<"(Kill Reward) ",
            user.addHel(100);
            statBon(user);
        }
        //boss
        if(cont) cout<<"PREPARE YOURSELF, A BOSS APPROACHES!!!"<<endl;
        if(cont) pauseG();
        if(cont) cont=duelBos(user);
        if(cont){
            cout<<"(Kill Reward) ";
            user.addMaxH(25);
            cout<<"(Kill Reward) ";
            user.addHel(100);
            statBon(user);
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
        cout<<"Your Maximum Health: "<<user.getMaxH()<<endl;
        cout<<"Your Current Health: "<<user.getHel()<<endl;
        cout<<"1.Attack      : "<<user.getDps()<<" (damage) ("<<user.getWepn().getWBon()<<")"<<endl;
        cout<<"2.Self-Heal   : "<<user.getSlfH()<<" (health)"<<endl;
        cout<<"3.Special     : "<<user.getSpec()<<" ("<<user.getSpC()<<" left)"<<endl;
        cout<<"4.Surrender   : (The coward's way out)"<<endl;
        cin>>cho;
        if(cho==3 && user.getSpC()<=0) cho=6;
    }while(cho<1 || cho>4);
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
        cout<<"(First Strike) You get a free hit."<<endl;
        //user hits first
        hitCh=rand()%10+1;
        if(enemy.getWeak()==user.getArch()||enemy.getWeak()=="Any") hitCh+=2;
        if(hitCh<=2) cout<<"You missed your attack."<<endl;
        else enemy.takeDmg(user.getDps());
        pauseG();
    }
    do{
        //enemy attacks player
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            hitCh=rand()%10+1;
            if(enemy.getWeak()==user.getArch()) hitCh-=1;
            if(user.getWepn().getWBon()=="Dodge Chance") hitCh-=2;
            if(hitCh<=3) cout<<"The enemy missed."<<endl;
            else user.takeDam(enemy.getDps());
            cout<<"********************"<<endl;
        }
        //player attacks enemy
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            userCho=pickMov(user);
            hitCh=rand()%10+1;
            if(enemy.getWeak()==user.getArch()||enemy.getWeak()=="Any") hitCh+=2;
            if(userCho==1){
               if(hitCh<=2) cout<<"Your weapon has missed. No damage done."<<endl;
               else{
                   enemy.takeDmg(user.getDps());
                   if(user.getWepn().getWBon()=="LifeSteal"){
                       user.addHel(user.getDps());
                   }
               }
            }else if(userCho==2){
               user.healS(); 
            }else if(userCho==3){
               enemy.setHlth(user.useSpec(enemy.getHlth())); 
            }else{
               user.setHel(0); 
            }
            pauseG();
            
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
    //declare variables
    short hitCh=0, userCho=0;
    //create enemy
    CrapUnitElite enemy;
    //introduce enemy
    cout<<"Before you stands an enemy "<<enemy.getName()<<endl;
    //find who hits first
    if(user.getWepn().getWBon()=="First Strike"){
        cout<<"(First Strike) You get a free attack"<<endl;
        //user hits first
        hitCh=rand()%10+1;
        if(enemy.getWeak()==user.getArch()||enemy.getWeak()=="Any") hitCh+=1;
        if(enemy.getBon()=="Dodge Chance") hitCh-=1;
        if(hitCh<=4) cout<<"You missed your attack."<<endl;
        else enemy.takeDmg(user.getDps());
        pauseG();
    }
    do{
        //enemy attacks player
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            hitCh=rand()%10+1;
            if(enemy.getWeak()==user.getArch()) hitCh-=1;
            if(user.getWepn().getWBon()=="Dodge Chance") hitCh-=2;
            if(hitCh<=3) cout<<"The enemy missed."<<endl;
            else {
                user.takeDam(enemy.getDps());
                if(enemy.getBon()=="LifeSteal"){
                    cout<<"(Lifesteal) The enemy stole life with his attack."<<endl;
                    enemy.setHlth((enemy.getHlth())+enemy.getDps());
                }
            }
            cout<<"********************"<<endl;
        }
        //player attacks enemy
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            userCho=pickMov(user);
            hitCh=rand()%10+1;
            if(enemy.getWeak()==user.getArch()||enemy.getWeak()=="Any") hitCh+=1;
            if(enemy.getBon()=="Dodge Chance") hitCh-=1;
            if(userCho==1){
               if(hitCh<=4) cout<<"You weapon has missed. No damage done."<<endl;
               else{
                   enemy.takeDmg(user.getDps());
                   if(user.getWepn().getWBon()=="LifeSteal"){
                       user.addHel(user.getDps());
                   }
               }
            }else if(userCho==2){
               user.healS(); 
            }else if(userCho==3){
               enemy.setHlth(user.useSpec(enemy.getHlth())); 
            }else{
               user.setHel(0); 
            }
            pauseG();
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
//   duel moderate enemy         //
//*******************************//
bool duelMEn(Player &user){
    //declare variables
    short hitCh=0, userCho=0;
    //create enemy
    ModerateUnit enemy;
    //introduce enemy
    cout<<"Before you stands an enemy "<<enemy.getName()<<endl;
    //find who hits first
    if(user.getWepn().getWBon()=="First Strike"){
        cout<<"(First Strike) You get a free hit."<<endl;
        //user hits first
        hitCh=rand()%10+1;
        if(enemy.getWeak()==user.getArch()||enemy.getWeak()=="Any") hitCh+=2;
        if(hitCh<=2) cout<<"You missed your attack."<<endl;
        else enemy.takeDmg(user.getDps());
        pauseG();
    }
    do{
        //enemy attacks player
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            hitCh=rand()%10+1;
            if(enemy.getWeak()==user.getArch()) hitCh-=1;
            if(user.getWepn().getWBon()=="Dodge Chance") hitCh-=2;
            if(hitCh<=3) cout<<"The enemy missed."<<endl;
            else user.takeDam(enemy.getDps());
            cout<<"********************"<<endl;
        }
        //player attacks enemy
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            userCho=pickMov(user);
            hitCh=rand()%10+1;
            if(enemy.getWeak()==user.getArch()||enemy.getWeak()=="Any") hitCh+=2;
            if(userCho==1){
               if(hitCh<=2) cout<<"You weapon has missed. No damage done."<<endl;
               else{
                   enemy.takeDmg(user.getDps());
                   if(user.getWepn().getWBon()=="LifeSteal"){
                       user.addHel(user.getDps());
                   }
               }
            }else if(userCho==2){
               user.healS(); 
            }else if(userCho==3){
               enemy.setHlth(user.useSpec(enemy.getHlth())); 
            }else{
               user.setHel(0); 
            }
            pauseG();
            
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
//  duel moderate elite enemy    //
//*******************************//
bool duelMEE(Player &user){
    //declare variables
    short hitCh=0, userCho=0;
    //create enemy
    ModerateUnitElite enemy;
    //introduce enemy
    cout<<"Before you stands an enemy "<<enemy.getName()<<endl;
    //find who hits first
    if(user.getWepn().getWBon()=="First Strike"){
        cout<<"(First Strike) You get a free attack"<<endl;
        //user hits first
        hitCh=rand()%10+1;
        if(enemy.getWeak()==user.getArch()||enemy.getWeak()=="Any") hitCh+=1;
        if(enemy.getBon()=="Dodge Chance") hitCh-=1;
        if(hitCh<=4) cout<<"You missed your attack."<<endl;
        else enemy.takeDmg(user.getDps());
        pauseG();
    }
    do{
        //enemy attacks player
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            hitCh=rand()%10+1;
            if(enemy.getWeak()==user.getArch()) hitCh-=1;
            if(user.getWepn().getWBon()=="Dodge Chance") hitCh-=2;
            if(hitCh<=3) cout<<"The enemy missed."<<endl;
            else {
                user.takeDam(enemy.getDps());
                if(enemy.getBon()=="Rupture"){
                    cout<<"(Rupture) The enemy has left a permanent wound."<<endl;
                    cout<<"         -20 to your maximum health"<<endl;
                    user.setMaxH((user.getMaxH())-20);
                    if(user.getMaxH()>user.getHel()) user.setHel(user.getMaxH());
                }
            }
            cout<<"********************"<<endl;
        }
        //player attacks enemy
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            userCho=pickMov(user);
            hitCh=rand()%10+1;
            if(enemy.getWeak()==user.getArch()||enemy.getWeak()=="Any") hitCh+=1;
            if(enemy.getBon()=="Dodge Chance") hitCh-=1;
            if(userCho==1){
               if(hitCh<=4) cout<<"You weapon has missed. No damage done."<<endl;
               else{
                   enemy.takeDmg(user.getDps());
                   if(user.getWepn().getWBon()=="LifeSteal"){
                       user.addHel(user.getDps());
                   }
               }
            }else if(userCho==2){
               user.healS(); 
            }else if(userCho==3){
               enemy.setHlth(user.useSpec(enemy.getHlth())); 
            }else{
               user.setHel(0); 
            }
            pauseG();
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
//         duel boss             //
//*******************************//
bool duelBos(Player &user){
    //declare variables
    short hitCh=0, userCho=0, spez=0, fear=0,hyde=0,devour=0;
    int temp=0;
    //create enemy
    BossUnit enemy;
    //introduce enemy
    cout<<"Before you stands the abhorrent "<<enemy.getName()<<endl;
    //check for special
    if(enemy.getBon()=="Toxic"){
        cout<<"(Toxic) A vile cloud has lowered your resilience."<<endl;
        cout<<"       -100 to your maximum health."<<endl;
        user.setMaxH((user.getMaxH())-100);
        if(user.getHel()>user.getMaxH()) user.setHel(user.getMaxH());
    }
    //find who hits first
    if(enemy.getSpec()=="Trample"&& user.getHel()>100){
        cout<<"(Trample) Hoofs storm across your person."<<endl;
        cout<<"         -100 health"<<endl;
        user.takeDam(100);
    }
    if(user.getWepn().getWBon()=="First Strike"){
        cout<<"(First Strike) You get a free hit."<<endl;
        //user hits first
        hitCh=rand()%10+1;
        if(hitCh<=3) cout<<"You missed your attack."<<endl;
        else enemy.takeDmg(user.getDps()),hyde++;
        pauseG();
    }
    do{
        //enemy attacks player
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            hitCh=rand()%10+1;
            if(user.getWepn().getWBon()=="Dodge Chance") hitCh-=2;
            if(hitCh<=1) cout<<"The enemy missed."<<endl;
            else {
                user.takeDam(enemy.getDps());
                if(enemy.getBon()=="LifeSteal") enemy.setHlth((enemy.getHlth())+enemy.getDps());
                cout<<"(LifeSteal) "<<enemy.getName()<<" has stolen life equal to the damage dealt"<<endl;
            }
            cout<<"********************"<<endl;
        }
        devour=rand()%4+1;
        if(devour==1 && enemy.getSpec()=="Devour"){
            cout<<"(Devour) The Great Old One Cthulhu has devoured you whole."<<endl;
            user.setHel(0);
        }
        //player attacks enemy
        if((enemy.getHlth()!=0) && (user.getHel()!=0)){
            userCho=pickMov(user);
            hitCh=rand()%10+1;
            if(enemy.getBon()=="Fear") fear=rand()%3+1;
            if(fear==1){
                hitCh=1;
                cout<<"(Fear) "<<enemy.getName()<<" has struck you with fright."<<endl;
            }
            if(userCho==1){
               if(hitCh==1&& enemy.getBon()=="The Call"){
                   cout<<"(The Call) You lose focus and harm yourself."<<endl;
                   cout<<"You take "<<user.getDps()<<" damage."<<endl;
                   user.takeDam(user.getDps());
               }
               else if(hitCh<=3) cout<<"You weapon has missed. No damage done."<<endl;
               else{
                   enemy.takeDmg(user.getDps());
                   hyde++;
                   if(user.getWepn().getWBon()=="LifeSteal"){
                       user.addHel(user.getDps());
                   }
                   if(enemy.getBon()=="Conduit"){
                       cout<<"(Conduit) Electricity forks off the creature and onto you"<<endl;
                       cout<<" 20 Damage to your health."<<endl;
                       user.takeDam(20);
                   }
               }
            }else if(userCho==2){
               user.healS(); 
            }else if(userCho==3){
               enemy.setHlth(user.useSpec(enemy.getHlth())); 
            }else{
               user.setHel(0); 
            }
            pauseG();
            
        }
        if((spez==0)&&(enemy.getHlth()<=100)&&(enemy.getSpec()=="LifeSwap")){
            cout<<"(LifeSwap) Your life totals have been swapped"<<endl;
            temp=enemy.getHlth();
            enemy.setHlth(user.getHel());
            user.setHel(temp);
            spez++;
        }
        if((spez==0)&&(hyde>=5)&&(enemy.getSpec()=="Anger")){
            cout<<"(Anger) You have driven "<<enemy.getName()<<" to desperation."<<endl;
            cout<<"After swallowing a nefarious concoction, he has embraced his"<<endl;
            cout<<"inner Mr. Hyde."<<endl;
            enemy.setDps(200);
            spez++;
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
//         stat bonus            //
//*******************************//
void statBon(Player &user){
    short luck;
    luck=rand()%7+1;
    if(luck==1){
        //small health gain
        user.setHel((user.getHel())+20);
        cout<<"(Bonus) You have been healed +20 health."<<endl;
    }else if(luck==2){
        //big health gain
        user.setHel((user.getHel())+50);
        cout<<"(Bonus) You have been healed +50 health."<<endl;
    }else if(luck==3){
        //small dps gain
        user.setDps((user.getDps())+10);
        cout<<"(Bonus) You have gained +10 to your damage."<<endl;
    }else if(luck==4){
        //large dps gain
        user.setDps((user.getDps())+20);
        cout<<"(Bonus) You have gained +20 to your damage."<<endl;
    }else if(luck==5){
        //small max health gain
        user.setMaxH((user.getMaxH())+30);
        cout<<"(Bonus) You have gained +30 to your maximum health."<<endl;
    }else if(luck==6){
        //large max health gain
        user.setMaxH((user.getMaxH())+60);
        cout<<"(Bonus) You have gained +60 to your maximum health."<<endl;
    }else{
        //small health, max health, and dps gain
        user.setMaxH((user.getMaxH())+20);
        user.setHel((user.getHel())+20);
        user.setDps((user.getDps())+20);
        cout<<"(Bonus) You have gained +20 to your max health, +20 to your "<<endl;
        cout<<"        current health, and +20 to your damage."<<endl;
    }
    pauseG();
}
//*******************************//
//  return PlayerData            //
//*******************************//
PlayerData retPD(Player user){
    //declare struct
    PlayerData temp;
    strcpy(temp.name,user.getName().c_str());
    temp.maxHlth=user.getMaxH();
    temp.dps=user.getDps();
    strcpy(temp.arch,user.getArch().c_str());
    strcpy(temp.weapon,user.getWepn().getWNam().c_str());
    strcpy(temp.special,user.getSpec().c_str());
    temp.waveC=user.getWave();
    //return struct
    return temp;
}
//*******************************//
//         write Record          //
//*******************************//
void writeRec(PlayerData r, string cName){
    //open file
    fstream fStuff;
    cName+=".txt";
    fStuff.open(cName.c_str(), ios::out);
    //write structure to file
    //fStuff.write(reinterpret_cast<char *>(&records),sizeof(records));
    fStuff<<"Name            : "<<r.name<<endl;
    fStuff<<"Maximum Health  : "<<r.maxHlth<<endl;
    fStuff<<"Damage          : "<<r.dps<<endl;
    fStuff<<"Archetype       : "<<r.arch<<endl;
    fStuff<<"Weapon          : "<<r.weapon<<endl;
    fStuff<<"Special         : "<<r.special<<endl;
    fStuff<<"Waves Completed : "<<r.waveC<<endl;
    //close file
    fStuff.close(); 
}
//*******************************//
//    file i/o highscore         //
//*******************************//
void writeHi(PlayerData r){
    //create structure
    PlayerData temp;
    //open file
    fstream fout;
    fout.open("Highscores.dat", ios::out | ios::binary | ios::app);
    //write file from structure
    fout.write(reinterpret_cast<char *>(&r),sizeof(r));
    //close file
    fout.close();
}
//*******************************//
//        read Record            //
//*******************************//
void readHi(){
    //create structure
    PlayerData temp;
    //open file
    fstream fin;
    fin.open("Highscores.dat", ios::in | ios::binary);
    while(fin){
       //read file into structure
       fin.read(reinterpret_cast<char *>(&temp),sizeof(temp));
       //output structure
       cout<<"Name            : "<<temp.name<<endl;
       cout<<"Maximum Health  : "<<temp.maxHlth<<endl;
       cout<<"Damage          : "<<temp.dps<<endl;
       cout<<"Archetype       : "<<temp.arch<<endl;
       cout<<"Weapon          : "<<temp.weapon<<endl;
       cout<<"Special         : "<<temp.special<<endl;
       cout<<"Waves Completed : "<<temp.waveC<<endl;
    }
    
    //close file
    fin.close();
}
//*******************************//
//        vector fun             //
//*******************************//
void vecFun(){
    //create an array of vectors from template
    SimpleVector<int> stuff(10);
    stuff.pushEle(5);
    /*for(int i=0;i<11;i++){
        cout<<stuff[i]<<endl;
    }*/
}