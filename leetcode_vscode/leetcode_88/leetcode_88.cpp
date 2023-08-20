#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int* sorted = new int[m + n];
        int p1 = 0, p2 = 0;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                sorted[p1 + p2 - 1] = nums2[p2++]; //注意执行顺序：拿到值 -> 自增1 -> 赋值
                continue;
            }
            if (p2 == n) {
                sorted[p1 + p2 - 1] = nums1[p1++];
                continue;
            }
            if (nums1[p1] <= nums2[p2]) {
                sorted[p1 + p2] = nums1[p1]; //效果一样
                p1++;
            } else {
                sorted[p1 + p2 - 1] = nums2[p2++];
            }
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = sorted[i];
        }
    }
};
int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution sol;
    sol.merge(nums1, 3, nums2, 3);
    for (int x : nums1) {
        cout << x << ' ';
    }
    // system("pause");
    return 0;
}