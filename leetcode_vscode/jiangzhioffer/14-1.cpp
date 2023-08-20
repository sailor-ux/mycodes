#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) {
            return n - 1;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3; // ����������㣳�����
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[n];
    }
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
        }
        return dp[n];
    }
    int cuttingRope(int n) { // ̰��˼·�������ܵؼ��ɳ���Ϊ3�����ɶ�
        if (n < 4) {
            return n - 1;
        }
        int zhishu = n / 3;
        int yushu = n % 3;
        if (yushu == 0) {
            return pow(3, zhishu);
        } else if (yushu == 1) {
            return 4 * pow(3, zhishu - 1);
        } else {
            return 2 * pow(3, zhishu);
        }
    }
};
int main() {
    Solution sol;
    cout << sol.cuttingRope(5);
    system("pause");
    return 0;
}