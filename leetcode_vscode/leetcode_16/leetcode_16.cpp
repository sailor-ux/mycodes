#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 15题三数之和的改版！！！
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minDistance = INT_MAX, res;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    if (sum - target < minDistance) {
                        minDistance = (sum - target);
                        res = sum;
                    }
                    r--;
                } else {
                    if (target - sum < minDistance) {
                        minDistance = (target - sum);
                        res = sum;
                    }
                    l++;
                }
            }
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}