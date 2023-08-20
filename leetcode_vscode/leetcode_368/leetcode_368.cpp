#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxSize = 1, pos = 0;
        vector<int> dp(n, 1), res;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            int maxVal = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    maxVal = max(maxVal, dp[j]);
                }
            }
            dp[i] += maxVal;
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                pos = i;
            }
        }
        res.push_back(nums[pos]);
        while (dp[pos] > 1) {
            for (int i = pos - 1; i >= 0; i--) {
                if (dp[i] + 1 == dp[pos] && nums[pos] % nums[i] == 0) {
                    res.push_back(nums[i]);
                    pos = i;
                    break;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxSize = 1, pos = 0;
        vector<int> dp(n, 1), res;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            int maxVal = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    maxVal = max(maxVal, dp[j]);
                }
            }
            dp[i] += maxVal;
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                pos = i;
            }
        }
        res.push_back(nums[pos]);
        maxSize--;
        while (maxSize > 0) {
            for (int i = pos - 1; i >= 0; i--) {
                if (dp[i] + 1 == dp[pos] && nums[pos] % nums[i] == 0) {
                    res.push_back(nums[i]);
                    pos = i;
                    maxSize--;
                    break;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> nums{2, 3, 4, 8};
    vector<int> res = sol.largestDivisibleSubset(nums);
    for (const int& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}