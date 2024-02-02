//
//  Interval.cpp
//  PR_2
//
//  Created by Marcus Shaw on 10/6/23.
//

#include "interval.hpp"
using namespace std;
// I assume the header has enough comments for this class
// Default constructor
interval::interval (const int a, const int b, const int c, const int d, const int e) {
    setStartTime(a);
    setFinTime(b);
    setWeight(c);
    setP(d);
    setM(e);
}

void interval::setStartTime(const int a) {
    startTime = a;
}
int interval::getStartTime() {
    return startTime;
}

void interval::setFinTime(const int a) {
    finTime = a;
}
int interval::getFinTime() {
    return finTime;
}

void interval::setWeight(const int a) {
    weight = a;
}
int interval::getWeight() {
    return weight;
}
void interval::setP(const int a) {
    p = a;
}
int interval::getP() {
    return p;
}

void interval::setM(const int a) {
    m = a;
}
int interval::getM() {
    return m;
}
