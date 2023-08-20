#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int offset = 0; // 右移offset位直到两者相等，最后的结果需要左移offset位
        while (left != right) {
            left >>= 1;
            right >>= 1;
            offset++;
        }
        return left << offset;
    }
};