#include <iostream>
#include <vector>
using namespace std;
// 滑动窗口，类似于76题
// 左右边界交替右移（固定左边界，有边界右移；固定右边界，左边界右移）
class Solution {
public:
    vector<int> minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, begin = -1, minlen = nums.size() + 1, sum = nums[0];
        bool flag = false;
        while (r < nums.size()) {
            while (sum < target) {
                if (++r == nums.size()) {
                    flag = true;
                    break;
                }
                sum += nums[r];
            }
            if (flag) {
                break;
            }
            while (sum >= target) {
                sum -= nums[l++];
            }
            if (r - l + 2 < minlen) {
                begin = l - 1;
                minlen = r - l + 2;
            }
        }
        if (begin == -1) {
            return {};
        }
        nums.assign(nums.begin() + begin, nums.begin() + begin + minlen);
        return nums;
    }
};
int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution sol;
    nums = sol.minSubArrayLen(7, nums);
    for (int x : nums) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}