#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        remove(s, {'(', ')'}, 0, 0);
        return res;
    }
    void remove(string s, const vector<char>& par, int m, int n) {
        int count = 0;
        for (int i = m; i < s.length(); i++) {
            if (s[i] == par[0]) {
                count++;
            } else if (s[i] == par[1]) {
                count--;
            }
            if (count == -1) {
                for (int j = n; j <= i; j++) {
                    if (s[j] == par[1] && (j == n || s[j - 1] != par[1])) {
                        string str = s.substr(0, j) + s.substr(j + 1);
                        remove(str, par, i, j);
                    }
                }
                return;
            }
        }
        reverse(s.begin(), s.end());
        if (par[0] == '(') {
            remove(s, {')', '('}, 0, 0);
        } else {
            res.push_back(s);
        }
    }
};
int main() {
    Solution sol;
    vector<string> res = sol.removeInvalidParentheses("()())()");
    for (auto str : res) {
        cout << str << endl;
    }
    system("pause");
    return 0;
}