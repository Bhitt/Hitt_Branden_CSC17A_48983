/* 
 * File:   Unit.h
 * Author: Branden
 * Purpose: Abstract base class
 * Created on December 11, 2015, 8:12 PM
 */
#include <string>
using namespace std;
#ifndef UNIT_H
#define	UNIT_H

class Unit{
    private:
        int hate;
    public:
        Unit(){ hate=0;}        //constructor
        virtual int getHate()=0; //pure virtual function
};

#endif	/* UNIT_H */

