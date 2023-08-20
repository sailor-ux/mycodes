#include <iostream>
#include <vector>
using namespace std;
// �ų�����ͳ�ƺ����ж��ٸ����Լ�С
class Solution {
public:
    int reversePairs(vector<int>& nums) { // ����������������nums�ǻᷢ���ı�ģ���ɵ���������
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        return countReversePairs(nums, 0, n - 1);
    }
    // ������������nums�����[l, r]�������������Ե���������������������˵�������
    int countReversePairs(vector<int>& nums, int left, int right) {
        if (left == right) {
            return 0;
        }
        int mid = (left + right) / 2;
        int leftReversePairs = countReversePairs(nums, left, mid);
        int rightReversePairs = countReversePairs(nums, mid + 1, right);
        if (nums[mid] <= nums[mid + 1]) { // �Ż�
            return leftReversePairs + rightReversePairs;
        }
        int crossReversePairs = mergeTwoSortedArr(nums, left, mid, right);
        return leftReversePairs + rightReversePairs + crossReversePairs;
    }
    // �����Խ�����������������Ե����������ϲ������������飬��ʹ��nums�����[l, r]�����������
    int mergeTwoSortedArr(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp{nums.begin() + left, nums.begin() + right + 1}; // ����ҿ���
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
            if (temp[i] <= temp[j]) { // ע����ȵ�ʱ�򲻿��Թ鲢temp[j], Ӧ��Ҫ��temp[i]�鲢��ȥ��
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