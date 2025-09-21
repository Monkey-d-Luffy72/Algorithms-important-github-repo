#include <bits/stdc++.h>
using namespace std;

// LeetCode 229 - Majority Element II (more than n/3 times)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0; //there might be 2 candidates atmost as  [n- 2*(n/3+ 1) < n/3]

        // Step 1: Find potential candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> ans;
        if (count1 > n / 3) ans.push_back(candidate1);
        if (count2 > n / 3) ans.push_back(candidate2);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 3, 1, 1, 1, 3};
    vector<int> ans = sol.majorityElement(nums);

    cout << "Majority Elements (> n/3): ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
