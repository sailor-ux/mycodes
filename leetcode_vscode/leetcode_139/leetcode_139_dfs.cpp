#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
  public:
    // memo���仯 + ����dfs
    // ���˺ü��棬���Կ����ύ��¼
    // ������bfs�����ˣ�����Ҫ�ٿ�������
    // �ܶ෽�����ܾ��䣬dp�������(����˼·�����룬��������)
    // ����Ŀ��Ҫ������������
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