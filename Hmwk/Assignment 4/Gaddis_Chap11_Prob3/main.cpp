/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: use a structure to store data 
 */

//System Libraries
#include <iostream>//I/O standard
#include <iomanip>//format
using namespace std;

//User Libraries
#include "CorpData.h"
//Global Constants

//Function Prototypes
void filCorp(CorpData &);
void display(CorpData &);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    CorpData com1;
    CorpData com2;
    CorpData com3;
    CorpData com4;
    //Fill the structures
    cout<<"Company Division 1 Input"<<endl;
    filCorp(com1);
    cout<<"Company Division 2 Input"<<endl;
    filCorp(com2);
    cout<<"Company Division 3 Input"<<endl;
    filCorp(com3);
    cout<<"Company Division 4 Input"<<endl;
    filCorp(com4);
    //Output 
    cout<<"***********************"<<endl;
    cout<<endl;
    display(com1);
    display(com2);
    display(com3);
    display(com4);
    //exit stage right
    return 0;
}
//fill corpdata
void filCorp(CorpData &p){
    cout<<"What is the division name?:"<<endl;
    cin>>p.name;
    do{
        cout<<"What were the sales for the first quarter?:"<<endl;
        cin>>p.qt1;
        if(p.qt1<0)cout<<"Invalid Input"<<endl;
    }while(p.qt1<0);
    do{
        cout<<"What were the sales for the second quarter?:"<<endl;
        cin>>p.qt2;
        if(p.qt2<0)cout<<"Invalid Input"<<endl;
    }while(p.qt2<0);
    do{
        cout<<"What were the sales for the third quarter?:"<<endl;
        cin>>p.qt3;
        if(p.qt3<0)cout<<"Invalid Input"<<endl;
    }while(p.qt3<0);
    do{
        cout<<"What were the sales for the fourth quarter?:"<<endl;
        cin>>p.qt4;
        if(p.qt4<0)cout<<"Invalid Input"<<endl;
    }while(p.qt4<0);
    p.annual=(p.qt1+p.qt2+p.qt3+p.qt4);
    p.average=(p.annual)/4;
    cin.ignore();
    cout<<endl;
}
//display the structure
void display(CorpData &p){
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Division: "<<p.name<<endl;
    cout<<"Annual sales: $"<<p.annual<<endl;
    cout<<"Average Quarterly Sales: $"<<p.average<<endl;
    cout<<endl;
}