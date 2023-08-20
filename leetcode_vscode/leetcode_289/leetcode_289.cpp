#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> coordinates;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                int livingCellNum = 0;
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (row + i >= 0 && row + i < board.size() && col + j >= 0 && col + j < board[0].size() && board[row + i][col + j] == 1) {
                            livingCellNum++;
                        }
                    }
                }
                if ((board[row][col] == 1 && (livingCellNum < 3 || livingCellNum > 4)) || (board[row][col] == 0 && livingCellNum == 3)) {
                    coordinates.push_back({row, col});
                }
            }
        }
        for (const pair<int, int>& coordinate : coordinates) {
            board[coordinate.first][coordinate.second] = !board[coordinate.first][coordinate.second];
        }
    }
};
int main() {
    vector<vector<int>> board{
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}};
    Solution sol;
    sol.gameOfLife(board);
    for (const auto& vec : board) {
        for (const int& x : vec) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}