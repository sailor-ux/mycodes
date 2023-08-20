#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (right >= 0 && nums[right] == nums[0]) { // »Ö¸´¶þ¶ÎÐÔ
            right--;
        }
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] >= nums[0]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left + 1 < n ? nums[left + 1] : nums[0];
    }
};
int main() {
    vector<int> nums{2, 3, 4, 5, 0, 1, 2, 2};
    Solution sol;
    cout << sol.findMin(nums);
    system("pause");
    return 0;
}