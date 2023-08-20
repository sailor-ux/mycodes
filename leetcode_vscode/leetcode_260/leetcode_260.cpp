#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 类似于136题
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, a = 0, b = 0;
        for (const int& num : nums) {
            x ^= num;
        }
        x = x == INT_MIN ? x : x &= -x; // 防止溢出，不太懂！
        for (const int& num : nums) {
            if (num & x) { // == x 的写法不对，有时候出错，有时候对，不懂！
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};
int main() {
    vector<int> nums{1, 2, 1, 3, 2, 5};
    Solution sol;
    nums = sol.singleNumber(nums);
    for (int x : nums) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}