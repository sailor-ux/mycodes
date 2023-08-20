#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            if (p[i - 1] != '*') {
                break;
            }
            dp[0][i] = true;
        } // ÓÐµãÁé»î£¡
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};
int main() {
    Solution sol;
    cout << sol.isMatch("adceb", "*a*b");
    return 0;
}

// int i = 0;
// while (i < n) {
//     if (p[i++] != '*') {
//         break;
//     }
// }