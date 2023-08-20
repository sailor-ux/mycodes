#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    string removeKdigits(string num, int k) {
        string res;
        int i = 0;
        for (; i < num.length() && k > 0; i++) {
            while (1) {
                if (res.empty() || (num[i] - '0') >= (res.back() - '0') || !k) {
                    res.push_back(num[i]);
                    break;
                }
                res.pop_back();
                k--;
            }
        }
        for (int j = i; j < num.length(); j++) {
            res.push_back(num[j]);
        }
        while (k) {
            res.pop_back();
            k--;
        }
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
    cout << sol.removeKdigits("10200", 2);
    system("pause");
    return 0;
}