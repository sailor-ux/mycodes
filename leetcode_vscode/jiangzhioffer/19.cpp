#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        f[0][0] = true;
        auto match = [&](int i, int j) { // 语法：在函数的内部定义一个函数！！！
            if (i == -1) {
                return false;
            }
            if (p[j] == '.') {
                return true;
            }
            return s[i] == p[j];
        };
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    if (match(i - 1, j - 2)) {
                        f[i][j] = f[i - 1][j] || f[i][j - 2];
                    } else {
                        f[i][j] = f[i][j - 2];
                    }
                } else {
                    if (match(i - 1, j - 1)) {
                        f[i][j] = f[i - 1][j - 1];
                    } else {
                        f[i][j] = false;
                    }
                }
            }
        }
        return f[m][n];
    }
    /* bool match(char ch_s, char ch_p) {
        if (ch_p == '.') {
            return true;
        }
        return ch_s == ch_p;
    } */
};
int main() {
    Solution sol;
    string s = "abbbcc";
    string p = "a*bb*.c";
    cout << sol.isMatch(s, p);
    system("pause");
    return 0;
}