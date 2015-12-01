/* 
 * File:   ShiftSupervisor.h
 * Author: Administrator
 * Purpose: Specification of the ShiftSupervisor class
 * Created on November 30, 2015, 11:23 PM
 */
#include "Employee.h"

#ifndef SHIFTSUPERVISOR_H
#define	SHIFTSUPERVISOR_H

class ShiftSupervisor : public Employee{
    private:
        int anSal;
        int bonus;
    public:
        ShiftSupervisor(int,int,string,int,string);
        void setSal(int);
        void setBonus(int);
        int getSal(){return anSal;}
        int getBonus(){return bonus;}
        
};

#endif	/* SHIFTSUPERVISOR_H */

