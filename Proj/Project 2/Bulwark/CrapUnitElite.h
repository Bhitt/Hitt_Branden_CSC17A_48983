/* 
 * File:   CrapUnitElite.h
 * Author: Branden Hitt
 * Purpose: Specification of the CrapUnitElite class
 * Created on December 1, 2015, 1:48 PM
 */

#ifndef CRAPUNITELITE_H
#define	CRAPUNITELITE_H

#include "CrapUnit.h"

class CrapUnitElite : public CrapUnit {
    private:
        string bonus;
    public:
        CrapUnitElite();            //Defaulted Constructor
        CrapUnitElite(string,int,int,string,string,string); //Constructor
        void setBon(string);        //Mutator
        string getBon();            //Accessor
};

#endif	/* CRAPUNITELITE_H */

