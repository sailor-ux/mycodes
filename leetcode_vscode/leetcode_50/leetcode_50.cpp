#include <cmath>
#include <iostream>
using namespace std;
class Solution {
  public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? recursion(x, N) : 1.0 / recursion(x, -N);
    }
    double recursion(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double y = recursion(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }

    //会超时！！！不知道原因
    // double myPow(double x, int n) {
    //     long long N = n;
    //     bool flag = true;
    //     if (N < 0) {
    //         N = -N;
    //         flag = false;
    //     }
    //     if (N == 0) {
    //         return 1.0;
    //     }
    //     if (N % 2 == 0) {
    //         if (flag) {
    //             return myPow(x, N / 2) * myPow(x, N / 2);
    //         }
    //         return 1.0 / (myPow(x, N / 2) * myPow(x, N / 2));
    //     }
    //     if (flag) {
    //         return myPow(x, N / 2) * myPow(x, N / 2) * x;
    //     }
    //     return 1.0 / (myPow(x, N / 2) * myPow(x, N / 2) * x);
    // }
};
int main() {
    Solution sol;
    cout << sol.myPow(0.00001, 2147483647);
    return 0;
}