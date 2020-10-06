#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
# Approach 1: Two Pointers

Since the array is already sorted, we can keep two pointers i and j.
where i is the slow-runner while j is the fast-runner.
As long as nums[i] == nums[j], we increment j to skip the duplicate.

When we encouter nums[j] != nums[i], the duplicate run has ended so we must copy its value to nums[i+1].
i is then incremented and we repeat the same process again until j reaches the end of array.

# Time Complexity   : O(n)
# Space Complexity  : O(1)
*/

class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i=0;
        for (int j=1; j<nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
        
        // vector에서 원소 제거한 방법
        // nums.erase(unique(nums.begin(), nums.end()), nums.end());
        // return nums.size();
    }
};

int main() {
    Solution s;
    vector<int> input;
    int len;

    input = {1, 1, 2};
    len = s.removeDuplicates(input);
    for (int i=0; i<len; i++) cout << input[i] << " ";
    cout << endl;

    input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    len = s.removeDuplicates(input);
    for (int i=0; i<len; i++) cout << input[i] << " ";
    cout << endl;
    
    return 0;
}