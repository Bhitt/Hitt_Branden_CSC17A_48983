/* 
 * File:   EnemyUnit.h
 * Author: Branden Hitt
 * Purpose: Implementation of the EnemyUnit Class
 * Created on November 27, 2015, 8:40 PM
 */

#include "EnemyUnit.h"
#include <string>

EnemyUnit::EnemyUnit(string n, int h, int d){
    name=n;
    health=h;
    dps=d;
}
void EnemyUnit::setName(string n){
    name=n;
}

string EnemyUnit::getName(){
    return name;
}
void EnemyUnit::setHlth(int h){
    health=h;
}
void EnemyUnit::setDps(int d){
    dps=d;
}
int EnemyUnit::getDps(){
    return dps;
}