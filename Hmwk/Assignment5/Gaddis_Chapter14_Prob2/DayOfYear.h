/* 
 * File:   DayOfYear.h
 * Author: Branden Hitt
 * Purpose: Specification for the dayofyear class
 * Created on November 15, 2015, 5:07 PM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H

#include <string>
using namespace std;

class DayOfYear{
    private:
        int day;
        static string *ptr;
    public:
        DayOfYear(int);             //constructor
        int getDay();               //accessor
        string getPtr(int);         //accessor
        void print();               //display
};

string *DayOfYear::ptr=month;

#endif	/* DAYOFYEAR_H */

