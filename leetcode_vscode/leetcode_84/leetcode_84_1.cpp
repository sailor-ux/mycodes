#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    // ���Բ�����
    // ��ÿһ�����θ߶�heights[i]�����ܹ��ճ���������ľ��ε����
    // heights[i] ��Ӧ leftBorder[i], rightBorder[i]
    // heights[i]��Ӧ��������ľ��ε����  = (rightBorder[i] - leftBorder[i] - 1) * heights[i]
    // ���ұ߽�leftBorder��rightBorder��ȷ��������Ҫһ������ջ(��������)
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        vector<int> rightBorder(heights.size());
        int i = 0;
        for (; i < heights.size(); i++) {
            while (1) {
                if (stk.empty() || heights[i] >= heights[stk.top()]) {
                    stk.push(i);
                    break;
                } else {
                    rightBorder[stk.top()] = i;
                    stk.pop();
                }
            }
        }
        while (!stk.empty()) {
            rightBorder[stk.top()] = i;
            stk.pop();
        }
        vector<int> leftBorder(heights.size());
        int j = heights.size() - 1;
        for (; j >= 0; j--) {
            while (1) {
                if (stk.empty() || heights[j] >= heights[stk.top()]) {
                    stk.push(j);
                    break;
                } else {
                    leftBorder[stk.top()] = j;
                    stk.pop();
                }
            }
        }
        while (!stk.empty()) {
            leftBorder[stk.top()] = j;
            stk.pop();
        }
        int maxArea = (rightBorder[0] - leftBorder[0] - 1) * heights[0];
        for (int i = 1; i < heights.size(); i++) {
            maxArea = max(maxArea, (rightBorder[i] - leftBorder[i] - 1) * heights[i]);
        }
        return maxArea;
    }
    vector<int> getRightBorder(vector<int>& heights) {
        stack<int> stk;
        vector<int> rightBorder(heights.size());
        int i = 0;
        for (; i < heights.size(); i++) {
            while (1) {
                if (stk.empty() || heights[i] >= heights[stk.top()]) {
                    stk.push(i);
                    break;
                } else {
                    rightBorder[stk.top()] = i;
                    stk.pop();
                }
            }
        }
        while (!stk.empty()) {
            rightBorder[stk.top()] = i;
            stk.pop();
        }
        return rightBorder;
    }
};
int main() {
    vector<int> heights{1};
    Solution sol;
    // vector<int> rightBorder = sol.getRightBorder(heights);
    // for (int x : rightBorder) {
    //     cout << x << ' ';
    // }
    cout << sol.largestRectangleArea(heights);
    system("pause");
    return 0;
}