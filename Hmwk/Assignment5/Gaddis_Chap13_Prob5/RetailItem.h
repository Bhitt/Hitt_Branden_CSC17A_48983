/* 
 * File:   RetailItem.h
 * Author: Administrator
 *
 * Created on November 8, 2015, 4:43 PM
 */

#ifndef RETAILITEM_H
#define	RETAILITEM_H

#include <string>
using namespace std;

class RetailItem{
    private:
        string desc;
        int units;
        float price;
    public:
        RetailItem(string,int,float);   //Constructor
        void setDesc(string);           //Mutator
        void setUnit(int);              //Mutator
        void setPrce(float);            //Mutator
        string getDesc(){return desc;}  //Accessor (in-line)
        int getUnit();                  //Accessor
        float getPrce(){return price;}  //Accessor (in-line)
};

#endif	/* RETAILITEM_H */

