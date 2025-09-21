#include <bits/stdc++.h>
using namespace std;

// LeetCode 169 - Majority Element (more than n/2 times)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0; //Finds an element that could be the majority

        // Moore's Voting Algorithm
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate; // As Guaranteed to exist GIven in Question
        //If not guaranteed, we would need a second pass to confirm
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}
