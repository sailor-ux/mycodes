#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 时间复杂度O((m+n)/2), 还不满足O(log(m+n))
    // 我的这种做法很多细节要注意！！！
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, m = nums1.size(), n = nums2.size(), flag = (m + n) % 2;
        int count = flag == 1 ? (m + n) / 2 : (m + n) / 2 - 1;
        if (!m || !n) {
            vector<int>& nums = nums1;
            if (!m) {
                nums = nums2;
            }
            if (flag) {
                return nums[count];
            }
            return ((double)nums[count] + (double)nums[count + 1]) / 2;
        }
        while (count) {
            count--;
            if (i == m) {
                j++;
                continue;
            }
            if (j == n) {
                i++;
                continue;
            }
            if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        if (flag) {
            if (i == m) {
                return nums2[j];
            }
            if (j == n) {
                return nums1[i];
            }
            return min(nums1[i], nums2[j]);
        }
        vector<int> arr;
        if (i < m) {
            arr.push_back(nums1[i]);
        }
        if (j < n) {
            arr.push_back(nums2[j]);
        }
        if (i + 1 < m) {
            arr.push_back(nums1[i + 1]);
        }
        if (j + 1 < n) {
            arr.push_back(nums2[j + 1]);
        }
        sort(arr.begin(), arr.end());
        return ((double)arr[0] + (double)arr[1]) / 2;
    }
};
int main() {
    vector<int> nums1{1};
    vector<int> nums2{2, 3, 4};
    Solution sol;
    cout << sol.findMedianSortedArrays(nums1, nums2);
    system("pause");
    return 0;
}