#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 1);
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            int num2 = 2 * dp[p2], num3 = 3 * dp[p3], num5 = 5 * dp[p5];
            dp[i] = min(min(num2, num3), num5);
            if (num2 == dp[i]) {
                p2++;
            }
            if (num3 == dp[i]) {
                p3++;
            }
            if (num5 == dp[i]) {
                p5++;
            }
        }
        return dp[n];
    }
};
int main() {

    system("pause");
    return 0;
}