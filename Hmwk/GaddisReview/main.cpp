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
int binarySearch(const string [], int, string);
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
            int thsMany=0;
            string name;
            int lowest,highest,total=0,avg=0,number;
            //fill array
            cout<<"What is the file name?"<<endl;
            cout<<"(taco.txt can be used if you have no prepared file)"<<endl;
            cin>>name;
            ifstream inFile;
            //int val1,val2,val3,val4,val5; used for testing
            string test;
            //ifstream inFile;
            inFile.open(name.c_str());
            //find size of array
            while(inFile>>number){
                thsMany++;
            }
            inFile.close();
            inFile.open(name.c_str());
            const int PIZE=thsMany;
            int array[PIZE]={};
            if(inFile){
                for(int i=0;i<PIZE;i++){
                    inFile>>array[i];
                    
                }   
            }else{
                //display error message
                cout<<"Error opening the File"<<endl;
            }
            //see if the array was filled
            lowest=array[0];
            highest=array[0];
            for(int i=0;i<PIZE;i++){
                if(array[i]<lowest){
                    lowest=array[i];
                }
                if(array[i]>highest){
                    highest=array[i];
                }
                total+=array[i];
            }
            avg=total/PIZE;
            //output the results
            cout<<"The lowest number in the array: "<<lowest<<endl;
            cout<<"The highest number in the array: "<<highest<<endl;
            cout<<"The total of the numbers: "<<total<<endl;
            cout<<"The average of the numbers: "<<avg<<endl;
            //close the file
            inFile.close();
            cout<<"*****************************"<<endl;
                break;
            }
        case '7':{
            cout<<"*****************************"<<endl;
            //
            const int NUM_NAMES = 20;
            // Array with employee IDs sorted in ascending order.
            string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
            "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
            "Taylor, Terri", "Johnson, Jill",
            "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
            "James, Jean", "Weaver, Jim", "Pore, Bob",
            "Rutherford, Greg", "Javens, Renee",
            "Harrison, Rose", "Setzer, Cathy",
            "Pike, Gordon", "Holland, Beth" };
            int results; // To hold the search results
            string empID; // To hold an employee ID

            // Get an employee ID to search for.
            cout << "Enter the employee name you wish to search for: ";
            cin >> empID;

            // Search for the ID.
            results = binarySearch(names, NUM_NAMES, empID);

            // If results contains -1 the ID was not found.
            if (results == -1)
            cout << "That number does not exist in the array.\n";
            else
            {
            // Otherwise results contains the subscript of
            // the specified employee ID in the array.
            cout << "That employee is found at element " << results;
            cout << " in the array.\n";
            }
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
//binary search
int binarySearch(const string array[], int size, string value)
 {
 int first = 0, // First array element
 last = size - 1, // Last array element
 middle, // Midpoint of search
 position = -1; // Position of search value
 bool found = false; // Flag

 while (!found && first <= last)
 {
 middle = (first + last) / 2; // Calculate midpoint
 if (array[middle] == value) // If value is found at mid
 {
 found = true;
 position = middle;
 }
 else if (array[middle] > value) // If value is in lower half
 last = middle - 1;
 else
 first = middle + 1; // If value is in upper half
 }
 return position;
 }