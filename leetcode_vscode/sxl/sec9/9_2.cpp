#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        vector<vector<int>> combinations;
        dfs(combination, combinations, 1, n, k);
        return combinations;
    }
    void dfs(vector<int>& combination, vector<vector<int>>& combinations, int start, const int& n, const int& k) {
        if (combination.size() == k) {
            combinations.push_back(combination);
            return;
        }
        for (int num = start; num <= n + 1 - k + combination.size(); num++) {
            combination.push_back(num);
            dfs(combination, combinations, num + 1, n, k);
            combination.pop_back();
        }
    }
};
int main() {

    system("pause");
    return 0;
}