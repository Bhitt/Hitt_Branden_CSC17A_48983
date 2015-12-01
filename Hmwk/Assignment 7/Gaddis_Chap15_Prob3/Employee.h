/* 
 * File:   Employee.h
 * Author: Administrator
 *
 * Created on November 30, 2015, 11:46 PM
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
        Employee();                         //default contructor
        Employee(string,int,string);        //constructor
        void setName(string);               //mutator
        string getName(){ return name;}     //accessor (in-line)
        void setNum(int);                   //mutator
        int getNum(){ return number;}       //accessor (in-line)
        void setHire(string);               //mutator
        string getHire(){ return hireDt;}   //accessor (in-line)
    
};

#endif	/* EMPLOYEE_H */

