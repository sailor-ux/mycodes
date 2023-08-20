#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i++) {
            res[i] = countNumOf1(i);
        }
        return res;
    }
    int countNumOf1(int x) {
        int count = 0; // count表示x的二进制各位求和，即x的二进制中1的个数或1出现的次数
        while (x) {
            count += x % 2;
            x >>= 1;
        }
        return count;
    }
};
int main() {

    system("pause");
    return 0;
}