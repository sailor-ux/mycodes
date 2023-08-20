#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int minVal = INT_MAX;
            for (const int& coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != -1) {
                    minVal = min(minVal, dp[i - coin]);
                }
            }
            if (minVal == INT_MAX) {
                dp[i] = -1;
            } else {
                dp[i] += minVal;
            }
        }
        return dp[amount];
    }
};
int main() {
    vector<int> coins{1,2,5};
    Solution sol;
    cout<<sol.coinChange(coins,11);
    system("pause");
    return 0;
}