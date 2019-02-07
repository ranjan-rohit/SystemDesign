//
//  Random.h
//  mid-term2
//
//  Created by Rohit Ranjan on 19/10/17.
//  Copyright © 2017 Rohit Ranjan. All rights reserved.
//

#ifndef Random_h
#define Random_h

#include<vector>
using namespace std;
class randomNormal
{
private:
    double spot_price, time_to_maturity, mean, volatility;
    int period;
public:
    randomNormal(double s, double t, double u, double v, int n);
    ~randomNormal();
    vector <double> ranNrml();
};

#endif
