#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    // （搜索）寻找所有可能的组合、所有可行的方案、所有的排列
    // 典型的回溯题！！！
    vector<string> permutation(string s) {
        int n = s.length();
        vector<bool> used(n, false);
        string str = "";
        unordered_set<string> res;
        dfs(str, res, used, s, n);
        return vector<string>(res.begin(), res.end());
    }
    void dfs(string& str, unordered_set<string>& res, vector<bool>& used, const string& s, const int& n) {
        if (str.length() == n && !res.count(str)) {
            res.insert(str);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                str.push_back(s[i]);
                dfs(str, res, used, s, n);
                str.pop_back();
                used[i] = false;
            }
        }
    }
};
int main() {
    Solution sol;
    vector<string> res = sol.permutation("aab");
    for (const string& str : res) {
        cout << str << "\n";
    }
    system("pause");
    return 0;
}