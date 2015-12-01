/* 
 * File:   ProductionWorker.h
 * Author: Branden Hitt
 * Purpose: Implementation of the Production Worker Class
 * Created on November 29, 2015, 11:38 PM
 */
#include "ProductionWorker.h"
#include "Employee.h"

ProductionWorker::ProductionWorker(){
    shift=0;
    payRate=1.11;
}
ProductionWorker::ProductionWorker(string n,int num,string h,int s, float p){
    shift=s;
    payRate=p;
    ProductionWorker::setName(n);
    ProductionWorker::setNum(num);
    ProductionWorker::setHire(h);
}
void ProductionWorker::setShft(int s){
    shift=s;
}
void ProductionWorker::setPayR(float p){
    payRate=p;
}
