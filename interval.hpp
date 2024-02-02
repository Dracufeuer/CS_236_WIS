//
//  Interval.hpp
//  PR_2
//
//  Created by Marcus Shaw on 10/6/23.
//

#ifndef Interval_hpp
#define Interval_hpp

#include <stdio.h>
using namespace std;
class interval {
    
private: // these are the variables of the object that will hold the data of the times and weights of the intervals then the p 
    int startTime;
    int finTime;
    int weight;
    int p;
    int m;
    
public:
    interval( const int = 0, const int = 0, const int = 0, const int = 0, const int = 0); // this is the default constructor
    
    void setStartTime(const int a); // setters and getters for startTime
    int getStartTime();
    
    void setFinTime(const int a); // setters and getters for finTime
    int getFinTime();
    
    void setWeight(const int a); // setters and getters for weight
    int getWeight();
    
    void setP(const int a); // setters and getters for p
    int getP();
    
    void setM(const int a); // setters and getters for m
    int getM();
};

#endif /* interval_hpp */
