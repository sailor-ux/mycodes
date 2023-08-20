#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] - '0' >= 0 && s[i] - '0' <= 9) || (s[i] >= 65 && s[i] <= 90)) {
                str += s[i];
            }
            if (s[i] >= 97 && s[i] <= 122) {
                str += s[i] - 32;
            }
        }
        // cout << str << endl;
        int n = str.length();
        if (!n) {
            return true;
        }
        // �ж��ַ���str�Ƿ�Ϊ���Ĵ�
        // dp������ʱ������
        // �������������Ӵ�������dp��������
        // vector<vector<bool>> dp(n, vector<bool>(n, false));
        // for (int L = 1; L <= n; L++) {
        //     for (int i = 0; i <= n - L; i++) {
        //         int j = L + i - 1;
        //         if (str[i] != str[j]) {
        //             continue;
        //         }
        //         if (L < 4) {
        //             dp[i][j] = true;
        //         } else {
        //             dp[i][j] = dp[i + 1][j - 1];
        //         }
        //     }
        // }
        // return dp[0][n - 1];

        // ˫ָ�뷨���ᳬʱ������
        int l = 0, r = n - 1;
        while (l < r) {
            if (str[l++] != str[r--]) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama");
    system("pause");
    return 0;
}