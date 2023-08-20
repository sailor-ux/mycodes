#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // vector<vector<int>> combinationSum4(vector<int>& nums, int target) {
    //     sort(nums.begin(), nums.end());
    //     vector<int> combination;
    //     vector<vector<int>> combinations;
    //     dfs(combination, combinations, nums, target);
    //     return combinations;
    // }
    // void dfs(vector<int>& combination, vector<vector<int>>& combinations, const vector<int>& nums, int target) {
    //     if (target == 0) {
    //         combinations.push_back(combination);
    //         return;
    //     }
    //     for (const int& num : nums) {
    //         if (num > target) {
    //             return;
    //         }
    //         combination.push_back(num);
    //         dfs(combination, combinations, nums, target - num);
    //         combination.pop_back();
    //     }
    // }

    // int combinationSum4(vector<int>& nums, int target) {
    //     sort(nums.begin(), nums.end());
    //     int count = 0;
    //     dfs(count, nums, target);
    //     return count;
    // }
    // void dfs(int& count, const vector<int>& nums, int target) {
    //     if (target == 0) {
    //         count++;
    //         return;
    //     }
    //     for (const int& num : nums) {
    //         if (num > target) {
    //             return;
    //         }
    //         dfs(count, nums, target - num);
    //     }
    // }

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> memo(target + 1, -1);
        return dfs(nums, target, memo);
    }
    int dfs(const vector<int>& nums, int target, vector<int>& memo) { // void dfs => int dfs
        if (memo[target] != -1) {
            return memo[target];
        }
        if (target == 0) {
            memo[0] = 1;
            return 1;
        }
        int count = 0;
        for (const int& num : nums) {
            if (num > target) {
                break;
            }
            count += dfs(nums, target - num, memo);
        }
        memo[target] = count;
        return count;
    }

    // int combinationSum4(vector<int>& nums, int target) {
    //     sort(nums.begin(), nums.end());
    //     vector<int> memo(target, -1); // 强行长度为target
    //     return dfs(nums, target, memo);
    // }
    // int dfs(const vector<int>& nums, int target, vector<int>& memo) {
    //     if (target == 0) {
    //         return 1;
    //     }
    //     if (memo[target - 1] != -1) {
    //         return memo[target - 1];
    //     }
    //     int count = 0;
    //     for (const int& num : nums) {
    //         if (num > target) { // 配合sort使用，加一点点速
    //             break;
    //         }
    //         count += dfs(nums, target - num, memo);
    //     }
    //     memo[target - 1] = count;
    //     return count;
    // }
};
int main() {
    Solution sol;
    vector<int> nums{3, 2, 1};
    // vector<vector<int>> combinations = sol.combinationSum4(nums, 4);
    // for (const vector<int>& combination : combinations) {
    //     for (const int& x : combination) {
    //         cout << x << ' ';
    //     }
    //     cout << "\n";
    // }

    cout << sol.combinationSum4(nums, 4);
    system("pause");
    return 0;
}