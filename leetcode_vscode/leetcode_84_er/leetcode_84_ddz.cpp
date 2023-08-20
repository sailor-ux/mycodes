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
                int idx = stk.top(); // 出栈的时候对左边界赋值
                stk.pop();
                left[idx] = stk.empty() ? -1 : stk.top();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            left[idx] = stk.empty() ? -1 : stk.top();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                int idx = stk.top(); // 出栈的时候对右边界赋值
                stk.pop();
                right[idx] = stk.empty() ? n : stk.top();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            right[idx] = stk.empty() ? n : stk.top();
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