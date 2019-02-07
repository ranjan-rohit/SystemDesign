//
//  BlackScholes.h
//  mid-term2
//
//  Created by Rohit Ranjan on 19/10/17.
//  Copyright © 2017 Rohit Ranjan. All rights reserved.
//

#ifndef BlackScholes_h
#define BlackScholes_h
#include <cmath>

using namespace std;

class BlackScholes
{
private:
    double s0, k, t, r, v, q, d1, d2;
    
public:
    BlackScholes();
    BlackScholes(double s0, double k, double t, double r, double v, double q);
    BlackScholes(double s0, double k, double t, double v);
    ~BlackScholes();
    
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
    
    double getd1();
    void setd1(double D1);
    
    double getd2();
    void setd2(double D2);
    
    double price(bool type);
    double delta(bool type);
   // bool putcallparity();
    void d1_d2val();
};




#endif /* BlackScholes_h */
