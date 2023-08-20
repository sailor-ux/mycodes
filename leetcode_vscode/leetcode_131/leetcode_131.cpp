#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // ¶þË¢ÁË£¡£¡£¡
    vector<vector<string>> partition(string s) {
        vector<string> res;
        vector<vector<string>> ress;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = L + i - 1;
                if (s[i] != s[j]) {
                    continue;
                }
                if (L < 4) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
        dfs(s, res, ress, dp, 0);
        return ress;
    }
    void dfs(const string& s, vector<string>& res, vector<vector<string>>& ress, const vector<vector<bool>>& dp, int start) {
        if (start == s.length()) {
            ress.push_back(res);
            return;
        }
        for (int i = start + 1; i <= s.length(); i++) {
            if (dp[start][i - 1]) {
                res.push_back(s.substr(start, i - start));
                dfs(s, res, ress, dp, i);
                res.pop_back();
            }
        }
    }

    // bool isPalindrome(const string& s) {
    //     int l = 0, r = s.length() - 1;
    //     while (l < r) {
    //         if (s[l++] != s[r--]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
};
int main() {
    Solution sol;
    vector<vector<string>> ress = sol.partition("aab");
    for (const vector<string>& res : ress) {
        for (const string& str : res) {
            cout << str << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}