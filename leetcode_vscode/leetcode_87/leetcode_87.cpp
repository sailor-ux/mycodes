#include <iostream>
#include <vector>
using namespace std;
// b’æ
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n + 1, vector<bool>(n + 1, false)));
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (k == 1) {
                        dp[i][j][k] = s1[i] == s2[j];
                    } else {
                        for (int u = 1; u < k; u++) {
                            dp[i][j][k] = (dp[i][j][u] && dp[i + u][j + u][k - u]) || (dp[i][j + k - u][u] && dp[i + u][j][k - u]);
                            if (dp[i][j][k]) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n + 1, vector<bool>(n + 1, false)));
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (k == 1) {
                        dp[i][j][k] = s1[i] == s2[j];
                        continue;
                    }
                    for (int u = 1; u < k; u++) {
                        bool o1 = dp[i][j][u] && dp[i + u][j + u][k - u];     // ±£≥÷À≥–Ú
                        bool o2 = dp[i][j + k - u][u] && dp[i + u][j][k - u]; // ΩªªªÀ≥–Ú
                        if (o1 || o2) {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
int main() {

    system("pause");
    return 0;
}