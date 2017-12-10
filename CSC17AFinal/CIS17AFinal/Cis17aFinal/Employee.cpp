/* 
 * File:   Employee.h
 * Author: Branden Hitt
 * Purpose: Employee implementation
 * Created on December 18, 2015, 3:17 AM
 */
#include <iostream>
#include <string.h>
#include "Employee.h"
using namespace std;

Employee::Employee(char name[] , char title[] , float hrRate){
    strcpy(MyName,name);
    strcpy(JobTitle,title);
    HourlyRate=setHourlyRate(hrRate);
    HoursWorked=0;
    GrossPay=0;
    NetPay=0;
}
float Employee::Tax(float tot){
    float tax=0;
    if(tot<=500){
        tax=.1*tot;
    }else if(tot<1000 && tot>500){
        tot-=500;
        tax=50+(.2*tot);
    }else{
        tot-=1000;
        tax=150+(.3*tot);
    }
    
    return tax;
}
float Employee::setHourlyRate(float rate){
    if(rate<=0 || rate>=200) rate=0;
    HourlyRate=rate;
    return HourlyRate;
}
int Employee::setHoursWorked(int hrs){
    if(hrs<=0 || hrs>=84) hrs=0;
    HoursWorked=hrs;
    return HoursWorked;
}
void Employee::toString(){
    cout<<"Name        :"<<MyName<<endl;
    cout<<"Job Title   : "<<JobTitle<<endl;
    cout<<"Hours Worked: "<<HoursWorked<<endl;
    cout<<"Hourly Rate : "<<HourlyRate<<endl;
    cout<<"Gross Pay   : $"<<GrossPay<<endl;
    cout<<"Net Pay     : $"<<NetPay<<endl;
}
float Employee::getGrossPay(float rate, int hrs){
    //straight time
    if(hrs<=40){
        GrossPay=rate*hrs;
    }else{
        GrossPay=rate*40;
        hrs-=40;
        //time and a half
        if(hrs<=10){
            GrossPay+=(rate*1.5)*hrs;
        }else{
            GrossPay+=(rate*1.5)*10;
            hrs-=10;
            //double time
            GrossPay+=(rate*2)*hrs;
        }
    }
    return GrossPay;
    
}
float Employee::getNetPay(float gross){
    NetPay=gross-Tax(gross);
    return NetPay;
}
float Employee::CalculatePay(float x, int y){
    return getNetPay(getGrossPay(setHourlyRate(x)
		,setHoursWorked(y)));
}