/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 4th, 2015, 1:10 PM
 *      Purpose: Vowels and consonants
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fill(char [],const int);//enter new string into array
int vowC(char *);//vowel count function
int conC(char *);//consonant count function
int allC(char *);//both consonants and vowels
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char ans='n';
    const int SIZE=251;//size of char array
    char user[SIZE]={};//initiate array
    int vowelsC=0,consC=0,both=0;//count for vowels, consonants, and both
    //get first string
    cout<<"Please enter in a string (limit "<<SIZE-1<<" characters):"<<endl;
    cin.getline(user,SIZE);//user inputs the string
    //loop as many times as the user wants
    do{
        //declare variables
        //Prompt the user for inputs
        cout<<"Enter in the letter of your choice:"<<endl;
        cout<<"A) Count the number of vowels:"<<endl;
        cout<<"B) Count the number of consonants:"<<endl;
        cout<<"C) Count both the vowels and consonants:"<<endl;
        cout<<"D) Enter another string:"<<endl;
        cout<<"E) Exit the program:"<<endl;
        char cho='F';
        cin>>cho;
        //menu
        switch(cho){
            case 'A':
            case 'a':{
                vowelsC=vowC(user);
                cout<<"Vowels    : "<<vowelsC<<endl;
                break;
            }
            case 'B':
            case 'b':{
                consC=conC(user);
                cout<<"Consonants: "<<consC<<endl;
                break;
            }
            case 'c':
            case 'C':{
                both=allC(user);
                cout<<"Letters   : "<<both<<endl;
                break;
            }
            case 'D':
            case 'd':{
                cin.ignore();
                fill(user,SIZE);
                break;
            }
            case 'E':
            case 'e':{
                ans='e';
                break;
            }
            default:{
                cout<<"Incorrect menu choice"<<endl;
            }
        };
    }while(ans!='E'&&ans!='e');
    //Exit stage right
    return 0;
}
//fill string into array
void fill(char a[], const int s){
    cout<<"Please enter in a string (limit "<<s-1<<" characters):"<<endl;
    cin.getline(a,s);//user inputs the string
}
//vowel count
int vowC(char *strPtr){
    int c=0;//counter
    while(*strPtr!='\0'){
        if(isalpha(*strPtr)){//if it is a letter
            if(*strPtr=='a'||*strPtr=='A'){
                c++;
            }
            if(*strPtr=='e'||*strPtr=='E'){
                c++;
            }
            if(*strPtr=='i'||*strPtr=='I'){
                c++;
            }
            if(*strPtr=='o'||*strPtr=='O'){
                c++;
            }
            if(*strPtr=='u'||*strPtr=='U'){
                c++;
            }
        }
        //increment
        strPtr++;
    }
    //return the count
    return c;
}
//consonant count
int conC(char *strPtr){
    int c=0;//counter
    while(*strPtr!='\0'){
        if(isalpha(*strPtr)){//if it is a letter
            if((*strPtr!='a')&&(*strPtr!='A')&&(*strPtr!='e')&&(*strPtr!='E')
               &&(*strPtr!='i')&&(*strPtr!='I')&&(*strPtr!='o')&&(*strPtr!='O')
               &&(*strPtr!='u')&&(*strPtr!='U')){
                c++;
            }
        }
        //increment
        strPtr++;
    }
    //return the count
    return c;
}
//both count
int allC(char *strPtr){
    int c=0;
    while(*strPtr!='\0'){
        if(isalpha(*strPtr)){
            c++;
        }
        //increment
        strPtr++;
    }
    //return the count
    return c;
}