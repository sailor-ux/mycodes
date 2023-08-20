#include <iostream>
#include <vector>
using namespace std;
// 排成升序，统计后面有多少个比自己小
class Solution {
public:
    int reversePairs(vector<int>& nums) { // 函数对于输入数组nums是会发生改变的！变成递增的有序
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        return countReversePairs(nums, 0, n - 1);
    }
    // 不仅仅返回了nums数组的[l, r]区间包含的逆序对的数量，还将该区间进行了递增排序
    int countReversePairs(vector<int>& nums, int left, int right) {
        if (left == right) {
            return 0;
        }
        int mid = (left + right) / 2;
        int leftReversePairs = countReversePairs(nums, left, mid);
        int rightReversePairs = countReversePairs(nums, mid + 1, right);
        if (nums[mid] <= nums[mid + 1]) { // 优化
            return leftReversePairs + rightReversePairs;
        }
        int crossReversePairs = mergeTwoSortedArr(nums, left, mid, right);
        return leftReversePairs + rightReversePairs + crossReversePairs;
    }
    // 计算跨越左右两个数组的逆序对的数量，即合并两个有序数组，并使得nums数组的[l, r]区间递增有序
    int mergeTwoSortedArr(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp{nums.begin() + left, nums.begin() + right + 1}; // 左闭右开！
        int i = 0, j = mid + 1 - left, k = left, count = 0;
        while (i <= mid - left || j <= right - left) {
            if (i == mid + 1 - left) {
                nums[k++] = temp[j++];
                continue;
            }
            if (j == right + 1 - left) {
                nums[k++] = temp[i++];
                count += (right - mid);
                continue;
            }
            if (temp[i] <= temp[j]) { // 注意相等的时候不可以归并temp[j], 应该要把temp[i]归并过去！
                nums[k++] = temp[i++];
                count += (j - mid + left - 1);
            } else {
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