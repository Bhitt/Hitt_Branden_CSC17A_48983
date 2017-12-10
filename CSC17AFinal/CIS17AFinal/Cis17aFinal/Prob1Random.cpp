/* 
 * File:   Prob1Random.h
 * Author: Branden Hitt
 * Purpose: Implementation for the Prob1Random class
 * Created on December 14, 2015, 5:54 PM
 */
#include "Prob1Random.h"
#include <cstdlib>
Prob1Random::Prob1Random(const char numSet, const char* ptr){
    //set variables
    numRand=0;
    nset=numSet;
    //create copy of set
    set=new char[nset];
    //initialize copy of values
    for(int i=0;i<nset;i++){
        *(set+i)=*(ptr+i);
    }
    //create freq array
    freq=new int[nset];
    //initialize array
    for(int i=0;i<nset;i++){
        *(freq+i)=0;
    }
}
Prob1Random::~Prob1Random(){
    //de-allocate memory
    delete [] freq;
    delete [] set;
}
char Prob1Random::randFromSet(){
    //get rand num
    int cho=rand()%nset;
    //add freq
    freq[cho]++;
    //increment times numRand
    numRand++;
    //return number from set
    return *(set+cho);
}