/* 
 * File:   DayOfYear.h
 * Author: Administrator
 *
 * Created on November 23, 2015, 6:40 PM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H

#include <string>
using namespace std;

class DayOfYear{
    private:
        int day;
        static string month[12];
    public:
        DayOfYear(int);             //constructor
        DayOfYear(string,int);      //constructor
        int getDay();               //accessor
        void print();               //display
        DayOfYear operator++();     //prefix operator
        DayOfYear operator++(int);  //postfix operator
        DayOfYear operator--();     //prefix operator
        DayOfYear operator--(int);  //postfix operator
};

#endif	/* DAYOFYEAR_H */

