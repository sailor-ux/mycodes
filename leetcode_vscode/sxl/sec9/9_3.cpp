#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 错误！
    /* vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        vector<vector<int>> combinations;
        vector<bool> used(9, false);
        int sum = 0;
        dfs(combination, combinations, used, sum, n, k);
        return combinations;
    }
    void dfs(vector<int>& combination, vector<vector<int>>& combinations, vector<bool>& used, int& sum, const int& n, const int& k) {
        if (combination.size() == k) {
            if (sum == n) {
                combinations.push_back(combination);
            }
            return;
        }
        for (int num = 1; num <= 9; num++) {
            if (!used[num - 1]) {
                combination.push_back(num);
                used[num - 1] = true;
                sum += num;
                dfs(combination, combinations, used, sum, n, k);
                combination.pop_back();
                used[num - 1] = false;
                sum -= num;
            }
        }
    } */
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        vector<vector<int>> combinations;
        int sum = 0;
        dfs(combination, combinations, 1, sum, n, k);
        return combinations;
    }
    void dfs(vector<int>& combination, vector<vector<int>>& combinations, int start, int& sum, const int& n, const int& k) {
        if (combination.size() == k) {
            if (sum == n) {
                combinations.push_back(combination);
            }
            return;
        }
        if (sum >= n) { // 剪枝优化！
            return;
        }
        for (int num = start; num <= 10 - k + combination.size(); num++) { // 剪枝优化！
            combination.push_back(num);
            sum += num;
            dfs(combination, combinations, num + 1, sum, n, k);
            combination.pop_back();
            sum -= num;
        }
    }
};
int main() {
    Solution sol;
    vector<vector<int>> combinations = sol.combinationSum3(3, 9);
    for (const vector<int>& combination : combinations) {
        for (const int& x : combination) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}