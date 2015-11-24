/* 
 * File:   NumDays.h
 * Author: Administrator
 * Purpose: Implementation of the NumDays class
 * Created on November 23, 2015, 9:40 PM
 */
 

//user library for specification
#include "NumDays.h"

NumDays::NumDays(int h){
    if(h<0)h=0;
    hours=h;
    setDays(hours);
}

int NumDays::getHrs(){
    return hours;
}

void NumDays::setHrs(int h){
    hours=h;
}

float NumDays::getDays(){
    return days;
}

void NumDays::setDays(int h){
    days=(h*1.0f)/8;
}

NumDays NumDays::operator +(const NumDays &right){
    NumDays temp(0);
    temp.hours= hours+right.hours;
    //int temp = hours + right.hours;
    return temp;
}

NumDays NumDays::operator -(const NumDays &right){
    NumDays temp(0);
    temp.hours= hours-right.hours;
    //int temp= hours - right.hours;
    return temp;
}

NumDays NumDays::operator ++(){
    hours++;
    setDays(hours);
}

NumDays NumDays::operator --(){
    hours--;
    setDays(hours);
}

