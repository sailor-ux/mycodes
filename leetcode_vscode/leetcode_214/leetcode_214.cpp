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
        // ���������#��next.back()+1 = s+rev_s������ǰ��׺�ĳ��� = s�������ǰ׺�ĳ��ȣ����ܻ�Խ��s
        // sҪɾ�������ǰ׺����s�Ŀ�ͷҪɾ��next.back()+1��Ԫ��
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