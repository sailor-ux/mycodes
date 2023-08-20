#include <iostream>
#include <vector>
using namespace std;
// �ųɽ���ͳ�ƺ����ж��ٸ����Լ�С
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        return countReversePairs(nums, 0, n - 1);
    }
    // ����nums[left:right]����������Ե���������ʹ��nums[left:right]����ݼ�
    int countReversePairs(vector<int>& nums, int left, int right) {
        if (left == right) {
            return 0;
        }
        int mid = (left + right) / 2;
        int leftReversePairs = countReversePairs(nums, left, mid);
        int rightReversePairs = countReversePairs(nums, mid + 1, right);
        if (nums[mid] > nums[mid + 1]) { // �Ż�
            return leftReversePairs + rightReversePairs + (mid - left + 1) * (right - mid);
        }
        int crossReversePairs = mergeTwoSortedArr(nums, left, mid, right);
        return leftReversePairs + rightReversePairs + crossReversePairs;
    }
    // �ϲ����������������飬�������Խ�����������������Ե����������nums[left:right]�ųɽ���
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
            } else { // temp[i] <= temp[j], ע����ȵ�ʱ��Ҳ������temp[j]�鲢��ȥ����
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