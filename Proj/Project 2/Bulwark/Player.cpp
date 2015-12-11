/* 
 * File:   Player.h
 * Author: Branden Hitt
 * Purpose: Implementation of the Player class
 * Created on December 2, 2015, 11:35 AM
 */
#include <iostream>
#include "Player.h"

Player::Player(){
    name="default";
    health=0;
    dps=0;
    arche="default";
    weapon=Weapon();
    maxHlth=0;
    waveCnt=0;
    selfH=0;
}
Player::Player(string n,int pick){
    if(pick==1){
        name=n;
        health=500;
        dps=70;
        arche="Ranger";
        weapon=Weapon(1);
        special="Headshot";
        specC=5;
        selfH=60;
    }else if(pick==2){
        name=n;
        health=450;
        dps=90;
        arche="Warlock";
        weapon=Weapon(2);
        special="Transfusion";
        specC=5;
        selfH=50;
    }else if(pick==3){
        name=n;
        health=550;
        dps=50;
        arche="Paladin";
        weapon=Weapon(3);
        special="Fortify";
        specC=5;
        selfH=70;
    }else{
        name=n;
        health=400;
        dps=100;
        arche="Beserker";
        weapon=Weapon(4);
        special="Ragnarok";
        specC=5;
        selfH=40;
    }
        maxHlth=health;
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
void Player::setSlfH(int s){
    selfH=s;
}
void Player::setSpec(string s){
    special=s;
}
void Player::setSpC(int c){
    specC=c;
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
void Player::takeDam(int d){
    cout<<"You have been hit for "<<d<<" damage."<<endl;
    health-=d;
    if(health<0)health=0;
}
void Player::addHel(int add){
    health+=add;
    if(health>maxHlth) health=maxHlth;
    cout<<"You have been healed for "<<add<<endl;
}
void Player::addMaxH(int add){
    maxHlth+=add;
    cout<<"You have gained +"<<add<<" max health."<<endl;
}
int Player::useSpec(int eneHlth){
    if(this->special=="Headshot"){
        int halved=eneHlth/2;
        eneHlth-=halved;
        if(eneHlth<0) eneHlth=0;
        cout<<"You have fired a direct hit to the enemy for "<<halved<<" damage!"<<endl;
    }else if(this->special=="Transfusion"){
        int steal=eneHlth/4;
        eneHlth-=steal;
        if(eneHlth<0) eneHlth=0;
        health+=steal;
        if(health>maxHlth) health=maxHlth;
        cout<<"You have stolen "<<steal<<" health from the enemy"<<endl;
    }else if(this->special=="Fortify"){
        int placeH=maxHlth/3;
        health+=placeH;
        maxHlth+=placeH;
        if(health>maxHlth) health=maxHlth;
        cout<<"Your max health has increased to "<<maxHlth<<"."<<endl;
        cout<<"You have also healed for "<<placeH<<" health."<<endl;
    }else{
        int half=health/2;
        health-=half;
        cout<<"You have given up half of your current health"<<endl;
        eneHlth=0;
        cout<<"The enemy is now dead"<<endl;
    }
    //decrement special count
    specC--;
    return eneHlth;
}
void Player::healS(){
    health+=selfH;
    if(health>maxHlth) health=maxHlth;
}