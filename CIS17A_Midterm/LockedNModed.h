/* 
 * File:   LockedNModed.h
 * Author: Administrator
 *
 * Created on October 27, 2015, 11:26 PM
 */

#ifndef LOCKEDNMODED_H
#define	LOCKEDNMODED_H

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

#endif	/* LOCKEDNMODED_H */

