#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        int x = 1; // x位数
        while (1) {
            long long digitNum = count(x);
            if (n >= digitNum) {
                x++;
                n -= digitNum;
            } else {
                break;
            }
        }
        int minVal = pow(10, x - 1); // 最小的x位数
        int num = minVal + n / x;
        string str = to_string(num);
        return str[n % x] - '0';
    }
    long long count(long long n) { // 所有的n位数，一共有几位数字
        if (n == 1) {
            return 10;
        }
        long long minVal = pow(10, n - 1);
        long long maxVal = pow(10, n) - 1;
        return (maxVal - minVal + 1) * n;
    }
};
int main() {
    Solution sol;
    cout << sol.findNthDigit(1001);
    system("pause");
    return 0;
}