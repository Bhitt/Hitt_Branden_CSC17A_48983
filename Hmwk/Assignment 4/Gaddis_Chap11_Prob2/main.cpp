/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on Oct 7th, 2015, 8:10 PM
 *      Purpose: use a structure to store info
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries
#include "MovieData.h"
//Global Constants

//Function Prototypes
void getData(MovieData &);
void display(MovieData &);
//Execution Begins Here!
int main(int argc, char** argv) {
    //declare Variables
    MovieData mov1;
    MovieData mov2;
    //fill structs
    getData(mov1);
    getData(mov2);
    //output 
    display(mov1);
    cout<<endl;
    display(mov2);
    //exit stage right
    return 0;
}
//fill the structure
void getData(MovieData &p){
    cout<<"What is the movie title?:"<<endl;
    getline(cin, p.title);
    cout<<"What is the directors name?:"<<endl;
    getline(cin, p.direct);
    cout<<"When was the movie release?:"<<endl;
    cin>>p.rlsYear;
    cout<<"What is the run time of the movie (in minutes)?:"<<endl;
    cin>>p.runTime;
    cout<<"What was the production cost of the movie?:"<<endl;
    cin>>p.proCost;
    cout<<"What was the first year's revenue?:"<<endl;
    cin>>p.yr1Rev;
    cin.ignore();
}
//display the structure
void display(MovieData &p){
    cout<<"Title: "<<p.title<<endl;
    cout<<"Director: "<<p.direct<<endl;
    cout<<"Release: "<<p.rlsYear<<endl;
    cout<<"Run Time: "<<p.runTime<<" minutes"<<endl;
    cout<<"Year 1 (profit/loss) $"<<p.yr1Rev-p.proCost<<endl;
}