#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int resXor = 0; // 全体异或，两个只出现一次的数字的异或，a^b
        for (const int& num : nums) {
            resXor ^= num;
        }
        int index = findFirstBitIs1(resXor); // resXor的第index位为1，其后每一位都为0
        int res1 = 0, res2 = 0;
        for (const int& num : nums) {
            if ((num >> index) & 1) { // num的第index位为1
                res1 ^= num;
            } else { // num的第index位为0
                res2 ^= num;
            }
        }
        return {res1, res2};
    }
    int findFirstBitIs1(int num) {
        int indexBit = 0;
        while ((num & 1) == 0) { // 判断num的第indexBit位
            indexBit++;
            num = num >> 1;
        }
        return indexBit; // num的第indexBit位为1，其后每一位都为0
    }
};
int main() {
    vector<int> nums{2, 4, 3, 6, 3, 2, 5, 5};
    Solution sol;
    vector<int> res = sol.singleNumbers(nums);
    cout << res[0] << ' ' << res[1];
    system("pause");
    return 0;
}