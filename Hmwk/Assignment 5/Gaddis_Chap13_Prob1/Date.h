/* 
 * File:   Date.h
 * Author: Branden Hitt
 * Created on November 3, 2015, 3:38 PM
 * Purpose: Specification for the Date class
 */

#ifndef DATE_H
#define	DATE_H

class Date{
    private:
        int month;
        int day;
        int year;
    public:
        void setMonth(int);
        void setDay(int);
        void setYear(int);
        void display1();
        void display2();
        void display3();
};

#endif	/* DATE_H */

