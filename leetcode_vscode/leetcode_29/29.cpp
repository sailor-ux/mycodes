#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) { // 二分模板
        long x = dividend, y = divisor;
        bool isNeg = false;
        if ((x < 0 && y > 0) || (x > 0 && y < 0)) {
            isNeg = true;
        }
        if (x < 0) {
            x = -x;
        }
        if (y < 0) {
            y = -y;
        }
        long l = 0, r = x;
        while (l < r) {
            long mid = (l + r + 1) / 2;
            if (mul(mid, y) <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        long ans = isNeg ? -l : l;
        if (ans > INT_MAX) {
            return INT_MAX;
        }
        if (ans < INT_MIN) {
            return INT_MIN;
        }
        return (int)ans;
    }
    long mul(long a, long k) { // 倍增(乘法)模板
        long ans = 0;
        while (k > 0) {
            if ((k & 1) == 1) { // == 优先级高于 &
                ans += a;
            }
            k >>= 1;
            a += a;
        }
        return ans;
    }
};
int main() {

    system("pause");
    return 0;
}