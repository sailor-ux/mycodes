#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> combination;
        vector<string> combinations;
        dfs(s, combination, combinations);
        return combinations;
    }
    void dfs(string s, vector<string>& combination, vector<string>& combinations) {
        //加上可以再快一点
        // if (!s.empty() && combination.size() == 4) {
        //     return;
        // }
        if (s.empty() && combination.size() == 4) {
            string str;
            for (int i = 0; i < 4; i++) {
                str += (combination[i] + '.');
            }
            str.pop_back();
            combinations.push_back(str);
            return;
        }
        for (int len = 1; len < 4 && len <= s.length(); len++) {
            if (isValid(s.substr(0, len))) {
                combination.push_back(s.substr(0, len));
                dfs(s.substr(len), combination, combinations);
                combination.pop_back();
            }
        }
    }
    bool isValid(string s) {
        if (s[0] == '0' && s.length() > 1) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum = 10 * sum + (s[i] - '0');
        }
        if (sum > 255) {
            return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<string> combinations = sol.restoreIpAddresses("101023");
    for (string combination : combinations) {
        cout << combination << "\n";
    }
    // system("pause");
    return 0;
}