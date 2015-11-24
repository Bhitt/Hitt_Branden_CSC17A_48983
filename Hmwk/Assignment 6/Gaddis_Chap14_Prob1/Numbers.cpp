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

string Numbers::less[20]={"zero","one","two","three","four","five","six","seven",
                   "eight","nine","ten","eleven","twelve","thirteen",
                   "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string Numbers::more[8] = {"twenty-","thirty-","forty-","fifty-","sixty-",
                                   "seventy-","eighty-","ninety-"};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

Numbers::Numbers(int n){
    num=n;
}
void Numbers::print(){
    //output the thousand value
    if(num>999){
        cout<<less[num/1000]<<" "<<thousand<<" ";
    }
    //output the hundred value
    if((num%1000)>99){
        cout<<less[(num%1000)/100]<<" "<<hundred<<" and ";
    }
    //output the remaining total
    if((num%100)>19){
        cout<<more[((num%100)/10)-2]<<less[(num%10)];
    }else{
        cout<<less[(num%100)];
    }
}