/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on September 20, 2015, 10:10 PM
 *      Purpose: Find the mode and input it into new array
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filAray(int [],int);//fill
void markSrt(int [], int);//sort
void cpyAray(int [], int);//copy
void prntAry(int [],int,int);//print
int *modeFil(int [],int);//find mode
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=19;
    int array[SIZE]={};//declare original array
    int copy[SIZE]={};//declare copy of array
    //fill the array
    filAray(array,SIZE);
    //print the original array
    prntAry(array,SIZE,10);
    //copy the array
    for(int i=0;i<SIZE;i++){
        copy[i]=array[i];
    }
    //sort the array
    markSrt(copy,SIZE);
    //find the dynamic mode array
    int *mode=modeFil(copy,SIZE);
    
    //Output dynamic array
    
    //De-allocate memory
    delete []mode;
    //Exit stage right
    return 0;
}
//fill the array
void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=i%5;
    }
}
//print the array
void prntAry(int a[],int n, int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
}
//sort the array
void markSrt(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        for(int lst=pos+1;lst<n;lst++){
            if(a[pos]>a[lst]){
                int temp=a[pos];
                a[pos]=a[lst];
                a[lst]=temp;
            }
        }
    }
}
//find the mode and freq
int *modeFil(int a[],int n){
    //declare variables
    int count=0,temp=0;
    int m=0;//mode
    //loop for mode
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            count++;
        }else{
            if(count>temp){
               temp=count; 
            }
            count=0;
        }
    }
}