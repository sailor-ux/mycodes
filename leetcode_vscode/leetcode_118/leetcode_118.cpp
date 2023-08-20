#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for (int i = 1; i < numRows; i++) {
            res.push_back({1});
            for (int j = 0; j < res[i - 1].size() - 1; j++) {
                res.back().push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }
            res.back().push_back({1});
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> res = sol.generate(5);
    for (vector<int> vec : res) {
        for (int x : vec) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}