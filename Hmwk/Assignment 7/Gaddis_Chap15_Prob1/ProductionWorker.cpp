/* 
 * File:   ProductionWorker.h
 * Author: Branden Hitt
 * Purpose: Implementation of the Production Worker Class
 * Created on November 29, 2015, 11:38 PM
 */
#include "ProductionWorker.h"

ProductionWorker::ProductionWorker(int s, float p){
    shift=s;
    payRate=p;
}
void ProductionWorker::setShft(int s){
    shift=s;
}
void ProductionWorker::setPayR(float p){
    payRate=p;
}