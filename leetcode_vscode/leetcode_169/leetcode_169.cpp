#include <iostream>
#include <vector>
using namespace std;
// 从第一个数开始count=1，遇到相同的就加1，遇到不同的就减1，减到0就重新换个数开始计数，总能找到最多的那个
// 对拼消耗
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, val = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (!count) {
                val = nums[i];
                count++;
            } else if (nums[i] == val) {
                count++;
            } else {
                count--;
            }
        }
        return val;
    }
};
int main() {
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    cout << sol.majorityElement(nums);
    system("pause");
    return 0;
}