#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return dfs(s1, s2, s3, true) || dfs(s1, s2, s3, false);
    }
    bool dfs(string s1, string s2, string s3, bool flag) {
        if (s1.empty() && s2.empty() && s3.empty()) {
            return true;
        }
        if (flag) {
            for (int i = 0; i < s1.length() && i < s3.length() && s1[i] == s3[i]; i++) {
                if (dfs(s1.substr(i + 1), s2, s3.substr(i + 1), false)) {
                    return true;
                }
            }
        } else {
            for (int i = 0; i < s2.length() && i < s3.length() && s2[i] == s3[i]; i++) {
                if (dfs(s1, s2.substr(i + 1), s3.substr(i + 1), true)) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    string s1 = "", s2 = "b", s3 = "b";
    Solution sol;
    cout << sol.isInterleave(s1, s2, s3);
    system("pause");
    return 0;
}