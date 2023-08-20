#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    // 寻找所有可能的结果可行的结果，寻找所有可行解，常见的dfs回溯
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> ans, cur;
        dfs(s, 0, st, cur, ans);
        return ans;
    }
    void dfs(const string& s, int idx, const unordered_set<string>& st, vector<string>& cur, vector<string>& ans) {
        if (idx == s.length()) {
            string str = "";
            for (const string& x : cur) {
                str += x + ' ';
            }
            str.pop_back();
            ans.push_back(str);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            string str = s.substr(idx, i - idx + 1);
            if (st.count(str)) {
                cur.push_back(str);
                dfs(s, i + 1, st, cur, ans);
                cur.pop_back();
            }
        }
    }
};
int main() {
    string s = "catsanddog";
    vector<string> wordDict{"cat", "cats", "and", "sand", "dog"};
    Solution sol;
    vector<string> ans = sol.wordBreak(s, wordDict);
    for (string str : ans) {
        cout << str;
    }
    system("pause");
    return 0;
}