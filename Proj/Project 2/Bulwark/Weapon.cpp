
#include "Weapon.h"

/* 
 * File:   Weapon.h
 * Author: Branden Hitt
 * Purpose: Implementation for the Weapon class
 * Created on December 1, 2015, 2:18 PM
 */
Weapon::Weapon(){
    wName="default";
    wBonus="none";
    wType="default";
}
Weapon::Weapon(int pick){
    if(pick==1){
        wName="Long Bow";
        wType="Ranged";
    }else if(pick==2){
        wName="Staff";
        wType="Ranged";
    }else if(pick==3){
        wName="Sword";
        wType="Melee";
    }else{
        wName="War Axe";
        wType="Melee";
    }
    wBonus="none";
}
Weapon::Weapon(string na, string bo, string ty){
    wName=na;
    wBonus=bo;
    wType=ty;
}
void Weapon::setWNam(string na){
    wName=na;
}
void Weapon::setWBon(string bo){
    wBonus=bo;
}
void Weapon::setWTyp(string ty){
    wType=ty;
}