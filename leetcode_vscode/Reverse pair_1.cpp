#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 归并排序
    /* vector<int> mergeSort(const vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums;
        }
        vector<int> res(n);
        vector<int> numsLeft{nums.begin(), nums.begin() + n / 2};
        vector<int> numsRight{nums.begin() + n / 2, nums.end()};
        numsLeft = mergeSort(numsLeft);
        numsRight = mergeSort(numsRight);
        int i = 0, j = 0, k = 0, leftSize = n / 2, rightSize = n - n / 2;
        while (i < leftSize || j < rightSize) {
            if (i == leftSize) {
                res[k++] = numsRight[j++];
                continue;
            }
            if (j == rightSize) {
                res[k++] = numsLeft[i++];
                continue;
            }
            if (numsLeft[i] < numsRight[j]) {
                res[k++] = numsLeft[i++];
            } else {
                res[k++] = numsRight[j++];
            }
        }
        return res;
    } */
    /* // 基于归并排序改写成计算逆序对的数量
    vector<int> mergeSort(const vector<int>& nums, int& count) {
        int n = nums.size();
        if (n < 2) {
            return nums;
        }
        vector<int> res(n);
        vector<int> numsLeft{nums.begin(), nums.begin() + n / 2};
        vector<int> numsRight{nums.begin() + n / 2, nums.end()};
        numsLeft = mergeSort(numsLeft, count);
        numsRight = mergeSort(numsRight, count);
        int i = 0, j = 0, k = 0, leftSize = n / 2, rightSize = n - n / 2;
        while (i < leftSize || j < rightSize) {
            if (i == leftSize) {
                res[k++] = numsRight[j++];
                continue;
            }
            if (j == rightSize) {
                res[k++] = numsLeft[i++];
                continue;
            }
            if (numsLeft[i] <= numsRight[j]) { // 必须要有等于！！
                res[k++] = numsLeft[i++];
            } else {
                res[k++] = numsRight[j++];
                count += (leftSize - i);
            }
        }
        return res;
    }
    int reversePairs(const vector<int>& nums) {
        int count = 0;
        mergeSort(nums, count);
        return count;
    } */
    // --------------------------------------------------------------
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
        /* vector<int> temp(right - left + 1);
        for (int i = left; i <= right; i++) {
            temp[i - left] = nums[i];
        } */
        vector<int> temp{nums.begin() + left, nums.begin() + right + 1}; // 左闭右开！
        int i = 0, j = mid + 1 - left, k = left, count = 0;
        while (i <= mid - left || j <= right - left) {
            if (i == mid + 1 - left) {
                nums[k++] = temp[j++];
                continue;
            }
            if (j == right + 1 - left) {
                nums[k++] = temp[i++];
                continue;
            }
            if (temp[i] <= temp[j]) { // 注意相等的时候应该要把temp[i]归并过去！
                nums[k++] = temp[i++];
            } else {
                nums[k++] = temp[j++];
                count += (mid - i + 1 - left);
            }
        }
        return count;
    }
    /* int mergeTwoSortedArr(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp = nums; // temp数组这么长会超时！！
        int i = left, j = mid + 1, k = left, count = 0;
        while (i <= mid || j <= right) {
            if (i == mid + 1) {
                nums[k++] = temp[j++];
                continue;
            }
            if (j == right + 1) {
                nums[k++] = temp[i++];
                continue;
            }
            if (temp[i] <= temp[j]) { // 注意相等的时候应该要把temp[i]归并过去
                nums[k++] = temp[i++];
            } else {
                nums[k++] = temp[j++];
                count += (mid - i + 1);
            }
        }
        return count;
    } */
};
// 排成升序，统计前面有多少个比自己大
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