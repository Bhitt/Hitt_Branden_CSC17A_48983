
#include "Weapon.h"

/* 
 * File:   Weapon.h
 * Author: Branden Hitt
 * Purpose: Implementation for the Weapon class
 * Created on December 1, 2015, 2:18 PM
 */
Weapon::Weapon(){
    wName="default";
    wBonus=0;
    wType="default";
}
Weapon::Weapon(string na, int bo, string ty){
    wName=na;
    wBonus=bo;
    wType=ty;
}
void Weapon::setWNam(string na){
    wName=na;
}
void Weapon::setWBon(int bo){
    wBonus=bo;
}
void Weapon::setWTyp(string ty){
    wType=ty;
}