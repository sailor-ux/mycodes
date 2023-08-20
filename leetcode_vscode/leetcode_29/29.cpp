#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) { // ����ģ��
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
    long mul(long a, long k) { // ����(�˷�)ģ��
        long ans = 0;
        while (k > 0) {
            if ((k & 1) == 1) { // == ���ȼ����� &
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