/* 
 * File:   CrapUnit.h
 * Author: Branden Hitt
 * Purpose: Implementation of the CrapUnit class
 * Created on December 1, 2015, 1:35 PM
 */

#include "CrapUnit.h"


CrapUnit::CrapUnit(){
    type="default";
    weakness="default";
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