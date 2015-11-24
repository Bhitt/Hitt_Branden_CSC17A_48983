/* 
 * File:   Numbers.h
 * Author: Branden Hitt
 * Purpose: Specification for the numbers class
 * Created on November 8, 2015, 7:48 PM
 */

#ifndef NUMBERS_H
#define	NUMBERS_H

#include <string>
using namespace std;

class Numbers{
    private:
        int num;
        static string less[20];
        static string more[8];
        static string hundred;
        static string thousand;
    public:
        Numbers(int);       //Constructor
        void print();       //Display
};

#endif	/* NUMBERS_H */

