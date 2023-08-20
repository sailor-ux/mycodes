#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        res.push_back({1});
        for (int i = 1; i < rowIndex + 1; i++) {
            res.push_back({1});
            for (int j = 0; j < res[i - 1].size() - 1; j++) {
                res.back().push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }
            res.back().push_back({1});
        }
        return res[rowIndex];
    }
};
int main() {
    Solution sol;
    vector<int> res = sol.getRow(4);
    for (int x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}