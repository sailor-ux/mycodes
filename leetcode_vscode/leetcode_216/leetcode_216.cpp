#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        vector<vector<int>> combinations;
        dfs(combination, combinations, k, n);
        return combinations;
    }
    void dfs(vector<int>& combination, vector<vector<int>>& combinations, int k, int n) {
        if (n == 0) {
            if (k == 0) {
                combinations.push_back(combination);
            }
            return;
        }
        for (int num = combination.empty() ? 1 : combination.back() + 1; num < 10 && num <= n; num++) {
            combination.push_back(num);
            dfs(combination, combinations, k - 1, n - num);
            combination.pop_back();
        }
    }
};
int main() {
    Solution sol;
    vector<vector<int>> combinations = sol.combinationSum3(3, 9);
    for (const vector<int>& combination : combinations) {
        for (const int& num : combination) {
            cout << num << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}