#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // unordered_set<string> set;
        // �ж�һ���ַ���s.substr(j, i - j)�Ƿ���wordDict���У�vector�������߱�����(find)����
        // ������wordDict�����ַ�������set
        set<string> st(wordDict.begin(), wordDict.end());
        // for (const string& word : wordDict) {
        //     st.insert(word);
        // }
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j <= i - 1; j++) {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
int main() {
    string s = "leetcode";
    vector<string> wordDict{"leet", "code"};
    Solution sol;
    cout << sol.wordBreak(s, wordDict);
    system("pause");
    return 0;
}