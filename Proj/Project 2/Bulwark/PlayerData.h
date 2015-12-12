/* 
 * File:   PlayerData.h
 * Author: Branden Hitt
 * Purpose: Hold data for output
 * Created on December 11, 2015, 3:22 PM
 */

#ifndef PLAYERDATA_H
#define	PLAYERDATA_H
#include <string>
using namespace std;

const int SIZE=30;
struct PlayerData{
    char name[SIZE];
    int maxHlth;
    int dps;
    char arch[SIZE];
    char weapon[SIZE];
    char special[SIZE];
    int waveC;
};

#endif	/* PLAYERDATA_H */

