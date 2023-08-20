#include <iostream>
#include <vector>
using namespace std;
// 排成降序，统计后面有多少个比自己小
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        return countReversePairs(nums, 0, n - 1);
    }
    // 计算nums[left:right]包含的逆序对的数量，并使得nums[left:right]降序递减
    int countReversePairs(vector<int>& nums, int left, int right) {
        if (left == right) {
            return 0;
        }
        int mid = (left + right) / 2;
        int leftReversePairs = countReversePairs(nums, left, mid);
        int rightReversePairs = countReversePairs(nums, mid + 1, right);
        if (nums[mid] > nums[mid + 1]) { // 优化
            return leftReversePairs + rightReversePairs + (mid - left + 1) * (right - mid);
        }
        int crossReversePairs = mergeTwoSortedArr(nums, left, mid, right);
        return leftReversePairs + rightReversePairs + crossReversePairs;
    }
    // 合并左右两个降序数组，并计算跨越左右两个数组的逆序对的数量，最后nums[left:right]排成降序
    int mergeTwoSortedArr(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(nums.begin() + left, nums.begin() + right + 1);
        int i = 0, j = mid + 1 - left, k = left, count = 0;
        while (i <= mid - left || j <= right - left) {
            if (i == mid - left + 1) {
                nums[k++] = temp[j++];
                continue;
            }
            if (j == right - left + 1) {
                nums[k++] = temp[i++];
                continue;
            }
            if (temp[i] > temp[j]) {
                nums[k++] = temp[i++];
                count += (right - left - j + 1);
            } else { // temp[i] <= temp[j], 注意相等的时候也必须是temp[j]归并过去！！
                nums[k++] = temp[j++];
            }
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<int> nums{1, 3, 2, 3, 1};
    cout << sol.reversePairs(nums) << endl;
    for (const int& num : nums) {
        cout << num << ' ';
    }
    system("pause");
    return 0;
}