//
//  main.cpp
//  mid-term2
//
//  Created by Rohit Ranjan on 19/10/17.
//  Copyright © 2017 Rohit Ranjan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>
#include "NormalCDF.h"
//#include "Bcal_HE.h"
//#include "BlackScholes.h"
#include "Random.h"
#include "Option.h"
#include <ql/quantlib.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
using namespace std;
using namespace boost;
using namespace QuantLib;
QuantLib::Date ConvertStrtoDate(std::string str);

vector<vector<string> > csvreader(string address);
double stringToDouble(string s);        //used while reading csv
string doubleToString(double d);
double bisection_method(double optionp, double minv, double maxv, double tol, double stockp, double strikep, double rfrate, double expiry_t);

//MAIN FUNCTION

int main()
{
    
    
    QuantLib::Date date_test = ConvertStrtoDate("2011-09-07");
    cout << "Date" << date_test;
    exit(1);
    
    
    
    vector<double> stockprice, optionprice, delta, sigmaHE, B; //Zvector;


    double s0 = 100.0;  //  spot price
    double k = 105.0;  // Strike price
    double r = 0.025;   // Risk-free rate
    double v = 0.24;    // Volatility
    double t = 0.4;    // time until expiry
    double q = 0.0;    // Dividend Yield
    double u = 0.05;
    double n = 100;
    double del_t = t/n;
   // double dt = 1.0/252.0 ;
    double deltaval = 0;
  //  bool x = 1;
  //  double mt;
    option calloption(k, s0, t, r, v, q);
    option op;
    //Zvector[0] = 0;
    stockprice.push_back(100);
    optionprice.push_back(op.callprice());
    NormalCDF n3;
    deltaval = n3(op.d1val());
    delta.push_back(deltaval);
    B.push_back(optionprice[0]-(s0 *delta[0]));
    sigmaHE.push_back(0);

    ofstream HedgingFile; //("/users/rohit/desktop/cpp-Q1.csv");
    HedgingFile.open("/users/rohit/desktop/cpp-Q1.csv");
    HedgingFile<<endl << "Time"<<","<< "Spot-Price"<<","<<"Option-Price"<<","<<"B-Value"<<""<<","<<"Hedging-Error"<<","<<endl;

    randomNormal rN(s0, t, u, v, n);
   // double z =rN.ranNrml();
    //Zvector=rN.ranNrml();
    stockprice = rN.ranNrml();
    vector <double> spot_price = rN.ranNrml();
    cout<<"mew"<<endl;
    for (int i =0; i<=99; i++)
    {
        option op(k,stockprice[i+1], t - i* del_t, r, v, q);
        optionprice.push_back(op.callprice()) ;
        deltaval = n3(op.d1val());
        delta.push_back(deltaval);
        B.push_back(delta[i] * stockprice[i+1] + B[i] * exp(r * del_t)- delta[i+1] * stockprice[i+1]);
        sigmaHE.push_back(delta[i] * stockprice[i+1] + B[i] * exp(r * del_t) - optionprice[i+1]);
        HedgingFile<<endl << i+1<<","<< stockprice[i+1]<<","<<optionprice[i+1]<<","<<B[i+1]<<""<<","<<sigmaHE[i+1]<<","<<endl;
    }
    HedgingFile.close();


  // Q-2 - File 1
    vector<double> rates;
    vector<vector<string> > Interest = csvreader("/Users/rohit/Desktop/Programs_C++/data/interest.csv");
    for(int i=0; i<Interest.size();i++)
    {
        //cout<<Interest[i][0]<<" ";  //date
        rates.push_back( atof(Interest[i][1].c_str()));  //rate
    }
    
    
    
    //File 2
    vector<double> stkprices;
    vector<vector<string> > goog_sec = csvreader("/Users/rohit/Desktop/Programs_C++/data/sec_goog.csv");
    for(int i=0; i<199;i++)//i<goog_sec.size();i++)
    {
        //cout<<goog_sec[i][0]<<" ";
        stkprices.push_back( atof(goog_sec[i][1].c_str()));
    }

    //File 3
    vector<string> date;
    vector<string> expiryd;
    vector<double> strikep;
    vector<string> fl;
    vector<double> bid;
    vector<double> offer;
    vector<vector<string> > goog_op = csvreader("/Users/rohit/Desktop/Programs_C++/data/op_goog.csv");
    for(int i=0; i<goog_op.size();i++)//i<goog_sec.size();i++)
    {
        date.push_back(goog_op[i][0]);
        expiryd.push_back((goog_op[i][1]));
        strikep.push_back(atof(goog_op[i][3].c_str()));
        fl.push_back(goog_op[i][2]);
        bid.push_back(atof(goog_op[i][4].c_str()));
        offer.push_back(atof(goog_op[i][5].c_str()));
    }
    string startdate = "2011-07-05";
    string enddate = "2011-07-29";
    string expirydate = "2011-09-17";
    string flag="C";
    string strikeprice="500";
    
    /*
    cout<<"enter start date"<<endl;
    cin>>startdate;
    cout<<"enter end date"<<endl;
    cin>>enddate;
    cout<<"enter expiry date"<<endl;
    cin>>expirydate;
    cout<<"enter flag"<<endl;
    cin>>flag;
    cout<<"enter strike price";
    cin>>strikeprice;
    
     */
    vector<string> date2;
    vector<string> expiryd2;
    vector<double> strikep2;
    vector<string> fl2;
    vector<double> stock_price;
    vector<double> option_price;
    vector<double> riskfreerate;
    vector<double> vol;
    
    vector<double> B_final;
    vector<double> delta_final;
    vector<double> HE_final;
    int flag2=0;
    
    double minvol = 0.001;
    double maxvol = 0.8;
    double tolerance = 0.00001;
   
    ofstream HedgingFile2; //("/users/rohit/desktop/cpp-Q2.csv");
    HedgingFile2.open("/users/rohit/desktop/cpp-Q2.csv");
    HedgingFile2<<endl << "Time"<<","<< "Spot-Price"<<","<<"Option-Price"<<","<< "Vol" <<","<<"B-Value"<<""<<","<<"Hedging-Error"<<","<<endl;
    
    
    
    Date start_date = ConvertStrtoDate(startdate);
    Date end_date = ConvertStrtoDate(expirydate);
    Calendar tom = UnitedStates();
    
    double timetomaturity = tom.businessDaysBetween(start_date, end_date);
    
    for(int i=0 ; i<date.size(); i++)
    {
       if(expirydate == goog_op[i][1] && "C"==goog_op[i][2] && strikeprice == goog_op[i][3])
       {
           if (startdate == goog_op[i][0] )
           {
               flag2=1;
           }
           if (flag2==1)
           {
                  // or enddate != goog_op[i][1] or expirydate != goog_op[i][2] or
                date2.push_back( date[i]);
                expiryd2.push_back( expiryd[i]);
                strikep2.push_back(strikep[i]);
                fl2.push_back(fl[i]) ;
                option_price.push_back((bid[i]+offer[i])/2);
               stock_price.push_back(stkprices[i]);
               riskfreerate.push_back(rates[i]);
               vol.push_back(bisection_method( option_price[i+1],  minvol, maxvol,  tolerance, stkprices[i+1], strikep2[i+1], riskfreerate[i+1],  (timetomaturity - i)/252));
               /***************/
               
               if(i==0)
               {
                   option calloption(strikep[i], stock_price[i], (timetomaturity - i)/252 , riskfreerate[i] , vol[i] , 0);
                   option op;
                   NormalCDF n3;
                   deltaval = n3(op.d1val());
                   delta_final.push_back(deltaval);
                   B_final.push_back(option_price[0]-(stock_price[0] *delta_final[0]));
                   HE_final.push_back(0);
                   HedgingFile2<<endl << i<<","<< stock_price[0] <<","<<option_price[0]<<","<< vol[0] <<","<<B_final[0]<<","<<HE_final[0]<<","<<endl;
                   
               }
               
               if(i>0)
               {
               option calloption(strikep[i], stock_price[i], (timetomaturity - i)/252 , riskfreerate[i] , vol[i] , 0);
               option op;
               NormalCDF n3;
               deltaval = n3(op.d1val());
               delta_final.push_back(deltaval);
               B_final.push_back(delta_final[i] * stock_price[i+1] + B_final[i] * exp(riskfreerate[i] /252)- delta_final[i+1] * stock_price[i+1]);
               HE_final.push_back(delta_final[i] * stock_price[i+1] + B_final[i] * exp(riskfreerate[i] /252) - option_price[i+1]);
                   
                   
                   HedgingFile2<<endl << i<<","<< stock_price[i] <<","<<option_price[i]<<","<< vol[i] <<","<<B_final[i]<<","<<HE_final[i]<<","<<endl;
                   
               }
               
               
               
               
               
               //offer2[i] = offer[i];
               //cout<<option_price[i]<<endl;
           }
           if(enddate== goog_op[i][0])
           {
               flag2=0;
           }
       }
    }
   
}



