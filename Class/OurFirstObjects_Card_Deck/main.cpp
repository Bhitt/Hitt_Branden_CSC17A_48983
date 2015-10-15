/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on October 15, 2015, 11:22 AM
 * Purpose: 
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//User Libraries
#include "card.h"
//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare some variables
    
    //Loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=1;i<=52;i++){
        Card card(i);
        cout<<"Card Number = "<<static_cast<int>(card.getNum())<<" Suit = "<<card.suit();
        cout<<" Numerical Value = "<<static_cast<int>(card.numVal());
        cout<<" Face Value = "<<card.faceVal()<<endl;
    }
     
        
    return 0;
}