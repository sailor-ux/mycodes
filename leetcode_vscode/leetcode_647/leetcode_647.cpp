#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int sum = 0;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = L + i - 1;
                if (s[i] == s[j]) {
                    if (L < 4) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j]) {
                    sum++;
                }
            }
        }
        return sum;
    }
};
int main() {

    system("pause");
    return 0;
}