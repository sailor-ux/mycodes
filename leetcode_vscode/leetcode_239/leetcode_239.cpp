#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 自己写的超时！
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int maxVal = INT_MIN;
        for (int i = 0; i < k; i++) {
            maxVal = max(maxVal, nums[i]);
        }
        res.push_back(maxVal);
        for (int i = k; i < n; i++) {
            if (nums[i] < maxVal) {
                if (nums[i - k] == maxVal) {
                    maxVal = nums[i];
                    for (int j = i - k + 1; j < i; j++) {
                        maxVal = max(maxVal, nums[j]);
                    }
                }
            } else if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
            res.push_back(maxVal);
        }
        return res;
    }
};
int main() {
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    Solution sol;
    vector<int> res = sol.maxSlidingWindow(nums, 3);
    for (auto x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}