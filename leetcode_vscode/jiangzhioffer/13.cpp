#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return movingCountCore(visited, m, n, k, 0, 0);
    }
    int movingCountCore(vector<vector<bool>>& visited, const int& m, const int& n, const int& k, int i, int j) {
        if (!check(visited, m, n, k, i, j)) {
            return 0;
        }
        visited[i][j] = true;
        return 1 + movingCountCore(visited, m, n, k, i - 1, j) + movingCountCore(visited, m, n, k, i + 1, j) + movingCountCore(visited, m, n, k, i, j - 1) + movingCountCore(visited, m, n, k, i, j + 1);
    }
    bool check(const vector<vector<bool>>& visited, const int& m, const int& n, const int& k, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || (getDigitSum(i) + getDigitSum(j) > k)) {
            return false;
        }
        return true;
    }
    int getDigitSum(int number) {
        int sum = 0;
        while (number) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};
int main() {

    system("pause");
    return 0;
}