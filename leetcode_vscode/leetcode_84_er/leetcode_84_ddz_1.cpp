#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top(); // 入栈的时候就对左边界赋值
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top(); // 入栈的时候就对右边界赋值
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
    vector<int> heights{6, 7, 5, 2, 4, 5, 9, 3};
    Solution sol;
    cout << sol.largestRectangleArea(heights);
    system("pause");
    return 0;
}