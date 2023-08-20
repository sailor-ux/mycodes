#include <iostream>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        int maxProduct = 1;
        while (n > 4) { // зЂвт n > 4 !!!
            maxProduct *= 3;
            n -= 3;
        }
        return maxProduct * n;
    }
};
int main() {
    Solution sol;
    cout << sol.integerBreak(5);
    system("pause");
    return 0;
}