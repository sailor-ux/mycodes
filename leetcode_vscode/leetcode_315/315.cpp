#include <iostream>
#include <vector>
using namespace std;
// �ų�����ͳ�ƺ����ж��ٸ����Լ�С
class Solution {
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
        if (nums[indexes[mid]] <= nums[indexes[mid + 1]]) { // �Ż�����������������²����������ĺ��滹����С��
            return;
        }
        mergeTwoSortedArr(nums, indexes, ans, left, mid, right); // ִ�е�ԭ������Ϊ���������ĺ��滹����С��
    }
    void mergeTwoSortedArr(const vector<int>& nums, vector<int>& indexes, vector<int>& ans, int left, int mid, int right) {
        vector<int> temp{indexes.begin() + left, indexes.begin() + right + 1}; // ����ҿ���
        int i = 0, j = mid + 1 - left, k = left;
        while (i <= mid - left || j <= right - left) {
            if (i == mid + 1 - left) {
                indexes[k++] = temp[j++];
                continue;
            }
            if (j == right + 1 - left) {
                indexes[k++] = temp[i];
                ans[temp[i++]] += (right - mid);
                continue;
            }
            if (nums[temp[i]] <= nums[temp[j]]) {
                indexes[k++] = temp[i];
                ans[temp[i++]] += (j - mid + left - 1);
            } else {
                indexes[k++] = temp[j++];
            }
        }
    }
};
int main() {
    Solution sol;
    vector<int> nums{1, 3, 2, 3, 1};
    vector<int> ans = sol.countSmaller(nums);
    for (const int& num : nums) {
        cout << num << ' ';
    }
    system("pause");
    return 0;
}