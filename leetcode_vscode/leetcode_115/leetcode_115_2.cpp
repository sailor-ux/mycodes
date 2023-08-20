#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // dp + 空间复杂度降维
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<unsigned long long> f(n + 1, 0);
        vector<unsigned long long> temp(n + 1, 0); // 巧妙了！！！ 要用到原来的f[j-1]的值，即为temp[j-1]!
        f[0] = 1, temp[0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    f[j] += temp[j - 1];
                }
            }
            temp = f;
        }
        return f[n];
    }
};
int main() {
    Solution sol;
    cout << sol.numDistinct("babgbag", "bag");
    system("pause");
    return 0;
}

// int numDistinct(string s, string t) {
//     int m = s.length(), n = t.length();
//     vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
//     for (int i = 0; i <= m; i++) {
//         for (int j = 0; j <= n; j++) {
//             if (j == 0) {
//                 dp[i][j] = 1;
//                 continue;
//             } else if (i == 0) {
//                 continue;
//             }
//             if (s[i - 1] == t[j - 1]) {
//                 dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//             } else {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }
//     return dp[m][n];
// }