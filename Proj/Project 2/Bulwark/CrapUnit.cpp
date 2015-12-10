/* 
 * File:   CrapUnit.h
 * Author: Branden Hitt
 * Purpose: Implementation of the CrapUnit class
 * Created on December 1, 2015, 1:35 PM
 */

#include "CrapUnit.h"
#include <cstdlib>
#include <iostream>

CrapUnit::CrapUnit(){
    srand(static_cast<unsigned int>(time(0)));
    int pick=(rand()%5+1);
    if(pick==1){
        name="Young Vampire";
        health=160;
        dps=25;
        type="Vampire";
        weakness="Paladin";
    }else if(pick==2){
        name="Dark Rider";
        health=140;
        dps=30;
        type="Vandal";
        weakness="Ranger";
    }else if(pick==3){
        name="Lunatic";
        health=100;
        dps=50;
        type="Mad Scientist";
        weakness="Warlock";
    }else if(pick==4){
        name="Abomination";
        health=200;
        dps=20;
        type="Frankenstein";
        weakness="Beserker";
    }else{
        name="Cultist";
        health=50;
        dps=120;
        type="Cthulhu Spawn";
        weakness="Any";
    }
}
CrapUnit::CrapUnit(string na, int he, int d, string ty, string weak){
    name=na;
    health=he;
    dps=d;
    type=ty;
    weakness=weak;
}
void CrapUnit::setType(string t){
    type=t;
}
void CrapUnit::setWeak(string w){
    weakness=w;
}