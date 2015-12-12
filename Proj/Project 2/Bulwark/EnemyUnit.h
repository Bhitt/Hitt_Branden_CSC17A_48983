/* 
 * File:   EnemyUnit.h
 * Author: Branden Hitt
 * Purpose: Specification of the EnemyUnit Class
 * Created on November 27, 2015, 8:30 PM
 */
#include <string>
using namespace std;

#ifndef ENEMYUNIT_H
#define	ENEMYUNIT_H
#include "Unit.h"
class EnemyUnit: public Unit{
    protected:
        string name;
        int health;
        int dps;
        static string allegiance;
    public:
        EnemyUnit(){name="Empty",health=0,dps=0;} //Default Constructor (in-line)
        EnemyUnit(string,int,int);      //Constructor
        void setName(string);           //Mutator
        string getName();               //Accessor
        void setHlth(int);              //Mutator
        int getHlth(){return health;}   //Accessor (in-line)
        void setDps(int);               //Mutator
        int getDps();                   //Accessor
        void takeDmg(int);              //take damage function
        int getHate(){ return 0;}
};

#endif	/* ENEMYUNIT_H */

