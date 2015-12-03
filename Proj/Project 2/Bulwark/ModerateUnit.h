/* 
 * File:   ModerateUnit.h
 * Author: Branden
 * Purpose: Specification for the ModerateUnit class
 * Created on December 3, 2015, 12:42 PM
 */

#ifndef MODERATEUNIT_H
#define	MODERATEUNIT_H
#include "EnemyUnit.h"
class ModerateUnit: public EnemyUnit{
    protected:
        string type;
        string weakness;
    public:
        ModerateUnit();                             //Default Constructor
        ModerateUnit(string,int,int,string,string); //Constructor
        void setType(string);                       //Mutator
        void setWeak(string);                       //Mutator
        string getType(){ return type;}             //Accessor (in-line)
        string getWeak(){ return weakness;}         //Accessor (in-line)
};

#endif	/* MODERATEUNIT_H */

