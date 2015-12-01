/* 
 * File:   MilTime.h
 * Author: Administrator
 *
 * Created on December 1, 2015, 12:28 AM
 */
#include "Time.h"
#ifndef MILTIME_H
#define	MILTIME_H

class MilTime : public Time{
    private:
        int milHrs;
        int milSec;
    public:
        MilTime(int h,int s);
        void setTime(int,int);
        int getMHour(){return milHrs;}
        int getStHr(){return hour;}
};

#endif	/* MILTIME_H */

