//
//  WISheader.hpp
//  PR_2
//
//  Created by Marcus Shaw on 10/6/23.
//

#ifndef WISheader_hpp
#define WISheader_hpp
#include "interval.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
class WISimplementation {
    
private:
    vector<interval> vect; // this is a vector to dynamically hold the given information
    int currWeight; // this is the current weight of the vector
    vector<interval> maxProfit;
    
public:
    WISimplementation (const int = 0); // Default constructor
    
    void addInterval(const int a, const int b, const int c); // this is to add an interval to the vector
    void sortIntervals(); // this sorts the vector by finish times
    void outputIntervals(); // this is to output all the intervals
    void outputMaxProfitIntervals(); // this is to output the intervals that are the most ideal 
    void computeP(); // this is used to computer the largest index that the job is compatible with
    void computeM(); // this is to show the max weight the job leads to
};
#endif /* WISheader_hpp */
