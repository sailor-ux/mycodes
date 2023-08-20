#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 1;
        vector<int> dp(n, INT_MIN);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] = dp[i] == INT_MIN ? 1 : dp[i] + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}