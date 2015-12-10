/* 
 * File:   CrapUnitElite.h
 * Author: Branden Hitt
 * Purpose: Specification of the CrapUnitElite class
 * Created on December 1, 2015, 1:54 PM
 */
#include <cstdlib>
#include "CrapUnitElite.h"

CrapUnitElite::CrapUnitElite(){
    srand(static_cast<unsigned int>(time(0)));
    int pick=(rand()%5+1);
    if(pick==1){
        name="Young Vampire Elite*";
        health=320;
        dps=25;
        type="Vampire";
        weakness="Paladin";
        bonus="LifeSteal";
    }else if(pick==2){
        name="Dark Rider Elite*";
        health=280;
        dps=30;
        type="Vandal";
        weakness="Ranger";
        bonus="None";
    }else if(pick==3){
        name="Lunatic Elite*";
        health=200;
        dps=50;
        type="Mad Scientist";
        weakness="Warlock";
        bonus="None";
    }else if(pick==4){
        name="Abomination Elite*";
        health=400;
        dps=20;
        type="Frankenstein";
        weakness="Beserker";
        bonus="Dodge Chance";
    }else{
        name="Cultist Elite*";
        health=100;
        dps=120;
        type="Vampire";
        weakness="Any";
        bonus="None";
    }
}
CrapUnitElite::CrapUnitElite(string na, int he, int d, string ty, string weak,string bon){
    name=na;
    health=he;
    dps=d;
    type=ty;
    weakness=weak;
    bonus=bon;
}
void CrapUnitElite::setBon(string bon){
    bonus=bon;
}
string CrapUnitElite::getBon(){
    return bonus;
}