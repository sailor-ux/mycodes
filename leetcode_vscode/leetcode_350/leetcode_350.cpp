#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            while (i < nums1.size() && j < nums2.size() && nums1[i] != nums2[j]) {
                while (i < nums1.size() && nums1[i] < nums2[j]) {
                    i++;
                }
                while (j < nums2.size() && nums1[i] > nums2[j]) {
                    j++;
                }
            }
            if (i >= nums1.size() || j >= nums2.size()) {
                break;
            }
            int begin1 = i, begin2 = j;
            while (i + 1 < nums1.size() && nums1[i] == nums1[i + 1]) {
                i++;
            }
            while (j + 1 < nums2.size() && nums2[j] == nums2[j + 1]) {
                j++;
            }
            int num = min(i - begin1, j - begin2) + 1;
            while (num) {
                res.push_back(nums1[i]); // nums2[j]
                num--;
            }
            i++;
            j++;
        }
        return res;
    }
};
int main() {
    vector<int> nums1 = {9, 3, 7}, nums2 = {6, 4, 1, 0, 0, 4, 4, 8, 7};
    Solution sol;
    vector<int> res = sol.intersect(nums1, nums2);
    for (auto x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}