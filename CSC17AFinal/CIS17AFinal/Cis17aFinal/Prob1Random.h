/* 
 * File:   Prob1Random.h
 * Author: Branden Hitt
 * Purpose: Specification for the Prob1Random class
 * Created on December 14, 2015, 5:54 PM
 */

#ifndef PROB1RANDOM_H
#define	PROB1RANDOM_H

class Prob1Random{
    private:
	char *set;      //The set of numbers to draw random numbers from
	char  nset;     //The number of variables in the sequence
	int  *freq;     //Frequency of all the random numbers returned
	int   numRand;  //The total number of times the random number function is called
    public:
	Prob1Random(const char,const char *);     //Constructor
	~Prob1Random(void);                       //Destructor
	char randFromSet(void);                   //Returns a random number from the set
	int *getFreq(void) const{return freq;}    //Returns the frequency histogram
	char *getSet(void) const{return set;}     //Returns the set used
	int getNumRand(void) const{return numRand;} //Gets the number of times randFromSet has
		                                          //been called
};

#endif	/* PROB1RANDOM_H */

