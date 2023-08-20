#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    ++heights[j];
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top(); // ��ջ��ʱ��Ͷ���߽縳ֵ
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top(); // ��ջ��ʱ��Ͷ��ұ߽縳ֵ
            stk.push(i);
        }
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            maxVal = max(maxVal, heights[i] * (right[i] - left[i] - 1));
        }
        return maxVal;
    }
};
int main() {

    system("pause");
    return 0;
}