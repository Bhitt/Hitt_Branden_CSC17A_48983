/* 
 * File:   Employee.h
 * Author: Branden Hitt
 * Purpose: Specification of the Employee class
 * Created on November 30, 2015, 11:14 PM
 */
#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee{
    private:
        string name;
        int number;
        string hireDt;
    public:
        Employee();
        Employee(string,int,string);
        void setName(string);
        void setNum(int);
        void setHire(string);
        string getName(){ return name;}
        int getNum(){ return number;}
        string getHire(){ return hireDt;}
};

#endif	/* EMPLOYEE_H */

