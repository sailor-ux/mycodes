#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    // 官方题解的思路，比_1的思路更好！！！
    // 单调栈，严格单调递增！！！
    // 从左至右，遍历一遍确定左边界
    // 从右至左，遍历一遍确定右边界，两个遍历过程的思路完全一样！
    // 求每一个柱形高度heights[i]，所能勾勒出的面积最大的矩形的面积
    // heights[i] 对应 leftBorder[i], rightBorder[i]
    // heights[i]对应的面积最大的矩形的面积  = (rightBorder[i] - leftBorder[i] - 1) * heights[i]
    // 左右边界leftBorder和rightBorder的确定，都需要一个单调栈(严格单调递增)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top(); // -1是哨兵
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top(); // n是哨兵
            stk.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(heights[i] * (right[i] - left[i] - 1), maxArea);
        }
        return maxArea;
    }
};
int main() {
    vector<int> heights{6, 7, 5, 2, 4, 5, 9, 3};
    Solution sol;
    cout << sol.largestRectangleArea(heights);
    system("pause");
    return 0;
}