/* 
 * File:   NumDays.h
 * Author: Administrator
 * Purpose: Specification for the NumDays class
 * Created on November 23, 2015, 9:29 PM
 */

#ifndef NUMDAYS_H
#define	NUMDAYS_H

class NumDays{
    private:
        float days;
        int hours;
    public:
        NumDays(int);           //constructor
        int getHrs();           //accessor
        void setHrs(int);       //mutator
        float getDays();        //accessor
        void setDays(int);      //mutator
        NumDays operator++();   //overloaded operator
        NumDays operator--();   //overloaded operator
        NumDays operator + (const NumDays &); //overloaded operator
        NumDays operator - (const NumDays &); //overloaded operator
};

#endif	/* NUMDAYS_H */

