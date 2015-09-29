/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Sept 23, 2015, 11:10 AM
 *      Purpose: hold test scores in dynamic array and find average
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *filScr(int);//fill the array with scores
void prntAry(int *,int,int);//print the array
void markSrt(int *,int);//utilize mark sort to sort the scores
float avgScr(int *,int);//find the average score
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int size=0;
    float average=0;
    //ask for input of scores (account for scores lower than 0))
    cout<<"How many scores would you like to enter?"<<endl;
    cin>>size;
    int *scores=filScr(size);
    //prntAry(scores,size,10);
    //sort the scores
    markSrt(scores,size);
    //find the average
    average=avgScr(scores,size);
    //display sorted scores
    cout<<"Sorted Scores: "<<endl;
    prntAry(scores,size,10);
    //display average
    cout<<"The Average Score: "<<endl;
    cout<<average<<endl;
    //de-allocate memory
    delete []scores;
    //exit stage right
    return 0;
}
//fill scores into array
int *filScr(int n){
    //allocate memory
    int *a=new int[n];
    //fill array
    for(int i=0;i<n;i++){
        cout<<"What is score "<<(i+1)<<"?"<<endl;
        cin>>*(a+i);
        while(*(a+i)<0){
            cout<<"Score cannot be less than zero. Please re-enter:"<<endl;
            cin>>*(a+i);
        }
    }
    return a;
}
//print the array
void prntAry(int *a,int n, int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}
//sort the array
void markSrt(int *a,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int lst=pos+1;lst<n;lst++){
            if(*(a+pos)>*(a+lst)){
                int temp=*(a+pos);
                *(a+pos)=*(a+lst);
                *(a+lst)=temp;
            }
        }
    }
}
//find the average
float avgScr(int *a,int n){
    float avg=0;
    for(int i=0;i<n;i++){
        avg+=*(a+i);
    }
    avg/=n;
    return avg;
}