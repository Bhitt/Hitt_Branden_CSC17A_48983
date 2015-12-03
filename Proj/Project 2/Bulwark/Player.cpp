/* 
 * File:   Player.h
 * Author: Branden Hitt
 * Purpose: Implementation of the Player class
 * Created on December 2, 2015, 11:35 AM
 */

#include "Player.h"

Player::Player(){
    name="default";
    health=0;
    dps=0;
    arche="default";
    weapon=Weapon();
    maxHlth=0;
    waveCnt=0;
}
Player::Player(string na, int he, int dp, string ar){
    name=na;
    health=he;
    dps=dp;
    arche=ar;
    weapon=Weapon();
    maxHlth=he;
    waveCnt=0;
}
void Player::setName(string na){
    name=na;
}
void Player::setHel(int he){
    health=he;
}
void Player::setDps(int d){
    dps=d;
}
void Player::setArch(string a){
    arche=a;
}
void Player::setWepn(Weapon &w){
    weapon=w;
}
void Player::setMaxH(int m){
    maxHlth=m;
}
void Player::setWave(int w){
    waveCnt=w;
}