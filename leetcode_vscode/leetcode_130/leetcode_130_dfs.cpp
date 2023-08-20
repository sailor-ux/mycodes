#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void solve(vector<vector<char>>& board) {
        vector<int> dx{1, -1, 0, 0}; // …œœ¬◊Û”“
        vector<int> dy{0, 0, -1, 1};
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, 0, i, m, n, dx, dy);
            dfs(board, m - 1, i, m, n, dx, dy);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, i, 0, m, n, dx, dy);
            dfs(board, i, n - 1, m, n, dx, dy);
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
    void dfs(vector<vector<char>>& board, int i, int j, const int& m, const int& n, const vector<int>& dx, const vector<int>& dy) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'A';
        for (int index = 0; index < 4; index++) {
            dfs(board, i + dx[index], j + dy[index], m, n, dx, dy);
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