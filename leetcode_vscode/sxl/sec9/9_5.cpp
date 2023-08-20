#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> combinations;
        dfs(combination, combinations, candidates, 0, target);
        return combinations;
    }
    void dfs(vector<int>& combination, vector<vector<int>>& combinations, const vector<int>& candidates, int index, int target) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            combination.push_back(candidates[i]);
            dfs(combination, combinations, candidates, i, target - candidates[i]);
            combination.pop_back();
        }
    }
    // 剪枝优化，前提要先对candidates排序！
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int>> combinations;
        dfs(combination, combinations, candidates, 0, target);
        return combinations;
    }
    void dfs(vector<int>& combination, vector<vector<int>>& combinations, const vector<int>& candidates, int index, int target) {
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }
            combination.push_back(candidates[i]);
            dfs(combination, combinations, candidates, i, target - candidates[i]);
            combination.pop_back();
        }
    }
};
int main() {

    system("pause");
    return 0;
}