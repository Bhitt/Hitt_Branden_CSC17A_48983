//Branden Hitt
//October 26th, 2015
//Menu to be used for the midterm
//homework and final, etc....

//Library includes Here!!!
#include <iostream>
using namespace std;

//User Libraries
#include "CheckingAcc.h"
#include "GrossPay.h"
#include "LockedNModed.h"
//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
statsResult *avgMedMode(int *,int);
void printStat(statsResult *);
void markSrt(int [], int);
void encrypt();
void decrypt();
bool valid(int);
//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        //Declare Variables
        Chcking user;
        char repeat='x';
        short count=1;
        int checks=0,deposit=0;
        bool overD=false;
        user.ttlChks=0;
        user.deposit=0;
        //Prompt for inputs
        cout<<"In problem # 1"<<endl<<endl;
        cout<<"****************************"<<endl;
        cout<<"Welcome to Fells Wargo."<<endl;
        do{
        cout<<"Please enter in your account number now:"<<endl;
        cin>>user.accNum;
        if(user.accNum>99999||user.accNum<10000)cout<<"Invalid Entry"<<endl;
        }while(user.accNum>99999||user.accNum<10000);
        cout<<"What was the balance at the beginning of the month?:"<<endl;
        cin>>user.begBal;
        cout<<"Enter in your check amounts this month."<<endl;
        do{
            cout<<"Check "<<count<<":"<<endl;
            cin>>checks;
            count++;
            user.ttlChks+=checks;
            cout<<"Would you like to enter another check?"<<endl;
            cout<<"Enter in Y for yes or N for no"<<endl;
            cin>>repeat;
        }while(repeat=='Y'||repeat=='y');
        cout<<"Enter in your deposit amounts this month."<<endl;
        count=1;
        do{
            cout<<"Deposit "<<count<<":"<<endl;
            cin>>deposit;
            count++;
            user.deposit+=deposit;
            cout<<"Would you like to enter another check?"<<endl;
            cout<<"Enter in Y for yes or N for no"<<endl;
            cin>>repeat;
        }while(repeat=='Y'||repeat=='y');
        //calculate the new balance
        user.begBal+=user.deposit;
        user.begBal-=user.ttlChks;
        //check for overdraw
        if(user.begBal<0){
            user.begBal-=15;
            overD=true;
        }
        cout<<endl;
        if(overD)cout<<"You have overdrawn and will be charged an additional $15"<<endl;
        cout<<"Account number:"<<user.accNum<<endl;
        cout<<"Balance: $"<<user.begBal<<endl;
        cout<<"****************************"<<endl;
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
        cout<<"****************************"<<endl;
        //create dynamic array of structures
        
        //fill structures
        
        //calculate gross pay
        
        //loop and output
        cout<<"****************************"<<endl;
}

void problem3(){
        //Declare Variables
        int size;
        statsResult *stats;
        cout<<"In problem # 3"<<endl<<endl;
        cout<<"****************************"<<endl;
        cout<<"MEAN MEDIAN AND MODE"<<endl;
        //prompt for size of array
        cout<<"How many inputs do you want for the array?"<<endl;
        cin>>size;
        //create the array and fill it
        int array[size]={};
        for(int i=0;i<size;i++){
            cout<<"Input the integer at index "<<i<<":"<<endl;
            cin>>array[i];
        }
        //sort the array
        markSrt(array,size);
        //send array into function
        stats=avgMedMode(array,size);
        //print results held in structure
        printStat(stats);
        //de-allocate memory
        delete []stats->mode;
        delete stats;
        cout<<"****************************"<<endl;
}

