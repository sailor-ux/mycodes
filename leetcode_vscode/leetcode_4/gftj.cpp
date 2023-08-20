#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ʱ�临�Ӷ�O(log(min(m, n)))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        int sizeLeft = (m + n + 1) / 2, l = 0, r = m;
        while (l < r) {
            int i = l + (r - l + 1) / 2; // ��ƫ��������ѭ����i>0��nums1[i-1]һ���Ϸ�
            int j = sizeLeft - i;
            if (nums1[i - 1] <= nums2[j]) { // ����<=
                l = i;                      // ������棬������ѭ��
            } else {
                r = i - 1;
            }
        } // l==r�ҵ���nums1�ķָ����ҵ���i
        int i = r, j = sizeLeft - i;
        int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
        int nums1RightMin = i == m ? INT_MAX : nums1[i];
        int nums2LeftMax = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2RightMin = j == n ? INT_MAX : nums2[j];
        if ((m + n) % 2) {
            return max(nums1LeftMax, nums2LeftMax);
        }
        return (double)(max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        int sizeLeft = (m + n + 1) / 2, l = 0, r = m;
        while (l < r) {
            int i = l + (r - l) / 2; // ��ƫ����Ϊ����Ҫ������ѭ����i<m�����Ƶ���j>0����nums2[j-1]һ���Ϸ�
            int j = sizeLeft - i;
            if (nums2[j - 1] <= nums1[i]) { // ����<=
                r = i;                      // ������棬������ѭ��
            } else {
                l = i + 1; // ���赣����ѭ��������
            }
        } // l==r�ҵ���nums1�ķָ����ҵ���i
        int i = r, j = sizeLeft - i;
        int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
        int nums1RightMin = i == m ? INT_MAX : nums1[i];
        int nums2LeftMax = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2RightMin = j == n ? INT_MAX : nums2[j];
        if ((m + n) % 2) {
            return max(nums1LeftMax, nums2LeftMax);
        }
        return (double)(max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2;
    }
};
int main() {
    vector<int> nums1{1, 7, 8, 10};
    vector<int> nums2{2, 3, 4};
    Solution sol;
    cout << sol.findMedianSortedArrays(nums1, nums2);
    system("pause");
    return 0;
}