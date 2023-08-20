#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string str = "";
        int n = s.length(), begin = -1;
        bool flag = true; // T, 当前在找一个单词的起点; F, 起点已经找到, 在找单词的末尾
        for (int i = 0; i < n; i++) {
            if (flag) {
                if (s[i] == ' ') {
                    continue;
                }
                begin = i;
                flag = false;
            } else {
                if (s[i] != ' ') {
                    continue;
                }
                stk.push(s.substr(begin, i - begin));
                flag = true;
            }
        }
        if (!flag) {
            stk.push(s.substr(begin));
        }
        while (!stk.empty()) {
            str += stk.top() + ' ';
            stk.pop();
        }
        str.pop_back();
        return str;
    }
};
int main() {
    Solution sol;
    cout << sol.reverseWords("  hel lo world!  ");
    system("pause");
    return 0;
}