//FUNCTIONS

double Hedgingerror(double a1,double a2,double a3,double a4,double a5, double a6)
{
    return (a1 * a2 + a3 * exp(a4*a6) - a5);
}

double bisection_method(double optionp, double minv, double maxv, double tol, double stockp, double strikep, double rfrate, double expiry_t)
{
    double x = 0.5 * (minv + maxv);    // Keeping initial guess as (min+max) /2
    //int call_input = 1;     //option
     option op(strikep, stockp, expiry_t, rfrate, x, 0);
    double y = op.callprice();
    
    do
    {
        if (y < optionp)
        {
            minv = x;
        }
        if (y > optionp)
        {
            maxv = x;
        }
        x = 0.5 * (minv + maxv);
        option op(strikep, stockp, expiry_t, rfrate, x, 0);
        y = op.callprice();
    } while (fabs(y - optionp) > tol);
    return x;
}
        


QuantLib::Date ConvertStrtoDate(std::string str)
{
    int date[3], j(0);
    size_t pos;
    std::string delim = "-";
    while ((pos = str.find(delim)) != std::string::npos)
    {
        date[j++] = atoi(str.substr(0, pos).c_str());
        str.erase(0, pos + delim.length());
    }
    date[j] = atoi(str.c_str());
    return QuantLib::Date(date[2], QuantLib::Month(date[1]), date[0]);
}

double stringToDouble(string s) {
    double d;
    stringstream ss(s);
    ss >> d;
    return d;
}


string doubleToString(double d){
    stringstream strs;
    strs<< d;
    string str = strs.str();
    return str;
    
}

vector<vector<string> > csvreader(string address)
{
    vector<vector<string> > o1;
    vector<string> o2;
    string line;
    ifstream csv(address.c_str());
    string token;
    while (getline(csv, line))        //iterate the row while exists information
    {
        istringstream stream1(line);
        while(getline(stream1,token, ','))                //separates the data with commas ","
        {
            o2.push_back(token);  //inserting the rates in the vector
        }
        o1.push_back(o2);
        o2.clear();
    }
    return o1;
}
