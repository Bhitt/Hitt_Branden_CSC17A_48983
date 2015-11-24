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

//void DayOfYear::setPtr(){
//    string month[12]={"January","February","March","April","May","June",
//                  "July","August","September","October","November","December"};
//    string* DayOfYear::ptr=month;
//}

//string DayOfYear::getPtr(int i){
//    return *(ptr+i);
//}

string DayOfYear::month[12]={"January","February","March","April","May","June",
                  "July","August","September","October","November","December"};

int DayOfYear::getDay(){
    return day;
}

void DayOfYear::print(){
    if(getDay()==0){
        //error case
        cout<<"Invalid Input"<<endl;
    }else if(getDay()<=31){
        //January
        cout<<month[0]<<" "<<getDay()<<endl;
    }else if(getDay()<=59){
        //February
        cout<<month[1]<<" "<<getDay()-31<<endl;
    }else if(getDay()<=90){
        //March
        cout<<month[2]<<" "<<getDay()-59<<endl;
    }else if(getDay()<=120){
        //April
        cout<<month[3]<<" "<<getDay()-90<<endl;
    }else if(getDay()<=151){
        //May
        cout<<month[4]<<" "<<getDay()-120<<endl;
    }else if(getDay()<=181){
        //June
        cout<<month[5]<<" "<<getDay()-151<<endl;
    }else if(getDay()<=212){
        //July
        cout<<month[6]<<" "<<getDay()-181<<endl;
    }else if(getDay()<=243){
        //August
        cout<<month[7]<<" "<<getDay()-212<<endl;
    }else if(getDay()<=273){
        //September
        cout<<month[8]<<" "<<getDay()-243<<endl;
    }else if(getDay()<=304){
        //October
        cout<<month[9]<<" "<<getDay()-273<<endl;
    }else if(getDay()<=334){
        //November
        cout<<month[10]<<" "<<getDay()-304<<endl;
    }else{
        //December
        cout<<month[11]<<" "<<getDay()-334<<endl;
    }
}
