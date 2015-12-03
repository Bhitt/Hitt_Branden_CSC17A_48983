/* 
 * File:   ModerateUnit.h
 * Author: Branden
 * Purpose: Implementation for the ModerateUnit class
 * Created on December 3, 2015, 12:49 PM
 */
#include "ModerateUnit.h"

ModerateUnit::ModerateUnit(){
    name="default";
    health=0;
    dps=0;
    type="default";
    weakness="default";
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