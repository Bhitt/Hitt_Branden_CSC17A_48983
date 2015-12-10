/* 
 * File:   BossUnit.h
 * Author: Branden Hitt
 * Purpose: Implementation of the BossUnit class
 * Created on December 3, 2015, 1:11 PM
 */
#include "BossUnit.h"
#include <cstdlib>
BossUnit::BossUnit(){
    srand(static_cast<unsigned int>(time(0)));
    int pick=(rand()%5+1);
    if(pick==1){
        name="Nosferatu";
        health=1200;
        dps=70;
        bonus="LifeSteal";  //Steals health from successful attacks
        special="LifeSwap"; //Swaps health with the player at a given percentage
    }else if(pick==2){
        name="Headless Horseman";
        health=1400;
        dps=50;
        bonus="Fear";       //Chance to force player to miss attack
        special="Trample";  //Attacks First
    }else if(pick==3){
        name="Dr. Jeckyl";
        health=1200;
        dps=30;
        bonus="Toxic";      //Chance to lower Max Health permanently
        special="Anger";    //Chance to transform to Mr.Hyde and gain stats 
    }else if(pick==4){
        name="Frankenstein's Monster";
        health=1600;
        dps=60;
        bonus="Conduit";    //Chance to shock player for damage when he is hit   
        special="none"; //Chance to break the player's weapon, returning it to default stats
    }else{
        name="Cthulhu";
        health=5000;
        dps=300;
        bonus="The Call";   //Chance for the player to go mad and attack themselves
        special="Devour";   //Chance to automatically kill the player
    }
}
void BossUnit::setBon(string b){
    bonus=b;
}
void BossUnit::setSpec(string s){
    special=s;
}