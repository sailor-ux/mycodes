#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        if (N == 0) {
            return 1;
        }
        if (N == 1) {
            return x;
        }
        bool isNeg = false;
        if (N < 0) {
            isNeg = true;
            // n = -n; // n = INT_MIN时，会溢出越界！！将n转换为long类型
            N = -N;
        }
        // double res = myPow(myPow(x, n >> 1), 2); // 当n=2，计算2次方时，这样写出现死循环！
        double res = myPow(x, N >> 1);
        res *= res; // 防止死循环，计算2次方不调用myPow
        res *= (N & 1) ? x : 1;
        if (isNeg) {
            return 1 / res;
        }
        return res;
    }
};
int main() {
    Solution sol;
    cout << sol.myPow(4, -2);
    system("pause");
    return 0;
}