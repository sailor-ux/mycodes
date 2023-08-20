#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    // 每一个前面补0；每一个前面补1，逆序加到后面（记忆方法）
    vector<int> grayCode(int n) {
        vector<string> resStr{"0", "1"};
        if (n == 1) {
            return transform(resStr);
        }
        stack<string> stk;
        while (n > 1) {
            for (int i = 0; i < resStr.size(); i++) {
                stk.push('1' + resStr[i]);
                resStr[i] = '0' + resStr[i];
            }
            while (!stk.empty()) {
                resStr.push_back(stk.top());
                stk.pop();
            }
            n--;
        }
        return transform(resStr);
    }
    vector<int> transform(const vector<string>& resStr) {
        vector<int> res;
        for (const string& str : resStr) {
            res.push_back(strToInt(str));
        }
        return res;
    }
    int strToInt(const string& str) {
        int len = str.length(), sum = 0;
        for (int i = 0; i < len; i++) {
            int x = str[i] - '0';
            sum += x * pow(2, len - 1 - i);
        }
        return sum;
    }
};
int main() {
    Solution sol;
    vector<int> res = sol.grayCode(2);
    for (const int& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}