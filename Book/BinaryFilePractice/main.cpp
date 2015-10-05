/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 5th, 2015, 10:10 AM
 *      Purpose: Practice sending binary data to a file
 */

//System Libraries
#include <iostream>//I/O standard
#include <fstream>// file i/o
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    fstream file;
    char letter='A';
    //Open the file
    file.open("binary.dat",ios::out | ios::binary);
    //Output 
    file.write(&letter, sizeof(letter));
    
    //close the file
    file.close();
    
    
    //****send array to binary file
    const int SIZE=10;
    int numbers[SIZE]={1,2,3,4,5,6,7,8,9,10};
    //open file
    file.open("binary2.dat", ios::out | ios::binary);
    //write to file
    cout<<"Writing the contents of int array to the file"<<endl;
    file.write(reinterpret_cast<char *>(numbers),sizeof(numbers));
    //close file
    file.close();
    //open file for input
    file.open("binary2.dat", ios::in | ios::binary);
    cout<<"Now reading the data back into memory"<<endl;
    file.read(reinterpret_cast<char *>(numbers),sizeof(numbers));
    //display array
    for( int i=0;i<SIZE;i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
    //close the file
    file.close();
    //exit stage right
    return 0;
}