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
    int array[SIZE]={1,2,3,4,5,6,7,8,9,10};
    int *ptr;
    string fName;
    int deets;
    //set pointer to array
    ptr=array;
    deets=sizeof(array);//size of array in bites
    //Prompt the user for inputs
    cout<<"What is the name of the binary file?"<<endl;
    cin>>fName;
    //call array to file function
    aryToFl(fName,ptr,deets);
    //call file to array function
    flToAry(fName,ptr,deets);
    //Output the array
    for(int i=0;i<SIZE;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    //exit stage right
    return 0;
}
//array to file
void aryToFl(string s,int *a,int b){
    //open the file in binary mode
    fstream fout;
    fout.open(s.c_str(),ios::out | ios::binary);
    //file is opened
    if(fout.is_open()){
        //write the contents of the array into the file
        cout<<"Writing the characters to the file..."<<endl;
        fout.write(reinterpret_cast<char *>(a),b);
    }else{
        cout<<"Error opening file for output"<<endl;
    }
    //close the file
    fout.close();
}
//file to array
void flToAry(string s,int *a,int b){
    //open the file
    fstream fin;
    fin.open(s.c_str(), ios::in | ios::binary);
    //file is opened
    if(fin.is_open()){
        //read in the contents of the file
        cout<<"Reading the contents of the file..."<<endl;
        fin.read(reinterpret_cast<char *>(a),b);
    }else{
        cout<<"Error opening file for input"<<endl;
    }
    //close the file
    fin.close();
}