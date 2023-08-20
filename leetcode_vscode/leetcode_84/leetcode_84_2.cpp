#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    // �ٷ�����˼·����_1��˼·���ã�����
    // ����ջ���ϸ񵥵�����������
    // �������ң�����һ��ȷ����߽�
    // �������󣬱���һ��ȷ���ұ߽磬�����������̵�˼·��ȫһ����
    // ��ÿһ�����θ߶�heights[i]�����ܹ��ճ���������ľ��ε����
    // heights[i] ��Ӧ leftBorder[i], rightBorder[i]
    // heights[i]��Ӧ��������ľ��ε����  = (rightBorder[i] - leftBorder[i] - 1) * heights[i]
    // ���ұ߽�leftBorder��rightBorder��ȷ��������Ҫһ������ջ(�ϸ񵥵�����)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top(); // -1���ڱ�
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top(); // n���ڱ�
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