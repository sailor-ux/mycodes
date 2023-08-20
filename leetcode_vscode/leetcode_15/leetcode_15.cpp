#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 排序+双指针
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] == 0) {
                    ans.push_back({nums[l], nums[r], nums[i]});
                    do {
                        r--; // 一直到下一个不同的数
                    } while (l < r && nums[r] == nums[r + 1]);
                    do {
                        l++; // 一直到下一个不同的数
                    } while (l < r && nums[l] == nums[l - 1]);
                } else if (nums[l] + nums[r] + nums[i] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums{0, 0, 0};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);
    for (auto vec : ans) {
        for (auto x : vec) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}