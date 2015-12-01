#include <iostream>
#include "MilTime.h"
using namespace std;
/* 
 * File:   MilTime.h
 * Author: Branden Hitt
 *
 * Created on December 1, 2015, 12:28 AM
 */
MilTime::MilTime(int h, int s){
    if(h>2359||h<0)h=0, cout<<"Invalid Input"<<endl;
    if(s>59||s<0)s=0, cout<<"Invlaid Input"<<endl;
    milHrs=h;
    milSec=s;
    MilTime::setTime(h,s);
}
void MilTime::setTime(int h, int s){
    if(h>=1300)h-=1200;
    min=(h%100);
    hour=h/100;
    sec=s;
}