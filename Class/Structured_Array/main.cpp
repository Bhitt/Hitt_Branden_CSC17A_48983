/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on October 1, 2015, 12:11 PM
 * Purpose: Self Contained Array
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Library
#include "Array.h"

//Global Constants

//Function Prototypes
Array *fillAry(int);
void prntAry(Array *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed and size the array
    srand(static_cast<unsigned int>(time(0)));
    int size=100,perLine=10;
    //Declare and size our ADT
    Array *array=fillAry(size);
    //print the results
    prntAry(array,perLine);
    //Destroy/Deallocate memory
    delete []array->data;
    delete array;
    //Exit stage right
    return 0;
}

void prntAry(Array *a,int perLine){
    for(int indx=0;indx<a->size;indx++){
        cout<<a->data[indx]<<" ";
        if(indx%perLine==(perLine-1)) cout<<endl;
    }
}

Array *fillAry(int n){
    //Check n
    if(n<=1)n=2;
    //Allocate memory
    Array *a=new Array;
    //a->size=n;
    (*a).size=n;
    a->data=new int[a->size];
    //Loop and fill with a random number
    for(int indx=0;indx<a->size;indx++){
        //a->data[indx]=rand()%90+10;
        //(*a).data[indx]=rand()%90+10;
        (*a).data[indx]=rand()%90+10;//convert to pointer notation
    }
    //Exit
    return a;
}

