/* 
 * File:   card.cpp
 * Author: Branden Hitt
 * Created on November 8th, 2015, 5:14 PM
 * Purpose: Implementation for the Inventory Class
 */

//User Library for the Specification
#include "Inventory.h"

Inventory::Inventory(){
    itemNum==0;
    quantty=0;
    cost=0;
    ttlCost=0;
}
Inventory::Inventory(int i, float c, int q){
    if(i<0) i=0;
    if(c<0) c=0;
    if(q<0) q=0;
    itemNum=i;
    quantty=q;
    cost=c;
    setTCst();
}
void Inventory::setItem(int i){
    if(i<0)itemNum=0;
    else itemNum=i;
}
void Inventory::setQuan(int q){
    if(q<0)quantty=0;
    else quantty=q;
}
void Inventory::setCost(float c){
    if(c<0)cost=0;
    else cost=c;
}
void Inventory::setTCst(){
    ttlCost=quantty*cost;
}
int Inventory::getQuan(){
    return quantty;
}