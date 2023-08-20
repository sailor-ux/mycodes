#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& str : tokens) {
            if (str != "+" && str != "-" && str != "*" && str != "/") {
                // stk.push(stoi(str));  stoi: string ===> int ¿âº¯Êý
                stk.push(strToInt(str));
            } else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if (str == "+") {
                    stk.push(a + b);
                } else if (str == "-") {
                    stk.push(a - b);
                } else if (str == "*") {
                    stk.push(a * b);
                } else {
                    stk.push(a / b);
                }
            }
        }
        return stk.top();
    }
    int strToInt(const string& str) {
        int res = 0;
        int flag = 1;
        for (const char& ch : str) {
            if (ch == '-') {
                flag = -1;
                continue;
            }
            res = 10 * res + (ch - '0');
        }
        return flag * res;
    }
};
int main() {
    vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution sol;
    cout << sol.evalRPN(tokens);
    system("pause");
    return 0;
}