#include <iostream>
using namespace std;
class Solution {
public:
    // ±©Á¦³¬Ê±£¡
    int nthUglyNumber(int n) {
        int num = 1;
        while (1) {
            if (isUgly(num) && (--n == 0)) {
                return num;
            }
            num++;
        }
        return -1;
    }
    bool isUgly(int n) {
        if (n < 1) {
            return false;
        }
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        return n == 1;
    }
};
int main() {

    system("pause");
    return 0;
}