#include <iostream>
#include <vector>
using namespace std;
// 自己写的，像是在写业务！！！
class Solution {
public:
    int m, n;
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        vector<int> res;
        bool flag = false;
        vector<int> vec = print(mat, res, flag, 0, 0);
        while (vec[0] != m - 1 || vec[1] != n - 1) {
            if (vec[0] == 0) {
                if (vec[1] + 1 < n) { // 优先往右走
                    vec = print(mat, res, flag, 0, vec[1] + 1);
                } else { // 实在不行往下走
                    vec = print(mat, res, flag, 1, vec[1]);
                }
            } else if (vec[0] == m - 1) {
                vec = print(mat, res, flag, m - 1, vec[1] + 1);
            } else {
                vec = print(mat, res, flag, vec[0] + 1, vec[1]);
            }
        }
        return res;
    }
    vector<int> print(const vector<vector<int>>& mat, vector<int>& res, bool& flag, int i, int j) {
        if (flag) {
            while (i < m && j >= 0) {
                res.push_back(mat[i][j]);
                i++;
                j--;
            }
            flag = false;
            return {i - 1, j + 1};
        }
        while (i >= 0 && j < n) {
            res.push_back(mat[i][j]);
            i--;
            j++;
        }
        flag = true;
        return {i + 1, j - 1};
    }
};
int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution sol;
    vector<int> res = sol.findDiagonalOrder(mat);
    for (auto x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}