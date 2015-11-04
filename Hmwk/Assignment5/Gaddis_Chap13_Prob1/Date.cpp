/* 
 * File:   card.cpp
 * Author: Branden Hitt
 * Created on November 3rd, 2015, 3:20 PM
 * Purpose: Implementation for the Date Class
 */
#include <iostream>
using namespace std;
//User Library for the Specification
#include "Date.h"
        
void Date::setMonth(int m){
    if(m<1||m>12) m=1;
    month=m;
}       
void Date::setDay(int d){
    if(d>1||d>31) d=1;
    day=d;
}
void Date::setYear(int y){
    year=y;
}
void Date::display1(){
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
void Date::display2(){
    if(month==1)cout<<"January ";
    else if(month==2)cout<<"February ";
    else if(month==3)cout<<"March ";
    else if(month==4)cout<<"April ";
    else if(month==5)cout<<"May ";
    else if(month==6)cout<<"June ";
    else if(month==7)cout<<"July ";
    else if(month==8)cout<<"August ";
    else if(month==9)cout<<"September ";
    else if(month==10)cout<<"October ";
    else if(month==11)cout<<"November ";
    else cout<<"December ";
    cout<<day<<", "<<year<<endl;
}
void Date::display3(){
    cout<<day<<" ";
    if(month==1)cout<<"January ";
    else if(month==2)cout<<"February ";
    else if(month==3)cout<<"March ";
    else if(month==4)cout<<"April ";
    else if(month==5)cout<<"May ";
    else if(month==6)cout<<"June ";
    else if(month==7)cout<<"July ";
    else if(month==8)cout<<"August ";
    else if(month==9)cout<<"September ";
    else if(month==10)cout<<"October ";
    else if(month==11)cout<<"November ";
    else cout<<"December ";
    cout<<year<<endl;
}