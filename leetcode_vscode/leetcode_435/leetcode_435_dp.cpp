#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
        int n = intervals.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            int maxVal = 0;
            for (int j = 0; j < i; j++) {
                if (intervals[j][1] <= intervals[i][0]) {
                    maxVal = max(maxVal, dp[j]);
                }
            }
            dp[i] += maxVal;
            ans = max(ans, dp[i]);
        }
        return n - ans;
    }
};