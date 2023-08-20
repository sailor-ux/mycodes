#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + (right - left) / 2; // 注意(l+r)/2的写法不对！
            if (countNum(matrix, n, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool countNum(const vector<vector<int>>& matrix, const int& n, const int& k, int mid) {
        int i = n - 1, j = 0, sum = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                sum += (i + 1);
                j++;
            } else {
                i--;
            }
        }
        return sum >= k;
    }
};
int main() {
    vector<vector<int>> matrix{{-5, -4}, {-5, -4}};
    Solution sol;
    cout << sol.kthSmallest(matrix, 2);
    system("pause");
    return 0;
}