#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        string ori = s;
        reverse(s.begin(), s.end());
        string strCat = ori + "#" + s;
        // 如果不设置#，next.back()+1 = s+rev_s的最长相等前后缀的长度 = s的最长回文前缀的长度，可能会越过s
        // s要删掉最长回文前缀，即s的开头要删掉next.back()+1个元素
        int n = strCat.length();
        vector<int> next(n);
        int j = -1;
        next[0] = j;
        for (int i = 1; i < n; i++) {
            while (j >= 0 && strCat[i] != strCat[j + 1]) {
                j = next[j];
            }
            if (strCat[i] == strCat[j + 1]) {
                j++;
            }
            next[i] = j;
        }
        return s + ori.substr(next.back() + 1);
    }
};
int main() {
    Solution sol;
    cout << sol.shortestPalindrome("aabba");
    system("pause");
    return 0;
}