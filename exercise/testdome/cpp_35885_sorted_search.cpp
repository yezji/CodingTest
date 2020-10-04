#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

int countNumbers(const std::vector<int>& sortedVector, int lessThan) {
    int mid = sortedVector.size()/2;
    int direction;
    if (sortedVector[mid] < lessThan) direction = 1;
    else direction = -1;

    while (mid>=0 && mid<sortedVector.size()) {
        if (direction == 1) {
            if (sortedVector[mid] < lessThan) mid += direction;
            else break;
        }
        else {
            if (sortedVector[mid] < lessThan) break;
            else mid += direction;
        }
    }
    if (direction == 1) return mid;
    else return mid+1;
}

#ifndef RunTests
int main() {
    std::vector<int> v { 1, 3, 5, 7, 9 };
    std::cout << countNumbers(v, 10);
}
#endif