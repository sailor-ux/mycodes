#include <iostream>
#include <vector>
using namespace std;
// 排成升序，统计后面有多少个比自己更小
class Solution01 {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        return countReversePairs(nums, 0, n - 1);
    }
    int countReversePairs(vector<int>& nums, int left, int right) {
        if (left == right) {
            return 0;
        }
        int mid = (left + right) / 2;
        int leftReversePairs = countReversePairs(nums, left, mid);
        int rightReversePairs = countReversePairs(nums, mid + 1, right);
        if (nums[mid] <= nums[mid + 1]) {
            return leftReversePairs + rightReversePairs;
        }
        int crossReversePairs = mergeTwoSortedArr(nums, left, mid, right);
        return leftReversePairs + rightReversePairs + crossReversePairs;
    }
    int mergeTwoSortedArr(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(nums.begin() + left, nums.begin() + right + 1);
        int i = 0, j = mid + 1 - left, k = left, count = 0;
        while (i <= mid - left || j <= right - left) {
            if (i == mid + 1 - left) {
                nums[k++] = temp[j++];
                continue;
            }
            if (j == right - left + 1) {
                nums[k++] = temp[i++];
                count += (right - mid);
                continue;
            }
            if (temp[i] <= temp[j]) {
                nums[k++] = temp[i++];
                count += (j - mid - 1 + left);
            } else {
                nums[k++] = temp[j++];
            }
        }
        return count;
    }
};
class Solution02 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> indexes(n), ans(n, 0);
        for (int i = 0; i < n; i++) {
            indexes[i] = i;
        }
        countReversePairs(nums, indexes, ans, 0, n - 1);
        return ans;
    }
    void countReversePairs(const vector<int>& nums, vector<int>& indexes, vector<int>& ans, int left, int right) {
        if (left == right) {
            return;
        }
        int mid = (left + right) / 2;
        countReversePairs(nums, indexes, ans, left, mid);
        countReversePairs(nums, indexes, ans, mid + 1, right);
        if (nums[indexes[mid]] <= nums[indexes[mid + 1]]) {
            return;
        }
        mergeTwoSortedArr(nums, indexes, ans, left, mid, right);
    }
    void mergeTwoSortedArr(const vector<int>& nums, vector<int>& indexes, vector<int>& ans, int left, int mid, int right) {
        vector<int> temp(indexes.begin() + left, indexes.begin() + right + 1);
        int i = 0, j = mid + 1 - left, k = left;
        while (i <= mid - left || j <= right - left) {
            if (i == mid + 1 - left) {
                indexes[k++] = temp[j++];
                continue;
            }
            if (j == right - left + 1) {
                indexes[k++] = temp[i];
                ans[temp[i++]] += (right - mid);
                continue;
            }
            if (nums[temp[i]] <= nums[temp[j]]) {
                indexes[k++] = temp[i];
                ans[temp[i++]] += (j - mid - 1 + left);
            } else {
                indexes[k++] = temp[j++];
            }
        }
    }
};
int main() {

    system("pause");
    return 0;
}