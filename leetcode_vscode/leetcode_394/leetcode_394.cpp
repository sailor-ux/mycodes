#include <iostream>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        bool flag = false;
        string str = "";
        string res = "";
        for (char ch : s) {
            if (ch == ']') {
                for (int i = 0; i < num; i++) {
                    res += str;
                }
                str = "";
                flag = false;
                num = 0;
                continue;
            }
            if (flag) {
                str += ch;
                continue;
            }
            if (ch == '[') {
                flag = true;
                continue;
            }
            if (ch - '0' >= 0 && ch - '0' < 10) {
                ch -= '0';
                num = 10 * num + ch;
            } else {
                res += ch;
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    cout << sol.decodeString("abc3[cd]xyz");
    system("pause");
    return 0;
}