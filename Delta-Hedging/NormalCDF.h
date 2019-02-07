//
//  Normal.h
//  mid-term2
//
//  Created by Rohit Ranjan on 19/10/17.
//  Copyright © 2017 Rohit Ranjan. All rights reserved.
//

#ifndef NormalCDF_h
#define NormalCDF_h
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <cmath>
#include <iostream>
using namespace std;
using namespace boost::math;

class NormalCDF
{
public:
    NormalCDF();
    NormalCDF(double x);
    ~NormalCDF();
    double operator() (double x) ;
};


#endif

