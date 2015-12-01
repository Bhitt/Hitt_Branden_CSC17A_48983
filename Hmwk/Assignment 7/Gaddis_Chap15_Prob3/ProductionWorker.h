/* 
 * File:   ProducitonWorker.h
 * Author: Administrator
 *
 * Created on November 30, 2015, 11:49 PM
 */

#ifndef PRODUCITONWORKER_H
#define	PRODUCITONWORKER_H
#include "Employee.h"
class ProductionWorker : public Employee{
    private:
        int shift;
        float payRate;
    public:
        ProductionWorker();
        ProductionWorker(string,int,string,int,float);
        void setShft(int);
        int getShft(){ return shift;}
        void setPayR(float);
        float getPayR(){ return payRate;} 
};


#endif	/* PRODUCITONWORKER_H */

