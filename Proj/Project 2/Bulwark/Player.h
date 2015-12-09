/* 
 * File:   Player.h
 * Author: Branden Hitt
 * Purpose: Specification of the Player class
 * Created on December 1, 2015, 2:01 PM
 */
#include "Weapon.h"
#include <string>
using namespace std;

#ifndef PLAYER_H
#define	PLAYER_H

class Player{
    private:
        string name;
        int health;
        int dps;
        int selfH;
        string special;
        int specC;
        string arche;
        Weapon weapon;
        int maxHlth;
        int waveCnt;
    public:
        Player();                               //Default Constructor
        Player(string,int);                     //Constructor
        Player(string,int,int,string);          //Constructor
        void setName(string);                   //Mutator
        void setHel(int);                       //Mutator
        void setDps(int);                       //Mutator
        void setSlfH(int);                      //Mutator
        void setSpec(string);                   //Mutator
        void setSpC(int);                       //Mutator
        void setArch(string);                   //Mutator    
        void setWepn(Weapon &);                 //Mutator
        void setMaxH(int);                      //Mutator
        void setWave(int);                      //Mutator
        string getName(){ return name;}         //Accessor (in-line)
        int getHel(){ return health;}           //Accessor (in-line)
        int getDps(){ return dps;}              //Accessor (in-line)
        int getSlfH(){ return selfH;}           //Accessor (in-line)
        string getSpec(){ return special;}      //Accessor (in-line)
        int getSpC(){ return specC;}            //Accessor (in-line)
        string getArch(){ return arche;}        //Accessor (in-line)
        Weapon getWepn(){ return weapon;}       //Accessor (in-line)
        int getMaxH(){ return maxHlth;}         //Accessor (in-line)
        int getWave(){ return waveCnt;}         //Accessor (in-line)
        void takeDam(int);                      //Take damage function
        void addHel(int);                       //Add health function
        void addMaxH(int);                      //Add max health
        int useSpec(int);                       //Use special attack
        void healS();                           //Self heal
};

#endif	/* PLAYER_H */

