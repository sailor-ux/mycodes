#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0; // ��������nums[i]ʱ��count��ʾnums[i]֮ǰ0����������nums[i]!=0��nums[i]ǰ��countλ
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                continue;
            }
            nums[i - count] = nums[i];
        }
        while (count) { // ���count����ȫΪ 0
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