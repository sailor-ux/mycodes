#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    const int ADDITION = -1;
    const int SUBTRACTION = -2;
    const int MULTIPLICATION = -3;
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ops;
        for (int i = 0; i < expression.length();) {
            if (isdigit(expression[i])) {
                int num = 0;
                while (i < expression.length() && isdigit(expression[i])) {
                    num = 10 * num + expression[i++] - '0';
                }
                ops.push_back(num);
            } else {
                if (expression[i] == '+') {
                    ops.push_back(ADDITION);
                } else if (expression[i] == '-') {
                    ops.push_back(SUBTRACTION);
                } else {
                    ops.push_back(MULTIPLICATION);
                }
                i++;
            }
        }
        vector<vector<vector<int>>> dp(ops.size(), vector<vector<int>>(ops.size()));
        return dfs(dp, 0, ops.size() - 1, ops);
    }
    vector<int> dfs(vector<vector<vector<int>>>& dp, int l, int r, const vector<int>& ops) {
        if (!dp[l][r].empty()) {
            return dp[l][r];
        }
        if (l == r) {
            return dp[l][r] = {ops[l]};
        }
        for (int idx = l + 1; idx < r; idx += 2) {
            vector<int> left = dfs(dp, l, idx - 1, ops);
            vector<int> right = dfs(dp, idx + 1, r, ops);
            for (const int& x : left) {
                for (const int& y : right) {
                    if (ops[idx] == ADDITION) {
                        dp[l][r].push_back(x + y);
                    } else if (ops[idx] == SUBTRACTION) {
                        dp[l][r].push_back(x - y);
                    } else {
                        dp[l][r].push_back(x * y);
                    }
                }
            }
        }
        return dp[l][r];
    }
};
int main() {
    Solution sol;
    vector<int> res = sol.diffWaysToCompute("2-1-1");
    for (const int& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}