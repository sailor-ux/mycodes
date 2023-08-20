#include <iostream>
#include <vector>
using namespace std;
class Solution01 {
public:
    int m, n;
    vector<vector<int>> dirs;
    bool exist(vector<vector<char>>& board, string word) {
        this->dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        this->m = board.size(), this->n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = 0;
                if (dfs(board, word, len, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, const string& word, int& len, int i, int j) {
        if (board[i][j] == word[len]) {
            len++;
            if (len == word.length()) {
                return true;
            }
            char ch = board[i][j];
            board[i][j] = '#';
            for (const vector<int>& dir : dirs) {
                int newI = i + dir[0], newJ = j + dir[1];
                if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && board[newI][newJ] != '#') {
                    if (dfs(board, word, len, newI, newJ)) {
                        return true;
                    }
                }
            }
            board[i][j] = ch; // 回溯
            len--;            // 回溯
            return false;
        } else {
            return false;
        }
    }
};
class Solution02 {
public:
    int m, n;
    vector<vector<int>> dirs;
    bool exist(vector<vector<char>>& board, string word) {
        this->dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        this->m = board.size(), this->n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = 0;
                if (dfs(board, word, len, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, const string& word, int& len, int i, int j) {
        if (board[i][j] != word[len]) {
            return false;
        }
        if (++len == word.length()) {
            return true;
        }
        char ch = board[i][j];
        board[i][j] = '#';
        for (const vector<int>& dir : dirs) {
            int newI = i + dir[0], newJ = j + dir[1];
            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && board[newI][newJ] != '#') {
                if (dfs(board, word, len, newI, newJ)) {
                    return true;
                }
            }
        }
        board[i][j] = ch; // 回溯，board[i][j]恢复成原来的字符，相当于它又从路径当中被剔除出去，自然要len--
        len--;            // 回溯
        return false;
    }
};
int main() {
    vector<vector<char>> board{{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
    Solution02 sol;
    cout << sol.exist(board, "AAB");
    system("pause");
    return 0;
}