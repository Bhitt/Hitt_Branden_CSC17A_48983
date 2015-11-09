/* 
 * File:   card.cpp
 * Author: Branden Hitt
 * Created on November 8th, 2015, 8:29 PM
 * Purpose: Implementation for the Numbers Class
 */
#include <iostream>
using namespace std;
//User Library for the Specification
#include "Numbers.h"

Numbers::Numbers(int n){
    num=n;
}
void Numbers::print(){
    //output the thousand value
//    if(num>999){
//        cout<<less[num/1000]<<" "<<thousand;
//    }
//    //output the hundred value
//    if((num%1000)>99){
//        cout<<less[(num%1000)/100]<<" "<<hundred<<" and ";
//    }
//    //output the remaining total
//    if((num%100)>19){
//        cout<<more[((num%100)/10)-1]<<less[(num%10)+1];
//    }else{
//        cout<<less[(num%100)];
//    }
    cout<<num<<endl;
}