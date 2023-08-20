#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> stk;
        string res = "";
        int num = 0;
        for (char& ch : s) {
            if (isdigit(ch)) {
                ch -= '0';
                num = 10 * num + ch;
            } else if (ch == '[') {
                stk.push({num, res});
                num = 0;
                res = "";
            } else if (ch == ']') {
                string str = res;
                auto doub = stk.top();
                stk.pop();
                for (int i = 0; i < doub.first - 1; i++) {
                    res += str;
                }
                res = doub.second + res;
            } else {
                res += ch;
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    cout << sol.decodeString("abc3[cd]xyz");
    system("pause");
    return 0;
}