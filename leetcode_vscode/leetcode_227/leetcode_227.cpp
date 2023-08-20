#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
// 与224题存在通用的模板！！！
class Solution {
public:
    unordered_map<char, int> hashMap{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}, {'^', 3}};
    int calculate(string s) {
        replace(s);
        stack<char> ops;
        stack<int> nums;
        nums.push(0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ops.push('(');
            } else if (s[i] == ')') {
                while (ops.top() != '(') {
                    calc(ops, nums);
                }
                ops.pop();
            } else if (isdigit(s[i])) {
                int val = s[i] - '0', j = i + 1;
                while (j < n && isdigit(s[j])) {
                    val = 10 * val + (s[j++] - '0');
                }
                i = j - 1;
                nums.push(val);
            } else {
                if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
                    nums.push(0);
                }
                while (!ops.empty() && ops.top() != '(') {
                    if (hashMap[ops.top()] >= hashMap[s[i]]) { // 只有满足「栈内运算符」比「当前运算符」优先级高/同等，才进行运算
                        calc(ops, nums);
                    } else {
                        break;
                    }
                }
                ops.push(s[i]);
            }
        }
        while (!ops.empty()) {
            calc(ops, nums);
        }
        return nums.top();
    }
    void calc(stack<char>& ops, stack<int>& nums) {
        if (nums.size() >= 2 && !ops.empty()) {
            char operatorChar = ops.top();
            ops.pop();
            int rightNum = nums.top();
            nums.pop();
            int leftNum = nums.top();
            nums.pop();
            int ans = 0;
            if (operatorChar == '+') {
                ans = leftNum + rightNum;
            } else if (operatorChar == '-') {
                ans = leftNum - rightNum;
            } else if (operatorChar == '*') {
                ans = leftNum * rightNum;
            } else if (operatorChar == '/') {
                ans = leftNum / rightNum;
            } else if (operatorChar == '^') {
                ans = (int)pow(leftNum, rightNum);
            } else if (operatorChar == '%') {
                ans = leftNum % rightNum;
            }
            nums.push(ans);
        }
    }
    void replace(string& s) {
        int pos;
        while ((pos = s.find(' ')) != string::npos) {
            // s.erase(s.begin() + pos);
            s.replace(pos, 1, "");
        }
    }
};
int main() {
    Solution sol;
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << sol.calculate(s);
    system("pause");
    return 0;
}