void problem4(){
        char repeat='X',cho='O';
        cout<<"In problem # 4"<<endl<<endl;
        cout<<"****************************"<<endl;
        do{
            cout<<"Would you like to encrypt or decrypt?"<<endl;
            cout<<"Enter in E for encrypt or D for decrypt:"<<endl;
            cin>>cho;
            if(cho=='E'||cho=='e') encrypt();
            if(cho=='D'||cho=='d') decrypt();
            cout<<endl;
            cout<<"Would you like to encrypt or decrypt another number?"<<endl;
            cout<<"Enter in Y for yes or N for no:"<<endl;
            cin>>repeat;
            cout<<endl;
        }while(repeat=='Y'||repeat=='y');
        
        cout<<"****************************"<<endl;
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
        cout<<"****************************"<<endl;
        
        cout<<"****************************"<<endl;
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
        cout<<"****************************"<<endl;
        
        cout<<"****************************"<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

statsResult *avgMedMode(int *a,int s){
        //allocate memory
        statsResult *temp=new statsResult;
        //declare variables
        float av=0;
        int count=1,freq=1,nOfM=0;
        int m=0,med=0;//mode
        //find average
        for(int i=0;i<s;i++){
            av+=a[i];
        }
        av/=s;
        temp->avg=av;
        //find median
        med=(s+1)/2;
        temp->median=a[med+1];
        //find freq and number of modes
        for(int i=0;i<s;i++){
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
        temp->nModes=nOfM;
        temp->maxFreq=freq;
        //allocate memory
        temp->mode=new int[nOfM];
        count=0;
        for(int i=0;i<s;i++){
            if(a[i]==a[i+(freq-1)]){
                temp->mode[count]=a[i];
                count++;
            }else{
                //do nothing
            }
        }
        //return temp
        return temp;
        
}

void printStat(statsResult *s){
        cout<<"Average         : "<<s->avg<<endl;
        cout<<"Median          : "<<s->median<<endl;
        cout<<"Mode(s)         : ";
        for(int i=0;i<s->nModes;i++){
            cout<<s->mode[i]<<" ";
        }
        cout<<endl;
        cout<<"Number of Modes : "<<s->nModes<<endl;
        cout<<"Max Freq        : "<<s->maxFreq<<endl;
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

void encrypt(){
        //declare variables
        bool error=false;
        int user,end=0;
        //prompt for number and validate
        do{
            cout<<"What is the number you wish to encrypt"<<endl;
            cin>>user;
            error=valid(user);
            if(error)cout<<"Invalid Input"<<endl;
        }while(error);
        //get numbers individually
        int a=0,b=0,c=0,d=0,temp=0;
        a=user/1000;
        b=(user%1000)/100;
        c=((user%1000)%100)/10;
        d=((user%1000)%100)%10;
        //sum digits with 5
        a+=5,b+=5,c+=5,d+=5;
        //mod 8
        a%=8,b%=8,c%=8,d%=8;
        //swap
        temp=a;
        a=b;
        b=temp;
        temp=c;
        c=d;
        d=temp;
        //put back to one integer
        end=a*1000;
        end+=b*100;
        end+=c*10;
        end+=d;
        //output the encrypted number
        cout<<"Your encrypted result is "<<end<<endl;
}

void decrypt(){
    //declare variables
    int user,end=0;
    bool error=false;
    //prompt for number and validate
    do{
        cout<<"What is the number you would like to decrypt?"<<endl;
        cin>>user;
        error=valid(user);
        if(error)cout<<"Invalid Input"<<endl;
    }while(error);
    //get numbers individually
    int a=0,b=0,c=0,d=0,temp=0;
    a=user/1000;
    b=(user%1000)/100;
    c=((user%1000)%100)/10;
    d=((user%1000)%100)%10;
    //unswap
    temp=a;
    a=b;
    b=temp;
    temp=c;
    c=d;
    d=temp;
    //take away the remainder
    if(a<=4)a+=8;
    if(b<=4)b+=8;
    if(c<=4)c+=8;
    if(d<=4)d+=8;
    //take away 5
    a-=5,b-=5,c-=5,d-=5;
    //put back to one integer
    end=a*1000;
    end+=b*100;
    end+=c*10;
    end+=d;
    //output the encrypted number
    cout<<"Your decrypted result is "<<end<<endl;
    
}
//input validation
bool valid(int test){
    int a=0,b=0,c=0,d=0;
    a=test/1000;
    b=(test%1000)/100;
    c=((test%1000)%100)/10;
    d=((test%1000)%100)%10;
    //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl; <- testing purposes
    if(test<1000||test>7777)return true;
    else if(a>7||b>7||c>7||d>7)return true;
    else return false;
}