#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // dp超时，超时原因可能是不仅算了n=>1的最小替换次数，还算了(1~n-1)=>1的最小替换次数，多计算了很多中间状态！
    int integerReplacement(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            if (i % 2) {
                dp[i] = 2 + min(dp[(i + 1) / 2], dp[(i - 1) / 2]);
            } else {
                dp[i] = 1 + dp[i / 2];
            }
        }
        return dp[n];
    }
    //递归没问题！
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        }
        long temp = n; // n==INT_MAX， n+1超出int的表示范围，溢出，越界
        return 2 + min(integerReplacement((temp + 1) / 2), integerReplacement((temp - 1) / 2));
    }
};
int main() {

    system("pause");
    return 0;
}