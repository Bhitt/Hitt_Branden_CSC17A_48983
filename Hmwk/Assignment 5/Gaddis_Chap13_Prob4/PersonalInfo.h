/* 
 * File:   PersonalInfo.h
 * Author: Administrator
 *
 * Created on November 8, 2015, 3:56 PM
 */

#ifndef PERSONALINFO_H
#define	PERSONALINFO_H

#include <string>
using namespace std;

class PrsInfo{
    private:
      string name;
      string address;
      unsigned short age;
      string phone;
    public:
      void setName(string);             //mutator
      string getName(){return name;}    //accessor (in-line))
      void setAdd(string);              //mutator
      string getAdd(){return address;}  //accessor (in-line)
      void setAge(unsigned short);      //mutator
      unsigned short getAge();          //accessor
      void setPhn(string);              //mutator
      string getPhone(){return phone;}  //accessor (in-line)
};

#endif	/* PERSONALINFO_H */

