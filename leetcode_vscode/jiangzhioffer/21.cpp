#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = n - 1;
        while (p1 < p2) {
            while (p1 < p2 && nums[p1] % 2 == 1) {
                p1++;
            }
            while (p1 < p2 && nums[p2] % 2 == 0) {
                p2--;
            }
            swap(nums[p1], nums[p2]);
        }
        return nums;
    }
    // 函数指针写法
    vector<int> exchange(vector<int>& nums) {
        return exchange(nums, isOdd);
    }
    vector<int> exchange(vector<int>& nums, bool (*func)(int)) {
        int n = nums.size();
        int p1 = 0, p2 = n - 1;
        while (p1 < p2) {
            while (p1 < p2 && func(nums[p1])) {
                p1++;
            }
            while (p1 < p2 && !func(nums[p2])) {
                p2--;
            }
            swap(nums[p1], nums[p2]);
        }
        return nums;
    }
    static bool isOdd(int n) { // 需要static！！！
        return (n & 1) == 1;
    }
};
int main() {
    Solution sol;
    vector<int> nums{1, 2, 3, 4, 5};
    nums = sol.exchange(nums);
    for (int num : nums) {
        cout << num << ' ';
    }
    system("pause");
    return 0;
}