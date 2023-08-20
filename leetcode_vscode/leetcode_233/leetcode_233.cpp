#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
/* // ±©Á¦½â·¨
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += numOfOne(i);
        }
        return res;
    }
    int numOfOne(int x) {
        int sum = 0;
        while (x) {
            if (x % 10 == 1) {
                sum++;
            }
            x /= 10;
        }
        return sum;
    }
}; */
class Solution {
public:
    int countDigitOne(int n) {
        int sum = 0;
        string s = to_string(n);
        int len = s.length();
        if (len == 1) {
            return n == 0 ? 0 : 1;
        }
        vector<int> ps(len, 0), ss(len, 0);
        ss[0] = stoi(s.substr(1));
        ps[len - 1] = stoi(s.substr(0, len - 1));
        for (int i = 1; i < len - 1; i++) {
            ps[i] = stoi(s.substr(0, i));
            ss[i] = stoi(s.substr(i + 1));
        }
        for (int i = 0; i < len; i++) {
            sum += ps[i] * pow(10, (len - 1 - i));
            int num = s[i] - '0';
            if (num == 1) {
                sum += ss[i] + 1;
            } else if (num > 1) {
                sum += pow(10, (len - 1 - i));
            }
        }
        return sum;
    }
};
int main() {
    Solution sol;
    cout << sol.countDigitOne(0);
    system("pause");
    return 0;
}