#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> candidates;
        vector<int> combination;
        for (int num = 1; num * num <= n; num++) {
            candidates.push_back(num * num);
        }
        int minNum = n; // minNum的初值 >= n！！！
        dfs(candidates, combination, n, minNum);
        return minNum;
    }
    void dfs(const vector<int>& candidates, vector<int>& combination, int n, int& minNum) {
        if (n == 0) {
            minNum = min(minNum, (int)combination.size());
            return;
        }
        if (combination.size() == minNum) { // 加快一点！！！
            return;
        }
        for (int i = candidates.size() - 1; i >= 0; i--) {
            if (candidates[i] <= n) {
                combination.push_back(candidates[i]);
                dfs(candidates, combination, n - candidates[i], minNum);
                combination.pop_back();
            }
        }
    }
};
int main() {
    Solution sol;
    cout << sol.numSquares(49);
    system("pause");
    return 0;
}