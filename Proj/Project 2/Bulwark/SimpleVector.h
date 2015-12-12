/* 
 * File:   SimpleVector.h
 * Author: Branden Hitt
 * Purpose: specification and implementation of a vector template
 * Created on December 11, 2015, 2:30 PM
 */

#ifndef SIMPLEVECTOR_H
#define	SIMPLEVECTOR_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arrSize;      // Number of elements in the array
   int alSize;       // Size of the allocated array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arrSize = 0; alSize=0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arrSize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //push function
   void pushEle(T);
   
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arrSize = s;
   alSize= 2*s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [alSize];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arrSize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arrSize = obj.arrSize;
   
   // Allocate memory for the array.
   aptr = new T [arrSize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arrSize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arrSize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arrSize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arrSize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Push function                                        *
//                                                      *
//                                                      *
//*******************************************************

template <class T>
void SimpleVector<T>::pushEle(T newEle){
   //check the allocated size
   if(alSize<=(arrSize+1)){
       //double allocated size
       alSize*=2;
       // Copy the array size.
       arrSize+=1;

       // Allocate memory for the array.
       T *nAptr = new T [alSize];
       cout<<"New allocation"<<endl;
       // Copy the elements of obj's array.
       for(int count = 0; count < arrSize; count++)
          *(nAptr + count) = *(aptr + count);

       //Add the new element at the end
       *(nAptr + (arrSize-1))=newEle;

       //delete old array
       delete []aptr;

       //set pointer to new array
       aptr=nAptr;
   }else{
       //add new element
       *(aptr + arrSize)= newEle;
       //increment array size
       arrSize++;
   } 
   
}

#endif	/* SIMPLEVECTOR_H */

