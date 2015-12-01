
#include "ShiftSupervisor.h"

/* 
 * File:   ShiftSupervisor.h
 * Author: Administrator
 * Purpose: Implementation of the ShiftSupervisor class
 * Created on November 30, 2015, 11:23 PM
 */
ShiftSupervisor::ShiftSupervisor(int a, int b,string n,int num,string h){
    anSal=a;
    bonus=b;
    ShiftSupervisor::setName(n);
    ShiftSupervisor::setNum(num);
    ShiftSupervisor::setHire(h);
}
void ShiftSupervisor::setSal(int a){
    anSal=a;
}
void ShiftSupervisor::setBonus(int b){
    bonus=b;
}