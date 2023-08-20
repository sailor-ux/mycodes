#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    unordered_map<string, bool> memoMap;
    bool isInterleave(string s1, string s2, string s3) {
        return dfs(s1, s2, s3, 0, 0, 0, true) || dfs(s1, s2, s3, 0, 0, 0, false);
    }
    bool dfs(string s1, string s2, string s3, int beginS1, int beginS2, int beginS3, bool flag) {
        string str = to_string(beginS1) + "-" + to_string(beginS2) + "-" + to_string(beginS3) + "-" + to_string(flag);
        if (memoMap.count(str)) {
            return memoMap[str];
        }
        if (beginS1 == s1.length() && beginS2 == s2.length() && beginS3 == s3.length()) {
            memoMap[str] = true;
            return true;
        }
        if (flag) {
            for (int i = beginS1, j = beginS3; i < s1.length() && j < s3.length() && s1[i] == s3[j]; i++, j++) {
                if (dfs(s1, s2, s3, i + 1, beginS2, j + 1, false)) {
                    memoMap[str] = true;
                    return true;
                }
            }
        } else {
            for (int i = beginS2, j = beginS3; i < s2.length() && j < s3.length() && s2[i] == s3[j]; i++, j++) {
                if (dfs(s1, s2, s3, beginS1, i + 1, j + 1, true)) {
                    memoMap[str] = true;
                    return true;
                }
            }
        }
        memoMap[str] = false;
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