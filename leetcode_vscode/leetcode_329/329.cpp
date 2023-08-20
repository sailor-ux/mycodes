#include <iostream>
#include <vector>
using namespace std;
class Solution01 { // �����������еĵ���·��(�ߵ�ͷ����������ȥ��)
public:
    vector<vector<int>> dirs;
    int m;
    int n;
    vector<int> path;
    vector<vector<int>> pathes;
    vector<vector<int>> longestIncreasingPath(vector<vector<int>>& matrix) {
        dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        m = matrix.size(), n = matrix[0].size();
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                path.push_back(matrix[x][y]);
                dfs(matrix, x, y);
                path.pop_back();
            }
        }
        return pathes;
    }
    void dfs(vector<vector<int>>& matrix, int x, int y) {
        int temp = matrix[x][y];
        matrix[x][y] = -1;
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > temp) {
                flag = false;
                path.push_back(matrix[nx][ny]);
                dfs(matrix, nx, ny);
                path.pop_back();
            }
        }
        if (flag) {
            pathes.push_back(path);
        }
        matrix[x][y] = temp;
    }
};
class Solution02 { // ����������ĵ���·��
public:
    vector<vector<int>> dirs;
    int m;
    int n;
    vector<int> path;
    vector<int> maxPath;
    vector<int> longestIncreasingPath(vector<vector<int>>& matrix) {
        dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        m = matrix.size(), n = matrix[0].size();
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                path.push_back(matrix[x][y]);
                dfs(matrix, x, y);
                path.pop_back();
            }
        }
        return maxPath;
    }
    void dfs(vector<vector<int>>& matrix, int x, int y) {
        int temp = matrix[x][y];
        matrix[x][y] = -1;
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > temp) {
                flag = false;
                path.push_back(matrix[nx][ny]);
                dfs(matrix, nx, ny);
                path.pop_back();
            }
        }
        if (flag) {
            if (path.size() > maxPath.size()) {
                maxPath = path;
            }
            // pathes.push_back(path);//path�Ѿ���һ���ߵ�ͷ�˵ĵ���·��
        }
        matrix[x][y] = temp;
    }
};
class Solution03 { // �����·���ĳ���
public:
    vector<vector<int>> dirs;
    int m;
    int n;
    vector<int> path;
    int maxLen;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        m = matrix.size(), n = matrix[0].size();
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                path.push_back(matrix[x][y]);
                dfs(matrix, x, y);
                path.pop_back();
            }
        }
        return maxLen;
    }
    void dfs(vector<vector<int>>& matrix, int x, int y) {
        int temp = matrix[x][y];
        matrix[x][y] = -1;
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > temp) {
                flag = false;
                path.push_back(matrix[nx][ny]);
                dfs(matrix, nx, ny);
                path.pop_back();
            }
        }
        if (flag) {
            int size = path.size();
            maxLen = max(maxLen, size);
            // pathes.push_back(path);//path�Ѿ���һ���ߵ�ͷ�˵ĵ���·��
        }
        matrix[x][y] = temp;
    }
};
class Solution04 { // �����·���ĳ��� dfs + ���仯
public:
    vector<vector<int>> dirs;
    int m;
    int n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int maxLen = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                maxLen = max(maxLen, dfs(matrix, memo, x, y));
            }
        }
        return maxLen;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int x, int y) {
        if (memo[x][y] > 0) {
            return memo[x][y];
        }
        int maxPathLen = 1;
        int temp = matrix[x][y];
        matrix[x][y] = -1; // ʵ����������
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > temp) {
                maxPathLen = max(maxPathLen, dfs(matrix, memo, nx, ny) + 1);
            }
        }
        matrix[x][y] = temp;
        memo[x][y] = maxPathLen;
        return maxPathLen;
    }
};
int main() {
    vector<vector<int>> matrix{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    /* Solution01 sol01;
    vector<vector<int>> pathes = sol01.longestIncreasingPath(matrix);
    for (auto path : pathes) {
        for (auto x : path) {
            cout << x << ' ';
        }
        cout << "\n";
    } */
    /* Solution02 sol02;
    vector<int> maxPath = sol02.longestIncreasingPath(matrix);
    for (auto x : maxPath) {
        cout << x << ' ';
    } */
    Solution04 sol04;
    cout << sol04.longestIncreasingPath(matrix);
    system("pause");
    return 0;
}