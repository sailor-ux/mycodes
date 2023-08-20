#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0; // 当遍历到nums[i]时，count表示nums[i]之前0的数量。若nums[i]!=0，nums[i]前移count位
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                continue;
            }
            nums[i - count] = nums[i];
        }
        while (count) { // 最后count个数全为 0
            nums[nums.size() - count--] = 0;
        }
    }
};
int main() {
    vector<int> nums{0, 1, 0, 3, 12};
    Solution sol;
    sol.moveZeroes(nums);
    for (int num : nums) {
        cout << num << ' ';
    }
    system("pause");
    return 0;
}