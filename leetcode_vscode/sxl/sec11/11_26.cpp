#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 动态规划
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 1;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int maxVal = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxVal = max(maxVal, dp[j]);
                }
            }
            dp[i] = 1 + maxVal;
            res = max(res, dp[i]);
        }
        return res;
    }
    // 贪心
    int lengthOfLIS(vector<int>& nums) {
    }
};
int main() {

    system("pause");
    return 0;
}