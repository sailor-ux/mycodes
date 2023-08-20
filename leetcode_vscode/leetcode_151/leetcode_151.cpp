#include <iostream>
#include <stack>
using namespace std;
class Solution {
  public:
    string reverseWords(string s) {
        string res = "";
        stack<string> stk;
        int begin = 0, end = 0;
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && flag) {
                begin = i;
                flag = false;
            }
            if ((s[i] == ' ' || i == s.length() - 1) && !flag) {
                end = i == s.length() - 1 ? i + 1 : i;
                flag = true;
                stk.push(s.substr(begin, end - begin));
            }
        }
        while (!stk.empty()) {
            res += stk.top();
            res += ' ';
            stk.pop();
        }
        res.pop_back();
        return res;
    }
};
int main() {
    string s = "   is  sky the   blue";
    Solution sol;
    cout << sol.reverseWords(s);
    system("pause");
    return 0;
}