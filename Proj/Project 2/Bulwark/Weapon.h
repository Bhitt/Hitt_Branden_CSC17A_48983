/* 
 * File:   Weapon.h
 * Author: Branden Hitt
 * Purpose: Specification for the Weapon class
 * Created on December 1, 2015, 2:10 PM
 */

#include <string>
using namespace std;

#ifndef WEAPON_H
#define	WEAPON_H

class Weapon{
    private:
        string wName;
        string wBonus;
        string wType;
    public:
        Weapon();                       //Default Constructor
        Weapon(int);                    //Constructor
        Weapon(string,string,string);   //Constructor
        void setWNam(string);           //Mutator
        void setWBon(string);           //Mutator
        void setWTyp(string);           //Mutator
        string getWNam(){return wName;} //Accessor (in-line) 
        string getWBon(){return wBonus;}//Accessor (in-line)
        string getWTyp(){return wType;} //Accessor (in-line)
};

#endif	/* WEAPON_H */

