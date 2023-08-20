#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            int low, high;
            if (matrix[row][col] > target) {
                low = 0, high = col - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (matrix[row][mid] == target) {
                        return true;
                    } else if (matrix[row][mid] < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            } else {
                low = row + 1, high = m - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (matrix[mid][col] == target) {
                        return true;
                    } else if (matrix[mid][col] < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            row++;
            col--;
        }
        return false;
    }
};
int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    Solution sol;
    cout << sol.searchMatrix(matrix, 20);
    system("pause");
    return 0;
}