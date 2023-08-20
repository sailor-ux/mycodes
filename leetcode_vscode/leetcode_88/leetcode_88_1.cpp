#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                nums1[p2 + 1] = nums2[p2--];
            } else if (p2 == -1) {
                // nums1[p1] = nums1[p1];
                // p1--;
                break;
            } else if (nums1[p1] > nums2[p2]) {
                nums1[p1 + p2 + 2] = nums1[p1--];
            } else {
                nums1[p1 + p2 + 2] = nums2[p2--];
            }
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
    return 0;
}