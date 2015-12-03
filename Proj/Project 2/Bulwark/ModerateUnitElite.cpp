/* 
 * File:   ModerateUnitElite.h
 * Author: Branden Hitt
 * Purpose: Implementation for the ModerateUnitElite class
 * Created on December 3, 2015, 1:00 PM
 */
#include "ModerateUnitElite.h"
ModerateUnitElite::ModerateUnitElite(){
    name="default";
    health=0;
    dps=0;
    type="default";
    weakness="none";
    bonus="default";
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