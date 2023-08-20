#include <iostream>
using namespace std;
class Solution {
public:
    // 超时！
    int countPrimes(int n) {
        int res = 0;
        for (int num = 2; num < n; num++) {
            if (isPrime(num)) {
                res++;
            }
        }
        return res;
    }
    bool isPrime(int x) { // 判断x是不是质数，枚举[2, sqrt(x)]，若范围内存在x的因数，则x不是质数
        for (int num = 2; num * num <= x; num++) {
            int y = x / num;
            if (y * num == x) { // x % num == 0, return false;
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    cout << sol.countPrimes(10);
    system("pause");
    return 0;
}