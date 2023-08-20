#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
  public:
    // memo记忆化 + 回溯dfs
    // 改了好几版，可以看看提交记录
    // 还以用bfs，看了，还需要再看！！！
    // 很多方法，很经典，dp反而最简单(但是思路不好想，靠记忆了)
    // 此题目需要反复看！！！
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st{wordDict.begin(), wordDict.end()};
        vector<bool> memo(s.length(), true);
        return dfs(s, st, 0, memo);
    }
    bool dfs(const string& s, const set<string>& st, int start, vector<bool>& memo) {
        if (!memo[start]) {
            return false;
        }
        if (start == s.length()) {
            return true;
        }
        for (int i = start + 1; i <= s.length(); i++) {
            if (st.find(s.substr(start, i - start)) != st.end() && dfs(s, st, i, memo)) {
                return true;
            }
        }
        memo[start] = false;
        return false;
    }
};
int main() {
    string s = "leetcode";
    vector<string> wordDict{"leet", "leetco", "de"};
    Solution sol;
    cout << sol.wordBreak(s, wordDict);
    system("pause");
    return 0;
}