#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int minVal = i - 1; // minValµÄ³õÖµ >= i-1£¡£¡
            for (int j = 1; j * j <= i; j++) {
                minVal = min(minVal, dp[i - j * j]);
            }
            dp[i] += minVal;
        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    cout << sol.numSquares(1);
    system("pause");
    return 0;
}