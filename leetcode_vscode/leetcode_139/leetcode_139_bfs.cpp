#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
class Solution {
  public:
    // bfs广度优先搜索，与第102题二叉树的层序遍历很像！！！
    // bfs的思路差不多，有模板！！
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st{wordDict.begin(), wordDict.end()};
        vector<bool> visited(s.length(), false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 1; i <= len; i++) {
                int start = q.front();
                q.pop();
                if (visited[start]) {
                    continue;
                }
                visited[start] = true;
                for (int i = start + 1; i <= s.length(); i++) {
                    if (st.find(s.substr(start, i - start)) != st.end()) {
                        if (i == s.length()) {
                            return true;
                        }
                        q.push(i);
                    }
                }
            }
        }
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