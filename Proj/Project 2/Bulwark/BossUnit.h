/* 
 * File:   BossUnit.h
 * Author: Branden Hitt
 * Purpose: Specification of the BossUnit class
 * Created on December 3, 2015, 1:06 PM
 */

#ifndef BOSSUNIT_H
#define	BOSSUNIT_H
#include "EnemyUnit.h"
class BossUnit : public EnemyUnit{
    private:
        string bonus;
        string special;
    public:
        BossUnit();                         //Default Constructor
        void setBon(string);                //Mutator
        void setSpec(string);               //Mutator
        string getBon(){return bonus;}      //Accessor (in-line)
        string getSpec(){return special;}   //Accessor (in-line)
};

#endif	/* BOSSUNIT_H */

