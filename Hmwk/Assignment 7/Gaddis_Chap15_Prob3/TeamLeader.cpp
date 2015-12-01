
#include "TeamLeader.h"
#include "Employee.h"
#include "ProductionWorker.h"

/* 
 * File:   TeamLeader.h
 * Author: Administrator
 * Purpose: Specification of the TeamLeader Class
 * Created on November 30, 2015, 11:56 PM
 */
TeamLeader::TeamLeader(string n, int num, string h, int s, float p, int mon, int hrR, int hrA){
    monBon=mon;
    reqHour=hrR;
    hrAtte=hrA;
    TeamLeader::setName(n);
    TeamLeader::setNum(num);
    TeamLeader::setHire(h);
    TeamLeader::setShft(s);
    TeamLeader::setPayR(p);
}