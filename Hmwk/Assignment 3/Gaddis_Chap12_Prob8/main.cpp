/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 4th, 2015, 10:30 PM
 *      Purpose: read in a binary file
 */

//System Libraries
#include <iostream>//I/O standard
#include <fstream>//file i/o
#include <string>//string usage
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void aryToFl(string,int *,const int);
void flToAry(string,int *,const int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=10;
    int array[SIZE]={2,4,6,8,0,1,3,5,7,9};
    int *a= array;
    string fName;
    //Prompt the user for inputs
    cout<<"What is the name of the binary file?"<<endl;
    cin>>fName;
    //call array to file function
    aryToFl(fName,array,SIZE);
    //Output 
    cout<<"done";
    //exit stage right
    return 0;
}
//array to file
void aryToFl(string s,int *a,const int b){
    //open the file in binary mode
    fstream fout;
    fout.open(s.c_str(),ios::out | ios::binary);
    //write the contents of the array into the file
    if(fout.is_open()){
        //file is opened
        for(int i=0;i<b;i++){
            fout.write(reinterpret_cast<char *>(a),1);
        }
        
    }
    //close the file
    fout.close();
}
//file to array
void flToAry(string s,int *a,const int b){
    
}