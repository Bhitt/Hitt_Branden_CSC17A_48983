/* 
 * File:   Employee.h
 * Author: Branden Hitt
 * Purpose: Implementation of the Employee Class
 * Created on November 30, 2015, 11:46 PM
 */

#include "Employee.h"

Employee::Employee(){
    name="Empty Field";
    number=00000;
    hireDt="Empty Field";
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
