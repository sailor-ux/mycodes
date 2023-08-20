#include <iostream>
using namespace std;
/* 字符串模拟，原地修改字符串
双指针，p1指向原字符串的末尾，p2指向扩容字符串的末尾
见书 */
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, oldSize = s.length();
        for (const char& ch : s) {
            if (ch == ' ') {
                count++;
            }
        }
        int newSize = oldSize + 2 * count;
        s.resize(newSize);
        int p1 = oldSize - 1, p2 = newSize - 1;
        while (p1 != p2) {
            while (s[p1] != ' ') {
                s[p2] = s[p1];
                p1--;
                p2--;
            }
            p1--;
            s[p2--] = '0';
            s[p2--] = '2';
            s[p2--] = '%';
        }
        return s;
    }
};
int main() {
    string s = "We are happy.";
    Solution sol;
    cout << sol.replaceSpace(s);
    system("pause");
    return 0;
}