#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    // 从二叉树的层序遍历那题开始引入bfs，bfs用到队列queue，思路都很相像，有个大致的模板
    void solve(vector<vector<char>>& board) {
        vector<int> dx{1, -1, 0, 0}; // 上下左右
        vector<int> dy{0, 0, -1, 1};
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
            }
            if (board[m - 1][i] == 'O') {
                q.push({m - 1, i});
            }
        }
        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
            }
            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
            }
        }
        while (!q.empty()) {
            int qLen = q.size();
            for (int i = 1; i <= qLen; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                board[row][col] = 'A';
                for (int index = 0; index < 4; index++) {
                    if (row + dx[index] < 0 || row + dx[index] >= m || col + dy[index] < 0 || col + dy[index] >= n || board[row + dx[index]][col + dy[index]] != 'O') {
                        continue;
                    }
                    q.push({row + dx[index], col + dy[index]});
                }
            }
        }
        for (vector<char>& row : board) {
            for (char& ch : row) {
                if (ch == 'A') {
                    ch = 'O';
                } else if (ch == 'O') {
                    ch = 'X';
                }
            }
        }
    }
};
int main() {
    vector<vector<char>> board{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};
    Solution sol;
    sol.solve(board);
    for (const vector<char>& row : board) {
        for (const char& ch : row) {
            cout << ch << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}