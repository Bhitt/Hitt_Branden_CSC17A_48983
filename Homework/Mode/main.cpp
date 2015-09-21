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
void prntAry(int [],int,int);//print
int *modeFil(int [],int);//find mode
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=99;
    int array[SIZE]={};//declare original array
    int copy[SIZE]={};//declare copy of array
    //fill the array
    filAray(array,SIZE);
    //print the original array
    cout<<"Your array:"<<endl;
    prntAry(array,SIZE,10);
    cout<<endl;
    //copy the array
    for(int i=0;i<SIZE;i++){
        copy[i]=array[i];
    }
    //sort the array
    markSrt(copy,SIZE);
    //find the mode and put in a dynamic array
    int *mode=modeFil(copy,SIZE);
    //Output mode
    cout<<endl;
    cout<<"The Number of Modes is: "<<mode[0]<<endl;
    cout<<"The Frequency of the Mode(s) is: "<<mode[1]<<endl;
    
    for(int i=2;i<(mode[0]+2);i++){
        cout<<"Item "<<i-1<<": "<<mode[i]<<endl;
    }
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
    int count=1,freq=1,nOfM=0;
    int m=0;//mode
    //loop for freq and number of modes
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            count++;
        }else{
            if(count>freq){
               freq=count;
               nOfM=1;
            }else if(count==freq){
               nOfM++; 
            }else{
                //do nothing
            }
            count=1;
        }
    }
    //allocate memory
    int *b=new int[m];
    int temp=2;
    //loop for modes
    if(freq<=1){//no modes
        b[0]=0;
        b[1]=1;
    }else{
        //enter the data
        b[0]=nOfM;//number of modes
        b[1]=freq;//frequency of the mode
        //add the modes
        for(int i=0;i<n;i++){
            if(a[i]==a[i+(freq-1)]){
                b[temp]=a[i];
                temp++;
            }else{
                //do nothing
            }
        }
        return b;
    }
    
}