#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // ��������˼�룬���Ϳռ临�Ӷȣ�dp: O(n*n) ----> O(n), dp�ɶ�ά�Ľ���һά�ģ�����һ��
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[j] = min(f[j], f[j + 1]) + triangle[i][j];
            }
        }
        return f[0];
    }
};
int main() {
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    cout << sol.minimumTotal(triangle);
    system("pause");
    return 0;
}