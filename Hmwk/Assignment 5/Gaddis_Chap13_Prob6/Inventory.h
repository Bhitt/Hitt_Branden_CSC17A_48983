/* 
 * File:   Inventory.h
 * Author: Branden Hitt
 * Purpose : Specification for the Inventory Class 
 * Created on November 8, 2015, 5:04 PM
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

class Inventory{
    private:
        int itemNum;
        int quantty;
        float cost;
        float ttlCost;
    public:
        Inventory();                        //Default Constructor
        Inventory(int,float,int);           //Constructor #2
        void setItem(int);                  //Mutator
        void setQuan(int);                  //Mutator
        void setCost(float);                //Mutator
        void setTCst();                     //Mutator
        int getItem(){return itemNum;}      //Accessor (in-line)
        int getQuan();                      //Accessor
        float getCost(){return cost;}       //Accessor (in-line)
        float getTCst(){return ttlCost;}    //Accessor (in-line)
        
};

#endif	/* INVENTORY_H */

