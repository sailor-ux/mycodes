#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        if (isAnswer4(n)) {
            return 4;
        }
        if (isPerfectSquare(n)) {
            return 1;
        }
        for (int numx = 1; numx * numx < n; numx++) {
            // for (int numy = 1; numy * numy < n; numy++) {
            //     if (numx * numx + numy * numy == n) {
            //         return 2;
            //     }
            // }
            if (isPerfectSquare(n - numx * numx)) { // if语句或注释 2选1都可以！！！
                return 2;
            }
        }
        return 3;
    }
    bool isPerfectSquare(int n) {
        int x = sqrt(n);
        return x * x == n;
    }
    bool isAnswer4(int n) {
        while (n % 4 == 0) {
            n /= 4;
        }
        return n % 8 == 7;
    }
};
int main() {
    Solution sol;
    cout << sol.numSquares(13);
    system("pause");
    return 0;
}