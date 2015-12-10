/* 
 * File:   ModerateUnit.h
 * Author: Branden
 * Purpose: Implementation for the ModerateUnit class
 * Created on December 3, 2015, 12:49 PM
 */
#include "ModerateUnit.h"
#include <cstdlib>

ModerateUnit::ModerateUnit(){
    srand(static_cast<unsigned int>(time(0)));
    int pick=(rand()%5+1);
    if(pick==1){
        name="Elder Vampire";
        health=260;
        dps=45;
        type="Vampire";
        weakness="Paladin";
    }else if(pick==2){
        name="Dread Horseman";
        health=240;
        dps=50;
        type="Vandal";
        weakness="Ranger";
    }else if(pick==3){
        name="Maniac";
        health=200;
        dps=70;
        type="Mad Scientist";
        weakness="Warlock";
    }else if(pick==4){
        name="Monstrocity";
        health=300;
        dps=40;
        type="Frankenstein";
        weakness="Beserker";
    }else{
        name="Fanatic";
        health=100;
        dps=140;
        type="Cthulhu Spawn";
        weakness="Any";
    }
}
ModerateUnit::ModerateUnit(string na, int he, int dp, string ty, string we){
    name=na;
    health=he;
    dps=dp;
    type=ty;
    weakness=we;
}
void ModerateUnit::setType(string t){
    type=t;
}
void ModerateUnit::setWeak(string w){
    weakness=w;
}