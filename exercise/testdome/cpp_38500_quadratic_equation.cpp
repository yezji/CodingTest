#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

pair<double, double> findRoots(double a, double b, double c) {
    pair<double, double> answer;
    double up = sqrt(pow(b, 2) - (4*a*c));
    answer.first = (-1*b + up) / (2*a);
    answer.second = (-1*b - up) / (2*a);    
    return answer;
}

#ifndef RunTests
int main() {
    pair<double,double> roots = findRoots(2, 10, 8);
    cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second);
}
#endif