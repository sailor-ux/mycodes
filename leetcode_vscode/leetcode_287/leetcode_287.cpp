#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 至少有一个数（至少存在一个数）是至少重复出现2次
    // 必有环，且环的入口就是重复出现2次的数！
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
int main() {
    vector<int> nums{3, 1, 3, 4, 2};
    Solution sol;
    cout << sol.findDuplicate(nums);
    system("pause");
    return 0;
}