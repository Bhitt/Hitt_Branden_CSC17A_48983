/* 
 * File:   TeamLeader.h
 * Author: Administrator
 * Purpose: Specification of the TeamLeader Class
 * Created on November 30, 2015, 11:54 PM
 */
#include <string>
using namespace std;

#ifndef TEAMLEADER_H
#define	TEAMLEADER_H
#include "ProductionWorker.h"
class TeamLeader : public ProductionWorker{
    private:
        int monBon;
        int reqHour;
        int hrAtte;
    public:
        TeamLeader(string,int,string,int,float,int,int,int);
        void setMonB(int);
        void setRHrs(int);
        void setHrAt(int);
        int getMonB(){return monBon;}
        int getRHrs(){return reqHour;}
        int getHrAt(){return hrAtte;}
};

#endif	/* TEAMLEADER_H */

