#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // num不动，bitMask左移
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0); // 全体数字按位相加的结果
        for (const int& num : nums) {
            int bitMask = 1;
            for (int i = 31; i >= 0; i--) {
                bits[i] += (num & bitMask) == 0 ? 0 : 1; // 细节别想当然！
                if (i > 0) {                             // 如果循环32次，左移32位，最后bitMask变成33位，溢出！！
                    bitMask <<= 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] % 3 == 1) {
                res += 1 << (31 - i);
            }
        }
        return res;
    }
    // num右移，bitMask不动，始终为1，始终与1按位相与
    // 这种方式更好！没有那么多要注意的细节！！
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0); // 全体数字按位相加的结果
        for (int num : nums) {
            for (int i = 31; i >= 0; i--) {
                bits[i] += num & 1;
                num >>= 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] % 3 == 1) {
                res += 1 << (31 - i);
            }
        }
        return res;
    }
};
int main() {
    vector<int> nums{6, 1, 1, 1};
    Solution sol;
    cout << sol.singleNumber(nums);
    system("pause");
    return 0;
}