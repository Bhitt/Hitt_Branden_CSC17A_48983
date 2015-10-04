/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: Astrology Program (find user's sign and horoscope)
 */

//System Libraries
#include <iostream>//I/O standard
#include <fstream>//input output
#include <string>//used to turn input into a string
#include <cstring>//used for string length
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int findSiz(string);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    string file1,file2,temp,temp2;
    int size=0;
    ifstream inFile;
    ofstream outFile;
    //Prompt the user for inputs
    cout<<"This program reads in a file, sets every letter to lowercase,"<<endl;
    cout<<" sets the first letter of every sentence to Uppercase,"<<endl;
    cout<<" and finally outputs the results to a second file"<<endl;
    cout<<endl;
    cout<<"What is the name of the first file? (Input)";
    cin>>file1;
    cout<<"What is the name of the second file? (Output)";
    cin>>file2;
    //find size of input file
    size=findSiz(file1);
    //create array
    char array[size]={};
    //open the files
    inFile.open(file1.c_str());
    outFile.open(file2.c_str());
    //add strings to array
    getline(inFile,temp,'.');
    temp+=".";
    while(inFile){
        getline(inFile,temp2,'.');
        temp2+=".";
        temp+=temp2;
    }
    strcpy(array,temp.c_str());
    //correct the file
    for(int i=0;i<size;i++){
        array[i]=tolower(array[i]);//set everything to lower
    }
    array[0]=toupper(array[0]);//First letter is uppercase
    for(int i=0;i<size;i++){
        if((i!=(size-1))&&(i!=(size-2))){
            if(ispunct(array[i])){
                int b=i;
                do{   
                    b++;
                }while(isspace(array[b]));
                array[b]=toupper(array[b]);//Uppercase first letter at beginning of sentence
            }
        }
    }
    //output to the second file
    cout<<endl;
    for(int i=0;i<size-1;i++){
        outFile<<array[i];
    }
    //close the input file
    inFile.close();
    //close the output file
    outFile.close();
    //exit stage right
    return 0;
}
//find the size of the file
int findSiz(string n){
    //declare variables
    ifstream inFile;
    string temp;
    int count=0;
    //open file
    inFile.open(n.c_str());
    getline(inFile,temp,'.');
    temp+=".";
    count=temp.length();
    while(inFile){
        getline(inFile,temp,'.');
        temp+=".";
        count+=temp.length();
    }
    //close file
    inFile.close();
    //return size
    return count;
}