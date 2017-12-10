/* 
 * File:   Employee.h
 * Author: Branden Hitt
 * Purpose: Employee specification
 * Created on December 18, 2015, 3:17 AM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee{
    private:
	float Tax(float);      //Utility Procedure
	char   MyName[20];      //Property
	char   JobTitle[20];    //Property
	float  HourlyRate;      //Property
	int    HoursWorked;     //Property
	float  GrossPay;        //Property
	float  NetPay;          //Property
    public:
	Employee(char[],char[],float);  //Constructor
	float  CalculatePay(float,int); //Procedure
	float  getGrossPay(float,int);  //Procedure
	float  getNetPay(float);        //Procedure
	void   toString();            //Procedure
	int    setHoursWorked(int);     //Procedure
	float  setHourlyRate(float);    //Procedure
};

#endif	/* EMPLOYEE_H */

