#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        int top = 0, bot = m - 1, left = 0, right = n - 1;
        while (top <= bot && left <= right) {
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            if (top > bot) {
                return res;
            }
            for (int i = top; i <= bot; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (left > right) {
                return res;
            }
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bot][i]);
            }
            bot--;
            if (top > bot) {
                return res;
            }
            for (int i = bot; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
            if (left > right) {
                return res;
            }
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}