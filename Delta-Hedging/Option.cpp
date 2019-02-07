//
//  Option.cpp
//  mid-term2
//
//  Created by Rohit Ranjan on 20/10/17.
//  Copyright © 2017 Rohit Ranjan. All rights reserved.
//

#include <stdio.h>
#include "NormalCDF.h"
#include "Option.h"
#include <cmath>
#include <iostream>
using namespace std;

option::option()
{
    s0 = 90;
    k = 100;
    t = 1;
    r = 0.01;
    v = 0.1;
    q = 0;
}

option::option(double K, double S, double T, double R, double V, double Q)
{
    s0 = S;
    k = K;
    t = T;
    r = R;
    v = V;
    q = Q;
}

option::option(double K, double S, double T, double V)
{
    s0 = S;
    k = K;
    t = T;
    v = V;
    r = 0.01;
    q = 0;
    
}

option::~option(){}

double option::getspot(){return s0;}
void option::setspot(double S2){s0 = S2;}

double option::getstrike(){return k;}
void option::setstrike(double K2){k = K2;}

double option::getmaturity(){return t;}
void option::setmaturity(double T2){t = T2;}

double option::getrfrate(){return r;}
void option::setrfrate(double R2){r = R2;}

double option::getdividend(){return q;}
void option::setdividend(double Q2){q = Q2;}

double option::getvol(){return v;}
void option::setvol(double V2){v = V2;}

double option::getd1(){return d1;}
 void option::setd1(double D1){d1 = (log(s0/k) + t*(r - q + 0.5 * v * v))/(v*sqrt(t));}
 
 double option::getd2(){return d2;}
 void option::setd2(double D2){d2 = d1 - v * sqrt(t);}
 

//void option::d1_d2val()
//{
//    d1 = (log(s0/k) + t*(r - q + 0.5 * v * v))/(v*sqrt(t));
//
//
//    d2 = d1 - v * sqrt(t);
//}
double option::d1val()
{
    d1 = (log(s0/k) + t*(r - q + 0.5 * v * v))/(v*sqrt(t));
    
    return d1;
}
double option::d2val()
{
    double d1;
    d1 = (log(s0/k) + t*(r - q + 0.5 * v * v))/(v*sqrt(t));
    double d2 =  d1 - v * sqrt(t);
    return d2;
    
}



double option::callprice()
{
    
    NormalCDF n1;
    double cdf1 = n1(d1val());
    NormalCDF n2;
    double cdf2 = n2(d2val());
    double price_call = (s0 * cdf1 - k * cdf2 * exp(-r * t));
    //cout<<price_call;
    if (price_call>=0)
        {return price_call;}
        else
        {return 0;}
    
}


//double option::delta(bool type)
//{
//    d1_d2val();
//    Normal s3(d1);
//    double cdf1 = s3(d1);
//    
//    Normal s5(-d1);
//    double cdf3 = s5(-d1);
//    
//    if (type == 1)
//    {return (cdf1 * (exp(-q * t)));}
//    else
//    {return (cdf3 * (exp(-q * t)));}
//    
//}

/*bool BlackScholes::putcallparity()
 {
 if (price(1) + exp(-r * t) - price(0) - k == 0)
 {return (1);}
 else
 {return (0);}
 }*/

