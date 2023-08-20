#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    string removeKdigits(string num, int k) {
        string res;
        int remainlen = num.length() - k;
        int i = 0;
        for (; i < num.length(); i++) {
            while (1) {
                if (res.empty() || (num[i] - '0') >= (res.back() - '0') || !k) {
                    res.push_back(num[i]);
                    break;
                } else {
                    res.pop_back();
                    k--;
                }
            }
        }
        res = res.substr(0, remainlen);
        int index = 0;
        for (; index < res.length(); index++) {
            if (res[index] != '0') {
                break;
            }
        }
        if (index == res.length()) {
            return "0";
        }
        res = res.substr(index);
        return res;
    }
};
int main() {
    Solution sol;
    cout << sol.removeKdigits("1432219", 3);
    system("pause");
    return 0;
}