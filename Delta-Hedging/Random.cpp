//
//  Random.cpp
//  mid-term2
//
//  Created by Rohit Ranjan on 19/10/17.
//  Copyright © 2017 Rohit Ranjan. All rights reserved.
//

#include <stdio.h>
#include "Random.h"
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <vector>
#include <random>
#include <chrono>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>

using namespace std;

randomNormal::randomNormal(double s, double t, double u, double v, int n)
{
    spot_price = s;
    time_to_maturity = t;
    mean = u;
    volatility = v;
    period = n;
    
}

randomNormal::~randomNormal(){}

vector<double> randomNormal::ranNrml()
{
    vector<double> r;
    r.push_back(spot_price);
    default_random_engine rgen;
     rgen.seed(std::chrono::system_clock::now().time_since_epoch().count()); 
    double dt = time_to_maturity/period;
    normal_distribution <double> randnor(0,1);
    for (int i = 1; i<= period; i++)
    {
        r.push_back(r[i-1] + (mean * r[i-1]*dt) + volatility * r[i-1] * sqrt(dt) * randnor(rgen));
    }
    return r;
}


