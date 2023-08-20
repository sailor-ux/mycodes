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
            } else if (target < matrix[row][col]) {
                int low = 0, high = col - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (matrix[row][mid] == target) {
                        return true;
                    } else if (target < matrix[row][mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            } else {
                int low = row + 1, high = m - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (matrix[mid][col] == target) {
                        return true;
                    } else if (target < matrix[mid][col]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
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

    system("pause");
    return 0;
}