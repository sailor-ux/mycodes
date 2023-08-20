#include <deque>
#include <iostream>
using namespace std;
// 不用stack 而用deque
class Solution {
  public:
    string reverseWords(string s) {
        deque<string> d;
        string res = "", word = "";
        int left = 0, right = s.length() - 1;
        while (s[left] == ' ') {
            left++;
        };
        while (s[right] == ' ') {
            right--;
        }
        while (left <= right) {
            char c = s[left];
            if (c == ' ' && !word.empty()) {
                d.push_front(word); // 入栈
                word = "";
            } else if (c != ' ') {
                word += c;
            }
            left++;
        }
        res = word;
        while (!d.empty()) {
            res += ' ';
            res += d.front(); // 栈顶
            d.pop_front();    // 出栈
        }
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