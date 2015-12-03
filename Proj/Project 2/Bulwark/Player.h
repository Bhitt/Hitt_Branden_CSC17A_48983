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
        string arche;
        Weapon weapon;
        int maxHlth;
        int waveCnt;
    public:
        Player();                               //Default Constructor
        Player(string,int,int,string);          //Constructor
        void setName(string);                   //Mutator
        void setHel(int);                       //Mutator
        void setDps(int);                       //Mutator
        void setArch(string);                   //Mutator    
        void setWepn(Weapon &);                 //Mutator
        void setMaxH(int);                      //Mutator
        void setWave(int);                      //Mutator
        string getName(){ return name;}         //Accessor (in-line)
        int getHel(){ return health;}           //Accessor (in-line)
        int getDps(){ return dps;}              //Accessor (in-line)
        string getArch(){ return arche;}        //Accessor (in-line)
        Weapon getWepn(){ return weapon;}       //Accessor (in-line)
        int getMaxH(){ return maxHlth;}         //Accessor (in-line)
        int getWave(){ return waveCnt;}         //Accessor (in-line)
};

#endif	/* PLAYER_H */

