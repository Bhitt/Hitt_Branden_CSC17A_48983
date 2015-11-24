/* 
 * File:   card.cpp
 * Author: Branden Hitt
 * Created on November 8th, 2015, 4:00 PM
 * Purpose: Implementation for the Personal Info Class
 */

using namespace std;
//User Library for the Specification
#include "PersonalInfo.h"

void PrsInfo::setName(string n){
    name=n;
}
void PrsInfo::setAdd(string a){
    address=a;
}
void PrsInfo::setAge(unsigned short a){
    age=a;
}
unsigned short PrsInfo::getAge(){
    return age;
}
void PrsInfo::setPhn(string p){
    phone=p;
}