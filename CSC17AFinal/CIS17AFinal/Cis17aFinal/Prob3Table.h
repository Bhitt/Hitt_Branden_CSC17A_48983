/* 
 * File:   Prob3Table.h
 * Author: Branden Hitt
 * Purpose: Specification and implementation for the Prob3Table template
 * Created on December 14, 2015, 10:10 PM
 */

#include <fstream>
using namespace std;

#ifndef PROB3TABLE_H
#define	PROB3TABLE_H

template<class T>
class Prob3Table{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(char *,int,int);               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};

//constructor
template<class T>
Prob3Table<T>::Prob3Table(char* fileN, int r, int c){
    //set values
    rows=r;
    cols=c;
    //create table
    table=new T[rows*cols];
    //open file
    ifstream infile;
    infile.open(fileN,ios::in);
    //fill the table
    for(int i=0;i<(rows*cols);i++){
        infile>>table[i];
    }
    //close the file
    infile.close();
    //calcTable
    calcTable();
}

//calcTable
template<class T>
void Prob3Table<T>::calcTable(){
//find row sum
    //create array
    rowSum=new T[rows];
    //initialize values to zero
    for(int i=0;i<rows;i++){
        rowSum[i]=0;
    }
    //loop through rows
    for(int i=0;i<rows;i++){
        //add totals from row
        for(int j=0;j<cols;j++){
            rowSum[i]+=table[i*cols+j];
        }
    }
//find col sum
    //create array
    colSum=new T[cols];
    //initialize values to zero
    for(int i=0;i<cols;i++){
        colSum[i]=0;
    }
    //loop through cols
    for(int i=0;i<cols;i++){
        //add totals from row
        for(int j=0;j<rows;j++){
            colSum[i]+=table[i+(cols*j)];
        }
    }
//find the grand total
    grandTotal=0;
    for(int i=0;i<rows;i++){
        grandTotal+=rowSum[i]; 
    }
}


template<class T>
class Prob3TableInherited:public Prob3Table<T>{
    protected:
	T *augTable;                                  //Augmented Table with sums
    public:
        Prob3TableInherited(char *,int,int);          //Constructor
        ~Prob3TableInherited(){delete [] augTable;};  //Destructor
	const T *getAugTable(void){return augTable;};
};

//constructor
template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char* fileN, int r, int c):Prob3Table<T>(fileN,r,c){
  
    //create augtable with new values
    augTable=new T[(this->rows+1)*(this->cols+1)];
    //fill augtable with regular table
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            augTable[i*(this->cols+1)+j]=this->table[(i*this->cols)+j];
        }
    }
    //add in the row sums
    for(int i=0;i<r+1;i++){
        augTable[(i*(c+1))+c]=this->rowSum[i];
    }
    //add in the col sums
    for(int i=0;i<c+1;i++){
            augTable[(r*(c+1))+i]=this->colSum[i];
    }
    //add in the grand total
    augTable[((r+1)*(c+1))-1]=this->grandTotal;
}


#endif	/* PROB3TABLE_H */

