/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 8th, 2015, 12:45 PM
 *      Purpose: store weather data using array of structures
 */

//System Libraries
#include <iostream>

#include "WeatherData.h"//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filData(WthData *,int);
void display(WthData *,int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=12;//months in a year
    WthData yrData[SIZE];//array of structures
    //Prompt the user for inputs into individual structures
    filData(yrData,SIZE);
    //Output the results
    cout<<endl;
    display(yrData,SIZE);
    //exit stage right
    return 0;
}
void filData(WthData *p, int s){
    for(int i=0;i<s;i++){//loop through year
        cout<<"MONTH "<<i+1<<endl;
        cout<<"What was the total rainfall?:"<<endl;
        cin>>p[i].ttlRain;
        do{
            cout<<"What was the highest temperature? (Fahrenheit):"<<endl;
            cin>>p[i].hiTemp;
            if(p[i].hiTemp<-100 || p[i].hiTemp>140)cout<<"Invalid input"<<endl;
        }while(p[i].hiTemp<-100 || p[i].hiTemp>140);
        do{
            cout<<"What was the lowest temperature? (Fahrenheit):"<<endl;
            cin>>p[i].lowTemp;
            if(p[i].lowTemp<-100 || p[i].lowTemp>140)cout<<"Invalid input"<<endl;
        }while(p[i].lowTemp<-100 || p[i].lowTemp>140);
        //calculate avg temp
        p[i].avgTemp=(p[i].hiTemp+p[i].lowTemp)/2;
    
    }
}
//display the structure
void display(WthData *p,int s){
    //declare variables
    float avgRain=0;
    float rainfall=0;
    float highest=-100;
    float lowest=140;
    int month1=0,month2=0;
    float avgAvg=0;
    //calculate average and total rainfall for the year
    for(int i=0;i<s;i++){
        rainfall+=p[i].ttlRain;
        avgRain+=p[i].ttlRain;
    }
    avgRain/=12;
    //find highest and lowest temp
    for(int i=0;i<s;i++){
        if(p[i].hiTemp>highest){
            highest=p[i].hiTemp;
            month1=i+1;
        }
        if(p[i].lowTemp<lowest){
            lowest=p[i].lowTemp;
            month2=i+1;
        }
    }
    //find average of monthly average temperatures
    for(int i=0;i<s;i++){
        avgAvg+=p[i].avgTemp;
    }
    avgAvg/=12;
    //display
    cout<<"Average Monthly Rainfall   :"<<avgRain<<endl;
    cout<<"Total Rainfall             :"<<rainfall<<endl;
    cout<<"Highest temperature        :"<<highest<<endl;
    cout<<"         (month "<<month1<<")"<<endl;
    cout<<"Lowest temperature         :"<<lowest<<endl;
    cout<<"         (month "<<month2<<")"<<endl;
    cout<<"Average of monthly averages:"<<avgAvg<<"(Fahrenheit)"<<endl;
    
}
