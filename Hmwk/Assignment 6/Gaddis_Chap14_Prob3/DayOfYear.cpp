/* 
 * File:   DayOfYear.h
 * Author: Branden Hitt
 * Purpose: Implementation for the dayofyear class
 * Created on November 15, 2015, 5:07 PM
 */

#include <iostream>
#include <string>
using namespace std;
//user library for specification
#include "DayOfYear.h"

DayOfYear::DayOfYear(int d){
    if(d<1||d>365) d=0;
    day=d;
}

DayOfYear::DayOfYear(string m, int d){
    if(m=="January"){
        if(d<1||d>31){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d;
        }
    }else if(m=="February"){
        if(d<1||d>28){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+31;
        }
    }else if(m=="March"){
        if(d<1||d>31){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+59;
        }
    }else if(m=="April"){
        if(d<1||d>30){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+90;
        }
    }else if(m=="May"){
        if(d<1||d>31){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+120;
        }
    }else if(m=="June"){
        if(d<1||d>30){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+151;
        }
    }else if(m=="July"){
        if(d<1||d>31){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+181;
        }
    }else if(m=="August"){
        if(d<1||d>31){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+212;
        }
    }else if(m=="September"){
        if(d<1||d>30){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+243;
        }
    }else if(m=="October"){
        if(d<1||d>31){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+273;
        }
    }else if(m=="November"){
        if(d<1||d>30){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+304;
        }
    }else if(m=="December"){
        if(d<1||d>31){
            cout<<"Invalid Input"<<endl;
            return;
        }else{
            day=d+334;
        }
    }else{
        cout<<"Invalid Input"<<endl;
        return;
    }
    
}

string DayOfYear::month[12]={"January","February","March","April","May","June",
                  "July","August","September","October","November","December"};

int DayOfYear::getDay(){
    return day;
}

void DayOfYear::print(){
    cout<<getDay();
}

DayOfYear DayOfYear::operator --(){
    if(day==1)day=365;
    else day--;
}

DayOfYear DayOfYear::operator ++(){
    if(day==365)day=1;
    else day++;
}

