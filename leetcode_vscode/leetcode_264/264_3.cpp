#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(1, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        while (dp.size() < n) {
            dp.push_back(min(min(2 * dp[p2], 3 * dp[p3]), 5 * dp[p5]));
            if (dp.back() == 2 * dp[p2]) {
                p2++;
            }
            if (dp.back() == 3 * dp[p3]) {
                p3++;
            }
            if (dp.back() == 5 * dp[p5]) {
                p5++;
            }
        }
        return dp.back();
    }
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            int num2 = 2 * dp[p2], num3 = 3 * dp[p3], num5 = 5 * dp[p5];
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2) {
                p2++;
            }
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
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