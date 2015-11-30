/* 
 * File:   ProductionWorker.h
 * Author: Branden Hitt
 * Purpose: Specification of the Production Worker Class
 * Created on November 29, 2015, 11:38 PM
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H
#include "Employee.h"

class ProductionWorker : public Employee{
    private:
        int shift;
        float payRate;
    public:
        ProductionWorker(int,float);
        void setShft(int);
        int getShft(){ return shift;}
        void setPayR(float);
        float getPayR(){ return payRate;} 
};

#endif	/* PRODUCTIONWORKER_H */

