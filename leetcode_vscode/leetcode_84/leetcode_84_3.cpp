#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    // 官方题解的思路，再优化，只遍历一遍同时确定每一个柱子的左右边界
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                right[stk.top()] = i; // 出栈时，确定栈顶元素的右边界，但是最后栈可能非空，他们的右边界就是n，于是不妨把右边界的初始值都设定为n
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top(); // -1是哨兵
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