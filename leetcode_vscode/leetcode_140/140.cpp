#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    // Ѱ�����п��ܵĽ�����еĽ����Ѱ�����п��н⣬������dfs����
    unordered_set<string> st;
    vector<string> ans, cur;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        dfs(s, 0);
        return ans;
    }
    void dfs(const string& s, int idx) { // Ϊ�˼��ٲ�����������д�����ݳ�Ա����Ա����
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
                dfs(s, i + 1);
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