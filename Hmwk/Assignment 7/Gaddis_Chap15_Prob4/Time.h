/* 
 * File:   Time.h
 * Author: Administrator
 * Specification of the Time Class
 * Created on December 1, 2015, 12:23 AM
 */

#ifndef TIME_H
#define	TIME_H

class Time{
    protected:
        int hour;
        int min;
        int sec;
    public:
        Time(){ hour=0; min=0; sec=0; }
        Time(int h, int m, int s){ hour=h; min=m; sec=s;}
        int getHour() const {return hour;}
        int getMin() const {return min;}
        int getSec() const {return sec;}
};

#endif	/* TIME_H */

