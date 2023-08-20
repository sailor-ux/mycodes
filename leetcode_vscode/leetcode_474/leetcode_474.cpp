#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getZerosOnes(const string& str) {
        vector<int> zerosOnes(2, 0);
        for (const char& ch : str) {
            zerosOnes[ch - '0']++;
        }
        return zerosOnes;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= len; i++) {
            vector<int> zerosOnes = getZerosOnes(strs[i - 1]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - 1][j - zeros][k - ones]);
                    }
                }
            }
        }
        return dp[len][m][n];
    }
};
int main() {

    system("pause");
    return 0;
}