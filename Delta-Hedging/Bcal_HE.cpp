//
//  Bcal_HE.cpp
//  mid-term2
//
//  Created by Rohit Ranjan on 19/10/17.
//  Copyright © 2017 Rohit Ranjan. All rights reserved.
//

#include <stdio.h>
#include "Bcal_HE.h"
#include <cstdlib>
#include <cmath>
#include <vector>
#include "Option.h"
#include "Normal.h"

using namespace std;

double BScalc::call_price(option call)
{
    //call.d1_d2val();
    Normal n1(call.getd1());
    Normal n2(call.getd2());
    
    return ();
}





//double Herror(double a1,double a2,double a3,double a4,double a5, double a6)
//{
//
//    return (a1 * a2 + a3 * exp(a4*a6) - a5);
//}

