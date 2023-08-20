#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/* ����ͼ��BFS�������BFS����ԴBFS��ÿһ��0����Դ�㣬�����ǳ�����4���������BFS���������е�Դ�㣨0����һ������У�
queue
������еĲ���������С�����������ѭ��
���������ǰ��Ҫ���Ϊ����������С��ѷ��ʹ� */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] = -1;
                } else {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
            int x = cell.first, y = cell.second;
            for (int i = 0; i < 4; i++) {
                int newX = x + dirs[i][0], newY = y + dirs[i][1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && mat[newX][newY] == -1) {
                    mat[newX][newY] = mat[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
        return mat;
    }
};
int main() {

    system("pause");
    return 0;
}