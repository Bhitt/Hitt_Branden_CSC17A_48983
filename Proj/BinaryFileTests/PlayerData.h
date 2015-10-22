/* 
 * File:   PlayerData.h
 * Author: Branden Hitt
 * Created on October 18, 2015, 8:44 PM
 * Purpose: Hold the player's data in a structure
 */

#ifndef PLAYERDATA_H
#define	PLAYERDATA_H

struct PlyrDta{
    string name;//player name
    float winRate;//win rate
    unsigned short easyG;//easy games played
    unsigned short mediG;//medium games played
    unsigned short hardG;//hard games played
};

#endif	/* PLAYERDATA_H */

