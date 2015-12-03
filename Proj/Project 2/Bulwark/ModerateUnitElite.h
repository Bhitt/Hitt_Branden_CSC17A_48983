/* 
 * File:   ModerateUnitElite.h
 * Author: Branden Hitt
 * Purpose: Specification for the ModerateUnitElite class
 * Created on December 3, 2015, 12:54 PM
 */

#ifndef MODERATEUNITELITE_H
#define	MODERATEUNITELITE_H
#include "ModerateUnit.h"
class ModerateUnitElite : public ModerateUnit{
    private:
        string bonus;
    public:
        ModerateUnitElite();                //Default Constructor
        ModerateUnitElite(string,int,int,string,string); //Constructor
        void setBon(string);                //Mutator
        string getBon(){return bonus;}      //Accessor (in-line)
};

#endif	/* MODERATEUNITELITE_H */

