#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int offset = 0; // ����offsetλֱ��������ȣ����Ľ����Ҫ����offsetλ
        while (left != right) {
            left >>= 1;
            right >>= 1;
            offset++;
        }
        return left << offset;
    }
};