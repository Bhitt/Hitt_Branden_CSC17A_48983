/* 
 * File:   card.cpp
 * Author: Branden Hitt
 * Created on November 8th, 2015, 4:50 PM
 * Purpose: Implementation for the Retail Item Class
 */

//User Library for the Specification
#include "RetailItem.h"

RetailItem::RetailItem(string d, int u, float p){
    setDesc(d);
    setUnit(u);
    setPrce(p);
}
void RetailItem::setDesc(string d){
    desc=d;
}
void RetailItem::setUnit(int u){
    units=u;
}
void RetailItem::setPrce(float p){
    price=p;
}
int RetailItem::getUnit(){
    return units;
}