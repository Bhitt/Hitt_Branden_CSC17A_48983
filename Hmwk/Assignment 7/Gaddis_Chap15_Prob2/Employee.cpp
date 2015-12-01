
#include "Employee.h"

/* 
 * File:   Employee.h
 * Author: Branden Hitt
 * Purpose: Implementation of the Employee class
 * Created on November 30, 2015, 11:14 PM
 */
Employee::Employee(){
    name="empty";
    number=00000;
    hireDt="00/00/00";
}
Employee::Employee(string n, int num, string h){
    name=n;
    number=num;
    hireDt=h;
}
void Employee::setName(string n){
    name=n;
}
void Employee::setNum(int n){
    number=n;
}
void Employee::setHire(string h){
    hireDt=h;
}