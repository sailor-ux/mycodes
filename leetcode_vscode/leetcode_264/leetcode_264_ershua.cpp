#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(min(2 * dp[p2], 3 * dp[p3]), 5 * dp[p5]);
            if (2 * dp[p2] == dp[i]) {
                p2++;
            }
            if (3 * dp[p3] == dp[i]) {
                p3++;
            }
            if (5 * dp[p5] == dp[i]) {
                p5++;
            }
        }
        return dp[n - 1];
    }
};
int main() {

    system("pause");
    return 0;
}