/* 
 * File:   Player.h
 * Author: Branden Hitt
 * Purpose: Specification of the Player class
 * Created on December 1, 2015, 2:01 PM
 */
#include "Weapon.h"
#include <string>
using namespace std;

#ifndef PLAYER_H
#define	PLAYER_H

class Player{
    private:
        string name;
        int health;
        int dps;
        string arche;
        Weapon weapon;
    public:
};

#endif	/* PLAYER_H */

