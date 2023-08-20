#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (1) {
            if (n == 1) {
                return true;
            }
            if (n % 2) {
                return false;
            }
            n /= 2;
        }
    }
};
int main() {

    system("pause");
    return 0;
}