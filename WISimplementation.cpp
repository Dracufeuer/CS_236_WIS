//
//  WISimplementation.cpp
//  PR_2
//
//  Created by Marcus Shaw on 10/6/23.
//

#include "WISheader.hpp"
WISimplementation::WISimplementation(const int a) {
    currWeight = a;
    vect.clear();
    maxProfit.clear();
}
void WISimplementation::addInterval(const int a, const int b, const int c) {
    vect.push_back(interval(a,b,c,0,0));
}
void WISimplementation::sortIntervals() {
    int minVal, x; // this is used to see the minimum value to put at the beggining of the vector
    interval swap;
    for(int i = 0; i < vect.size(); i++) { // this is the for loop to sort the vector
        minVal = vect[i].getFinTime();
        x = i;
        
        for(int j = i; j < vect.size(); j++) { // this is to find he minimum number in the vector
            if(vect[j].getFinTime() < minVal) {
                minVal = vect[j].getFinTime();
                x = j;
            }
            if(j == vect.size()-1) {
                swap = vect[i];
                vect[i] = vect[x];
                vect[x] = swap;
            }
        }
    }
}

void WISimplementation::outputIntervals() {
    
    cout << "Sorted Input Intervals by finishing time: \n";
    cout << setw(8) << " " << setw(16) << left << "Index<i>" << setw(10) << "S<i>" << setw(10) << "F<i>" << setw(10) << "W<i>" << '\n';
    for(int i = 0; i < vect.size(); i++) {
        cout << setw(8) << " " << setw(16) << i+1 << setw(10)  << vect[i].getStartTime() << setw(10) << vect[i].getFinTime() << setw(10)  << vect[i].getWeight() << '\n';

    }
    cout << '\n';
}

void WISimplementation::outputMaxProfitIntervals() {
    int x, y; // this is used to find the max M value and the position of it
    x = vect[0].getM();
    y = 0;
    for(int i = 0; i < vect.size(); i++) {
        if( vect[i].getM() > x) {
            x = vect[i].getM();
            y = i;
        }
    }
    x = vect[y].getP(); //This is used so I can loop through and make a vector that holds the maximum profit intervals
    maxProfit.push_back(vect[y]);
    while(x != 0) { // this is making the vector that holds the max profit intervals
        maxProfit.push_back(vect[x-1]);
        if(vect[x-1].getP() != 0) {
            x = vect[x-1].getP();
        }
        else {
            x = 0;
        }
    }
    cout << "Maximum profit of non-overlapping scheduling is " << maxProfit[0].getM() << '\n';
    cout << "The jobs involved in the maximum profit are ";
    for(int i = maxProfit.size() - 1; i >= 0; i--) {
        cout << "(" << maxProfit[i].getStartTime() << " " << maxProfit[i].getFinTime() << " " << maxProfit[i].getWeight() << ")";
        if(i > 0) {
            cout << ", ";
        }
    }
    cout << "\n\n";
    
}
void WISimplementation::computeP() {
    for(int i = 0; i < vect.size(); i++) {
        
        for(int j = 0; j < vect.size(); j++) {
            if(vect[i].getFinTime() <= vect[j].getStartTime()) {
                vect[j].setP(i+1);
            }
        }
    }
}
void WISimplementation::computeM() {
    int x; // this is to keep track of the p
    for(int i = 0; i < vect.size(); i++) {
        x = vect[i].getP();
        vect[i].setM(vect[i].getWeight());
        while(x != 0){
            vect[i].setM(vect[i].getM() + vect[x-1].getWeight());
            if(vect[x-1].getP() != 0) {
                x = vect[x-1].getP();
            }
            else {
                x = 0;
            }
        }
        
        
    }
}
