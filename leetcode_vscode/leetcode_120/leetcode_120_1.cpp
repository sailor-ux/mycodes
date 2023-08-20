#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // �ݹ鷨������������ʱ�����ڴ������ظ����㣡����
    // �Զ����µĵݹ� ���������⣬ԭ���� ----> ��С������
    int minimumTotal(vector<vector<int>>& triangle) {
        return dfs(triangle, 0, 0);
    }
    int dfs(const vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size()) {
            return 0;
        }
        return min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
    }
};
int main() {
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    cout << sol.minimumTotal(triangle);
    system("pause");
    return 0;
}