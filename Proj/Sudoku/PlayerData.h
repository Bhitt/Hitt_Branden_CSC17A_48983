/* 
 * File:   PlayerData.h
 * Author: Branden Hitt
 * Created on October 18, 2015, 8:44 PM
 * Purpose: Hold the player's data in a structure
 */

#ifndef PLAYERDATA_H
#define	PLAYERDATA_H

const int SIZE=30;
struct Records{
    char name[SIZE];//name
    short ttlG;//total games played
    short easyG;//easy games won
    short mediG;//medium games won
    short hardG;//hard games won
    float winR;//win rate
};


#endif	/* PLAYERDATA_H */

