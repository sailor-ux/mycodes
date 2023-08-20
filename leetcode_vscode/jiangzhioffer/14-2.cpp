#include <iostream>
using namespace std;
class Solution {
public:
    const int c = 1000000007;
    int cuttingRope(int n) { // 额外增加了大数问题！！！
        if (n < 4) {
            return n - 1;
        }
        int lineNums = n / 3, yushu = n % 3;
        long res = 1; // res先算pow(3, lineNums-1)
        for (int i = 1; i < lineNums; i++) {
            res = (res * 3) % c;
        }
        if (yushu == 0) {
            res = (res * 3) % c;
        } else if (yushu == 1) {
            res = (res * 4) % c;
        } else {
            res = (res * 6) % c;
        }
        return (int)res;
    }
};
int main() {

    system("pause");
    return 0;
}