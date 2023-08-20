#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, left = 0;
        for (int read = 0; read < n; read++) {
            if (read == n - 1 || chars[read] != chars[read + 1]) {
                chars[write++] = chars[read];
                int num = read - left + 1;
                if (num > 1) {
                    int anchor = write;
                    while (num) {
                        chars[write++] = num % 10 + '0'; // int=>char
                        num /= 10;
                    }
                    reverse(chars.begin() + anchor, chars.begin() + write); // ��ת����vector��������[anchor,write), ����Ϊ������
                    // reverse(&chars[anchor], &chars[write]); // ��ת����[anchor,write), ����Ϊָ���ַ, ��������ָ���ַ���ɻ��ã���
                }
                left = read + 1;
            }
        }
        // chars.erase(chars.begin() + write, chars.end());
        return write;
    }
};
int main() {
    vector<char> chars{'a', 'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'f'};
    Solution sol;
    cout << sol.compress(chars) << "\n";
    for (const char& ch : chars) {
        cout << ch << ' ';
    }
    system("pause");
    return 0;
}