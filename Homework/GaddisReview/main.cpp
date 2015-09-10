/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  C++ Review
 * Modified on Sep 9th, 2015
 */

//System Libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float celsius(float);
//Execution Begins Here
int main(int argc, char** argv) {
    //General Menu Format
    char repeat;
    //Display the selection
    do{
    cout<<"Type 1 to solve problem 3.12"<<endl;
    cout<<"Type 2 to solve problem 3.13"<<endl;
    cout<<"Type 3 to solve problem 4.10"<<endl;
    cout<<"Type 4 to solve problem 5.11"<<endl;
    cout<<"Type 5 to solve problem 6.7"<<endl;
    cout<<"Type 6 to solve problem 7.6"<<endl;
    cout<<"Type 7 to solve problem 8.7"<<endl;
    //Read the choice
    char choice;
    cin>>choice;
    //Solve a problem that has been chosen.
    switch(choice){
        case '1':{
            cout<<"*****************************"<<endl;
            cout<<"What is the month?"<<endl;
            string month;//string variable
            cin>>month;//user input
            cout<<"What year is it?"<<endl;
            int year;//year variable
            cin>>year;//user input for year
            cout<<"What is the total amount collected? (Sales tax plus sales)"<<endl;
            float collect,sales;//sales, total amount collected variables
            cin>>collect;//user input for total amount collected
            sales=collect/1.06;//sales 
            //Output the results
            cout<<"Month: "<<month<<endl;
            cout<<"------------"<<endl;
            cout<<"Total Collected:  $"<<collect<<endl;
            cout<<"Sales:            $"<<sales<<endl;
            cout<<"County Sales Tax: $"<<sales*0.02<<endl;
            cout<<"State Sales Tax:  $"<<sales*0.04<<endl;
            cout<<"Total Sales Tax:  $"<<(sales*0.02)+(sales*0.04)<<endl;
            cout<<"*****************************"<<endl;
                break;
            }
        case '2':{
            cout<<"*****************************"<<endl;
            cout<<"What is the actual value of the property?"<<endl;
            float actual,assess,propTax;//variables
            cin>>actual;//input for actual value
            assess=actual*0.60;//assessment
            propTax=assess*0.0064;//property taxes based on assessment
            cout<<"The assessment value is: $"<<assess<<endl;
            cout<<"The property tax is    : $"<<propTax<<endl;
            cout<<"*****************************"<<endl;
                break;
            }
        case '3':{
            cout<<"*****************************"<<endl;
            int units=0;//units variable
            float cost=99;//cost per unit
            do{//check for positive number
            cout<<"What is the number of units sold?"<<endl;
            cin>>units;//user input for units sold
            }while(units<=0);
            if(units<10)cost=cost*units;//less than 10 units,no discount
            else if(units<19)cost=cost*units-((cost*units)*0.20);//20 percent discount
            else if(units<49)cost=cost*units-((cost*units)*0.30);//30 % discount
            else if(units<99)cost=cost*units-((cost*units)*0.40);//40 % discount
            else cost=cost*units-((cost*units)*0.5);//50 % discount
            cout<<"Your total cost is: $"<<cost<<endl;
            cout<<"*****************************"<<endl;
                break;
            }
        case '4':{
            cout<<"*****************************"<<endl;
            int start=0;//variable for beginning number of organisms
            do{//check for at least 2 organisms to start with
            cout<<"What is the starting number of organisms?"<<endl;
            cin>>start;//input for starting organisms
            }while(start<2);
            cout<<"What is the daily percentage increase? (ex:60 for 60%)"<<endl;
            float incr;//daily increase
            cin>>incr;//input for increase
            incr*=0.010;//turn into a percentage
            cout<<"How many days would you like this to loop?"<<endl;
            int loop=0,day=1;
            cin>>loop;
            //loop for each day
            for(loop;loop>0;loop--){
                cout<<"Day ("<<day<<"): "<<start<<endl;
                day++;
                start+=(start*incr);
            }
            cout<<"*****************************"<<endl;
                break;
            }
        case '5':{
            cout<<"*****************************"<<endl;
            float fare=0,cel=0;//variables
            //loop for each degree conversion
            for(int i=0;i<20;i++){
                cel=celsius(fare);
                cout<<"F: "<<fare<<" | C: "<<cel<<endl;
                fare++;
            }
            cout<<"*****************************"<<endl;
                break;
            }
        case '6':{
            cout<<"*****************************"<<endl;
            //declare variables
            //const int SIZE=20;
            //int array[SIZE]={};
            //fill array
            string name;
            cout<<"What is the file name?"<<endl;
            cin>>name;
            //ofstream outFile;
            //ifstream inFile;
            //inFile.open("name.txt");
            //close the file
            //outFile.close();
            cout<<"*****************************"<<endl;
                break;
            }
        case '7':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
            default:{
                    cout<<"Incorrect Menu Choice"<<endl;
            }      
    };
    cout<<"Would you like to return to the menu? Enter Y for yes or N for no:"<<endl;
    cin>>repeat;
    }while(repeat=='Y'||repeat=='y'); 
    return 0;
}
//celsius function
float celsius(float a){
    float end=5.0/9*(a-32);
    return end;
}