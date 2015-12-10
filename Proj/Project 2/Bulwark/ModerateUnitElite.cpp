/* 
 * File:   ModerateUnitElite.h
 * Author: Branden Hitt
 * Purpose: Implementation for the ModerateUnitElite class
 * Created on December 3, 2015, 1:00 PM
 */
#include "ModerateUnitElite.h"
#include <cstdlib>

ModerateUnitElite::ModerateUnitElite(){
    srand(static_cast<unsigned int>(time(0)));
    int pick=(rand()%5+1);
    if(pick==1){
        name="Elder Vampire Elite*";
        health=360;
        dps=55;
        type="Vampire";
        weakness="Paladin";
        bonus="none";
    }else if(pick==2){
        name="Dread Horseman Elite*";
        health=340;
        dps=60;
        type="Vandal";
        weakness="Ranger";
        bonus="none";
    }else if(pick==3){
        name="Maniac Elite*";
        health=300;
        dps=80;
        type="Mad Scientist";
        weakness="Warlock";
        bonus="none";
    }else if(pick==4){
        name="Monstrocity Elite*";
        health=400;
        dps=50;
        type="Frankenstein";
        weakness="Beserker";
        bonus="Rupture";
    }else{
        name="Fanatic Elite*";
        health=200;
        dps=150;
        type="Cthulhu Spawn";
        weakness="Any";
        bonus="none";
    }
}
ModerateUnitElite::ModerateUnitElite(string na, int he, int dp, string ty, string bo){
    name=na;
    health=he;
    dps=dp;
    type=ty;
    weakness="none";
    bonus=bo;
}
void ModerateUnitElite::setBon(string bo){
    bonus=bo;
}