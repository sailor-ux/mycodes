#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int>> combinations;
        vector<bool> used(candidates.size(), false);
        dfs(combination, combinations, candidates, used, 0, target);
        return combinations;
    }
    void dfs(vector<int>& combination, vector<vector<int>>& combinations, const vector<int>& candidates, vector<bool>& used, int index, int target) {
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size() && candidates[i] <= target; i++) { // ��֦�Ż�
            if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1]) {       // �����ظ�������ȥ��
                continue;
            }
            combination.push_back(candidates[i]);
            used[i] = true;
            dfs(combination, combinations, candidates, used, i + 1, target - candidates[i]);
            combination.pop_back();
            used[i] = false;
        }
    }
    // ����usedʵ������ȥ�أ�
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int>> combinations;
        vector<bool> used(candidates.size(), false);
        dfs(combination, combinations, candidates, 0, target);
        return combinations;
    }
    void dfs(vector<int>& combination, vector<vector<int>>& combinations, const vector<int>& candidates, int index, int target) {
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size() && candidates[i] <= target; i++) { // ��֦�Ż�
            if (i > index && candidates[i] == candidates[i - 1]) {                   // �����ظ�������ȥ��
                continue;
            }
            combination.push_back(candidates[i]);
            dfs(combination, combinations, candidates, i + 1, target - candidates[i]);
            combination.pop_back();
        }
    }
};
int main() {

    system("pause");
    return 0;
}