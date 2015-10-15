/* 
 * File:   card.h
 * Author: Branden Hitt
 * Created on October 15, 2015, 11:59 AM
 * Purpose: Specification for the Card Class
 */

#ifndef CARD_H
#define	CARD_H

class Card{
    private:
        char number;
    public:
        Card(char);                      //Constructor
        void setNum(char);               //Mutator
        char getNum(){return number;}    //Accessor (in-line function))
        char suit();                     //Suit property
        char numVal();                   //Numerical value property
        char faceVal();                  //Face value property
};

#endif	/* CARD_H */

