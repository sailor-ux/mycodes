#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], getMax(nums, i));
        }
        return dp[n - 1];
    }
    int getMax(vector<int>& nums, int index) {
        int maxVal = nums[index];
        int temp = maxVal;
        for (int i = index - 1; i >= 0; i--) {
            temp *= nums[i];
            maxVal = temp > maxVal ? temp : maxVal;
        }
        return maxVal;
    }
};
int main() {
    vector<int> nums{-2, 0, -1};
    Solution sol;
    cout << sol.maxProduct(nums);
    system("pause");
    return 0;
}