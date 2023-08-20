#include <iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int x = n % 2;
            n >>= 1;
            res <<= 1;
            res += x;
        }
        return res;
    }
};
int main() {
    Solution sol;
    cout << sol.reverseBits(4294967293);
    system("pause");
    return 0;
}