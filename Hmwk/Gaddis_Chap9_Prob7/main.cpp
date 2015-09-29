/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: edit the book code to sort in descending order
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);
int *filAray(int);
//Execution Begins Here!
int main(){
    //ask for the number of donations
    int size=0;
    cout<<"How many donations are there?"<<endl;
    cin>>size;
    // An array containing the donation amounts.
    int *donations=filAray(size); 
    // An array of pointers to int.
    int *arrPtr[size];
    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < size; count++)
       arrPtr[count] = &donations[count];
    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, size);
    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in descending order, are: \n";
    showArrPtr(arrPtr, size);
    // Display the donations in their original order.
    cout << "The donations, in their original order, are: \n";
    showArray(donations, size);
    //de-allocate memory
    delete []donations;
    //exit stage right
    return 0;
 }
//selection sort
void arrSelectSort(int *arr[], int size){
 int startScan, minIndex;
 int *minElem;

 for (startScan = 0; startScan < (size - 1); startScan++){
    minIndex = startScan;
    minElem = arr[startScan];
    for(int index = startScan + 1; index < size; index++){
        if (*(arr[index]) > *minElem){
            minElem = arr[index];
            minIndex = index;
        }
    }
    arr[minIndex] = arr[startScan];
    arr[startScan] = minElem;
    }
 }
//show array
void showArray(const int arr[], int size){
 for (int count = 0; count < size; count++)
 cout << arr[count] << " ";
 cout << endl;
 }
//show array pointer
void showArrPtr(int *arr[], int size){
 for (int count = 0; count < size; count++)
     cout << *(arr[count]) << " ";
 cout << endl;
}
//enter in donations to the array
int *filAray(int n){
    //allocate memory
    int *a=new int[n];
    //fill the array
    for(int i=0;i<n;i++){
        cout<<"What is donation #"<<(i+1)<<"?"<<endl;
        cin>>a[i];
    }
    return a;
}