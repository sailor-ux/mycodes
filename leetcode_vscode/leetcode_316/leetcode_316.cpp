#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk; // stack
        vector<int> lastAppear(26);
        vector<bool> isExistInStk(26, false);
        for (int i = 0; i < s.length(); i++) {
            lastAppear[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            if (isExistInStk[s[i] - 'a']) {
                continue;
            }
            while (1) {
                if (stk.empty() || s[i] - stk.back() > 0 || lastAppear[stk.back() - 'a'] < i) {
                    stk.push_back(s[i]);
                    isExistInStk[s[i] - 'a'] = true;
                    break;
                } else {
                    isExistInStk[stk.back() - 'a'] = false;
                    stk.pop_back();
                }
            }
        }
        return stk;
    }
};
int main() {
    string s = "cbacdcbc";
    Solution sol;
    cout << sol.removeDuplicateLetters(s);
    system("pause");
    return 0;
}