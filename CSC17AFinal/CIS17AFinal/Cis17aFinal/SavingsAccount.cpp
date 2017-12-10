/* 
 * File:   SavingsAccount.h
 * Author: Branden Hitt
 * Purpose: SavingsAccount implementation
 * Created on December 18, 2015, 12:55 AM
 */
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
using namespace std;

SavingsAccount::SavingsAccount(float bal){
    if(bal<0) bal=0;
    Balance=bal;
    FreqWithDraw=0;
    FreqDeposit=0;
    place=1;
}
void SavingsAccount::Transaction(float trans){
    if(trans>0) Deposit(trans);
    else Withdraw(trans);
}
float SavingsAccount::Deposit(float trans){
    Balance+=trans;
    FreqDeposit++;
}
float SavingsAccount::Withdraw(float trans){
    if(trans<Balance) {
        Balance-=trans;
        FreqWithDraw++;
    }
    else cout<<"You cannot withdraw more than your current balance"<<endl;
}
void SavingsAccount::toString(){
    cout<<"Balance               : $"<<setprecision(2)<<fixed<<Balance<<endl;
    cout<<"Frequency of Deposits : "<<FreqDeposit<<endl;
    cout<<"Frequency of Withdraws: "<<FreqWithDraw<<endl;
}
float SavingsAccount::Total(float savint, int time){
    for(int i=0;i<time;i++){
        place*=(1+savint);
    }
    return (Balance*place);
}
float SavingsAccount::TotalRecursive(float savint, int time){
    place*=(1+savint);
    time--;
    if(time>0){
        TotalRecursive(savint,time);
    }
    return (Balance*place);
}