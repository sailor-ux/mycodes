#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    string longestPalindrome(string s) {
        int len = int(s.length());
        vector<vector<bool>> dp(len, vector<bool>(len));
        int maxlen = 1, begin = 0;
        // maxlen和begin的初值设置:
        // int maxlen = 1, begin = 0;(最好) 或者:
        // int maxlen < 1, begin = 任意;
        for (int L = 1; L <= len; L++) {
            for (int i = 0; i <= len - L; i++) {
                int j = L + i - 1;
                if (s[i] == s[j]) {
                    if (L < 4) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] && L > maxlen) {
                    maxlen = L;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};
int main() {
    Solution sol;
    cout << sol.longestPalindrome("1");
    return 0;
}