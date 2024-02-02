//
//  WISmain.cpp
//  PR_2
//  Class: CS 236
//  Semester: Fall 2023
//  Name: Marcus Shaw
//  Created by Marcus Shaw on 10/6/23.
//


#include "WISheader.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    int intA = 1;
    double dblTest = 0; // this is used to test for decimals
    cout << "++++ Weighted Interval Scheduling with Bottom up Dynamic Programming ++++\n";
    while(dblTest != intA) { // this While statement is to check if they are entering decimals or not
        cout << "Enter number of Intervals: ";
        cin >> dblTest;
        intA = dblTest;
        if(intA != dblTest) {
            cout << "ERROR: Decimals were detected\n";
        }
    }
    cout << "Enter Start time, Finish time, and Weight seperate by a space: \n" <<
        "Si  Fi  Wi \n";
    interval a; // this is to store the intervals to send to the WISimplementation
    WISimplementation implementData;
    for(int i = intA; i > 0; i--) { // this is to gather all the user inputs
        cin >> intA;
        a.setStartTime(intA);
        cin >> intA;
        a.setFinTime(intA);
        cin >> intA;
        a.setWeight(intA);
        implementData.addInterval(a.getStartTime(), a.getFinTime(), a.getWeight());
        
    }
    implementData.sortIntervals();
    implementData.computeP();
    implementData.computeM();
    implementData.outputIntervals();
    implementData.outputMaxProfitIntervals();
    
    return 0;
}
