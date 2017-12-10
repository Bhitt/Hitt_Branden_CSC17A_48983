/* 
 * File:   Prob2Sort.h
 * Author: Branden Hitt
 * Purpose: template for sorting a 2D array represented as a 1D array
 * Created on December 14, 2015, 8:21 PM
 */

#ifndef PROB2SORT_H
#define	PROB2SORT_H

template<class T>
class Prob2Sort
{
    private:
        int *index;                                 //Index that is utilized in the sort
    public:
	Prob2Sort(){index=NULL;};                   //Constructor
	~Prob2Sort(){delete []index;};              //Destructor
	T * sortArray(const T*,int,bool);           //Sorts a single column array
	T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
};

//sort array
template<class T>
T * Prob2Sort<T>::sortArray(const T* ptr, int size, bool asc){
    //create new array and index
    T* array= new T[size];
    index = new int[size];
    //set index to values
    for(int i=0;i<size;i++){
        index[i]=i;
    }
    //set new array equal to the pointed array
    for(int i=0;i<size;i++){
        array[i]=*(ptr+i);
    }
    //loop through items
    for(int pos=0;pos<size;pos++){
        for(int lst=pos+1;lst<size;lst++){
            if(asc){
                if(array[pos]<array[lst]){
                    //swap the numbers
                    T temp=array[pos];
                    array[pos]=array[lst];
                    array[lst]=temp;
                    //set index
                    int tomp=index[pos];
                    index[pos]=index[lst];
                    index[lst]=tomp;
                }
            }else{
               if(array[pos]>array[lst]){
                    //swap the numbers
                    T temp=array[pos];
                    array[pos]=array[lst];
                    array[lst]=temp;
                    //set index
                    int tomp=index[pos];
                    index[pos]=index[lst];
                    index[lst]=tomp;
                } 
            }
        }
    }
    //return array
    return array;
}
//sort 2d array
template<class T>
T * Prob2Sort<T>::sortArray(const T* ptr, int r, int c, int colSrt, bool asc){
    //create new array and index
    T* array= new T[r*c];
    index = new int[r*c];
    //set index to values
    for(int i=0;i<r*c;i++){
        index[i]=i;
    }
    //set new array equal to the values of the input array
    for(int i=0;i<r*c;i++){
        array[i]=*(ptr+i);
    }
    //loop through items
    for(int pos=(colSrt-1);pos<r*c;pos+=c){
        for(int lst=pos+c;lst<r*c;lst+=c){
        //check for swap
            if(asc){//if sort is by ascending
                if(array[pos]<array[lst]){
                    //loop and swap the rows
                    for(int i=0;i<c;i++){
                        //set array
                        T temp=array[(pos-(colSrt-1))+i];
                        array[(pos-(colSrt-1))+i]=array[(lst-(colSrt-1))+i];
                        array[(lst-(colSrt-1))+i]=temp;
                        //set index
                        int tomp=index[(pos-(colSrt-1))+i];
                        index[(pos-(colSrt-1))+i]=index[(lst-(colSrt-1))+i];
                        index[(lst-(colSrt-1))+i]=tomp;
                    }
                }  
            }else{//if sort is by descending
                if(array[pos]>array[lst]){
                    //loop and swap the rows
                    for(int i=0;i<c;i++){
                        //set array
                        T temp=array[(pos-(colSrt-1))+i];
                        array[(pos-(colSrt-1))+i]=array[(lst-(colSrt-1))+i];
                        array[(lst-(colSrt-1))+i]=temp;
                        //set index
                        int tomp=index[(pos-(colSrt-1))+i];
                        index[(pos-(colSrt-1))+i]=index[(lst-(colSrt-1))+i];
                        index[(lst-(colSrt-1))+i]=tomp;
                    }
                } 
            }
             
         }
    }
    //return new sorted array
    return array;
}
#endif	/* PROB2SORT_H */

