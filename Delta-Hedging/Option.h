//
//  Option.h
//  mid-term2
//
//  Created by Rohit Ranjan on 20/10/17.
//  Copyright © 2017 Rohit Ranjan. All rights reserved.
//

#ifndef Option_h
#define Option_h
#include <cmath>

using namespace std;

class option
{
private:
    double s0, k, t, r, v, q, d1, d2;
    
public:
    option();
    option(double k, double s0, double t, double r, double v, double q);
    option(double k, double s0, double t, double v);
    ~option();
    
    double getspot();
    void setspot(double S2);
    
    double getstrike();
    void setstrike(double K2);
    
    double getmaturity();
    void setmaturity(double T2);
    
    double getrfrate();
    void setrfrate(double R2);
    
    double getdividend();
    void setdividend(double Q2);
    
    double getvol();
    void setvol(double V2);
    void d1_d2val();

    double getd1();
    void setd1(double D1);

    double getd2();
    void setd2(double D2);
    
    double callprice();
    double d1val();
    double d2val();
   //double delta(bool type);
// bool putcallparity();
};



#endif /* Option_h */
