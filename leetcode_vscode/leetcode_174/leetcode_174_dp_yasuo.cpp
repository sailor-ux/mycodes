#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //¹ö¶¯Êý×éÑ¹Ëõ
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> f(n + 1, INT_MAX);
        f[n] = f[n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i == m - 1 && j == n) {
                    continue;
                }
                if (j == n) {
                    f[j] = INT_MAX;
                    continue;
                }
                f[j] = max(min(f[j], f[j + 1]) - dungeon[i][j], 1);
            }
        }
        return f[0];
    }
};
int main() {
    vector<vector<int>> dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    Solution sol;
    cout << sol.calculateMinimumHP(dungeon);
    system("pause");
    return 0;
}