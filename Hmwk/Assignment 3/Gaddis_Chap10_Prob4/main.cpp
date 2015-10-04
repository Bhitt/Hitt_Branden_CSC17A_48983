/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on October 4th, 2015, 12:10 AM
 *      Purpose: Average number of letters
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int wordCnt(char *);//finds the amount of words in a string
float aver(char *, int);//finds the average amount of letters in each word
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=251;
    char user[SIZE]={};//array to hold string
    int wordC=0;//word count
    float avg=0;//average
    //Prompt the user for inputs
    cout<<"Input a string and I will tell you how many words it contains:"<<endl;
    cout<<"(limit "<<SIZE-1<<" characters)"<<endl;
    cin.getline(user,SIZE);//user inputs string
    //test purposes
    for(int i=0;i<SIZE;i++){
        cout<<user[i];
    }
    cout<<endl;
    //pass pointer to function
    wordC=wordCnt(user);
    avg=aver(user,wordC);
    //Output the number of words
    cout<<"Number of words: "<<wordC<<endl;
    //output the average of letters in each word
    cout<<"Average number of letters: "<<avg<<endl;
    return 0;
}
//word count
int wordCnt(char *strPtr){
    int c=0;//count
    while(*strPtr!='\0'){
        if(isspace(*strPtr)){
            strPtr--;
            if(isalpha(*strPtr)){
                c++;
                strPtr++;
            }else{
                strPtr++;
            }
        }else if(ispunct(*strPtr)){
            strPtr--;
            if(isalpha(*strPtr)){
                c++;
                strPtr++;
            }else{
                strPtr++;
            }      
        }else{
            //do nothing
        }
        strPtr++;
    }
    if(*strPtr=='\0'){
            strPtr--;
            if(isalpha(*strPtr)){
                c++;
                strPtr++;
            }else{
                strPtr++;
            }
    }
    return c;
}
//find the average
float aver(char *strPtr, int n){
    if(n!=0){
       float a=0;//average
    float c=0;//count and temp
    while(*strPtr!='\0'){
        if(isalpha(*strPtr)){
            c++;
        }else{
            //do nothing
        }
        strPtr++;
    }
    a=c/n;
    //return average
    return a; 
    }
    return 0;
}