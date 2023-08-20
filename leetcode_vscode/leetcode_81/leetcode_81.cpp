#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 81������nums�а����ظ���Ԫ�أ����ܳ������������33��û���ظ���Ԫ�ز�������������
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
    // int erfen(vector<int> &nums, int target) {
    //     int left = 0, right = nums.size() - 1;
    //     while (left <= right) {
    //         int mid = (left + right) / 2;
    //         if (nums[mid] == target) {
    //             return mid;
    //         } else if (nums[mid] < target) {
    //             left = mid + 1;
    //         } else {
    //             right = mid - 1;
    //         }
    //     }
    //     return -1;
    // }
};
int main() {
    vector<int> nums = {1, 0, 1, 1, 1};
    Solution sol;
    cout << sol.search(nums, 0);
    return 0;
}