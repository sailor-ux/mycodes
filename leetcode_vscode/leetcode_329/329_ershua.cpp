#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int m, n;
    vector<vector<int>> dirs;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        this->m = matrix.size(), this->n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLen = max(maxLen, dfs(matrix, memo, i, j));
            }
        }
        return maxLen;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int x, int y) {
        if (memo[x][y] != 0) {
            return memo[x][y];
        }
        int maxLen = 1; // ��ֵӦ��Ϊ1
        // ����forѭ��֮ǰҪ��·���߹�������matrix[x][y]���б�ǣ���ֹ����·����������forѭ������֮���ٻָ�����
        // ����·�����Ҫ�������������������ֵ������ڵ�ǰ�����ֵ����ʵ������������ֵһ��С�ڵ�ǰ�����ֵ
        // ����˵����·����������������������������Ҫ���б�ǣ�����
        // ·�������������Ѿ��߹�����������·���߹�������·���ϵ�����������б�ǣ���
        // ·���߹�������������ߣ��������ѭ��������Ҳ��������ĿҪ��
        for (int i = 0; i < 4; i++) {
            int dx = x + dirs[i][0], dy = y + dirs[i][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && matrix[dx][dy] > matrix[x][y]) {
                maxLen = max(maxLen, dfs(matrix, memo, dx, dy) + 1);
            }
        }
        memo[x][y] = maxLen;
        return maxLen;
    }
};
int main() {

    system("pause");
    return 0;
}