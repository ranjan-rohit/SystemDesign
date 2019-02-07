//
//  Normal.cpp
//  mid-term2
//
//  Created by Rohit Ranjan on 19/10/17.
//  Copyright © 2017 Rohit Ranjan. All rights reserved.
//
#include <stdio.h>
#include "NormalCDF.h"
#include <math.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>

NormalCDF::NormalCDF(double x){};
NormalCDF::NormalCDF(){};
NormalCDF::~NormalCDF(){};
double NormalCDF::operator()(double x) 
{
    normal_distribution<> StdNormal(0.0, 1.0);
    return cdf(StdNormal, x);
}

