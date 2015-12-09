/* 
 * File:   CrapUnit.h
 * Author: Branden Hitt
 * Purpose: Specification of the CrapUnit class
 * Created on December 1, 2015, 1:25 PM
 */

#ifndef CRAPUNIT_H
#define	CRAPUNIT_H

#include "EnemyUnit.h"

class CrapUnit : public EnemyUnit{
    protected:
       string type;         
       string weakness;
    public:
       CrapUnit();                              //Default Constructor
       CrapUnit(string,int,int,string,string);  //Constructor
       void setType(string);                    //Mutator
       void setWeak(string);                    //Mutator
       string getType(){ return type;}          //Accessor (in-line)
       string getWeak(){ return weakness;}      //Accessor (in-line)
       void takeDmg(int);                       //take damage function
};

#endif	/* CRAPUNIT_H */

