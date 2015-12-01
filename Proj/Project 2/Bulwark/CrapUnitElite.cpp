/* 
 * File:   CrapUnitElite.h
 * Author: Branden Hitt
 * Purpose: Specification of the CrapUnitElite class
 * Created on December 1, 2015, 1:54 PM
 */

#include "CrapUnitElite.h"


CrapUnitElite::CrapUnitElite(){
    bonus="default";
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