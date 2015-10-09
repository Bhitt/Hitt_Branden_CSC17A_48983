/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 9th, 2015, 12:10 PM
 *      Purpose: array of structures with menu
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries
#include "SpeakersBureau.h"
//Global Constants

//Function Prototypes
void filData(SpkrBru *,int);
void pick(SpkrBru *);
void fillEle(SpkrBru );
void display(SpkrBru *,int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char cho='m',repeat='n';
    const int SIZE=2;
    bool skip=false;
    SpkrBru array[SIZE]={};
    //ask for menu choice
    do{
        cout<<"Type 1 to enter data into the structures"<<endl;
        cout<<"Type 2 to change the contents of an element"<<endl;
        cout<<"Type 3 to display all of the data"<<endl;
        cout<<"Type z to exit"<<endl;
        cin>>cho;
        //display menu
        switch(cho){
            case'1':{
                //enter data into array
                filData(array,SIZE);
                break;
            }
            case'2':{
                //change contents of element
                pick(array);
                break;
            }
            case'3':{
                //display array of structures
                display(array,SIZE);
                break;
            }
            case'z':
            case'Z':{
                //exit queue
                skip=true;
                repeat='Y';
            }
        }
        if(skip==false){
            cout<<"Would you like to return to the menu?"<<endl;
            cout<<"Enter Y for yes or N for no:"<<endl;
            cin>>repeat;
        }
    }while(repeat=='Y'||repeat=='y');
    return 0;
}
//fill the data into the structures
void filData(SpkrBru *p,int s){
    for(int i=0;i<s;i++){
        cout<<"SPEAKER "<<i+1<<endl;
        cout<<"What is the speaker's name?:"<<endl;
        cin>>p[i].name;
        cout<<"What is their telephone number?:"<<endl;
        cin>>p[i].number;
        cout<<"What is their speaking topic?:"<<endl;
        cin>>p[i].topic;
        do{
            cout<<"What is their fee required?:"<<endl;
            cin>>p[i].fee;
            if(p[i].fee<0)cout<<"Invalid input"<<endl;
        }while(p[i].fee<0);
        cin.ignore();
        cout<<endl;
    }
}
//fill element
void fillEle(SpkrBru p){
    cout<<"What is the speaker's name?:"<<endl;
    cin>>p.name;
    cout<<"What is their telephone number?:"<<endl;
    cin>>p.number;
    cout<<"What is their speaking topic?:"<<endl;
    cin>>p.topic;
    do{
        cout<<"What is their fee required?:"<<endl;
        cin>>p.fee;
        if(p.fee<0)cout<<"Invalid input"<<endl;
    }while(p.fee<0);
    cout<<endl;
}
//pick element to change
void pick(SpkrBru *a){
    char ele='m',repeat='n';
    bool skip=false;
    do{
        cout<<"Type A to change Speaker 1:"<<endl;
        cout<<"Type B to change Speaker 2:"<<endl;
        cout<<"Type C to change Speaker 3:"<<endl;
        cout<<"Type D to change Speaker 4:"<<endl;
        cout<<"Type E to change Speaker 5:"<<endl;
        cout<<"Type F to change Speaker 6:"<<endl;
        cout<<"Type G to change Speaker 7:"<<endl;
        cout<<"Type H to change Speaker 8:"<<endl;
        cout<<"Type I to change Speaker 9:"<<endl;
        cout<<"Type J to change Speaker 10:"<<endl;
        cout<<"Type Z to exit the menu:"<<endl;
        cin>>ele;
        switch(ele){
            case'A':
            case'a':{
                fillEle(a[0]);
                break;
            }
            case'B':
            case'b':{
                fillEle(a[1]);
                break;
            }
            case'C':
            case'c':{
                fillEle(a[2]);
                break;
            }
            case'D':
            case'd':{
                fillEle(a[3]);
                break;
            }
            case'E':
            case'e':{
                fillEle(a[4]);
                break;
            }
            case'F':
            case'f':{
                fillEle(a[5]);
                break;
            }
            case'G':
            case'g':{
                fillEle(a[6]);
                break;
            }
            case'H':
            case'h':{
                fillEle(a[7]);
                break;
            }
            case'I':
            case'i':{
                fillEle(a[8]);
                break;
            }
            case'J':
            case'j':{
                fillEle(a[9]);
                break;
            }
            case'Z':
            case'z':{
                skip=true;
                repeat='Y';
            }
            default:{
                cout<<"Incorrect menu choice"<<endl;
            }
        }
        if(!skip){
            cout<<"Would you like to return to the menu?"<<endl;
            cout<<"Enter Y for yes or N for no:"<<endl;
            cin>>repeat;
        }
    }while(repeat=='Y'||repeat=='y');
}
//display the array of structures
void display(SpkrBru *p,int s){
    for(int i=0;i<s;i++){
        cout<<"SPEAKER "<<i+1<<endl;
        cout<<"NAME: "<<p[i].name<<endl;
        cout<<"TELEPHONE: "<<p[i].number<<endl;
        cout<<"TOPIC: "<<p[i].topic<<endl;
        cout<<"FEE: $"<<p[i].fee<<endl;
        cout<<endl;
    }
}