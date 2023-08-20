#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    // �ٷ�����˼·�����Ż���ֻ����һ��ͬʱȷ��ÿһ�����ӵ����ұ߽�
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                right[stk.top()] = i; // ��ջʱ��ȷ��ջ��Ԫ�ص��ұ߽磬�������ջ���ܷǿգ����ǵ��ұ߽����n�����ǲ������ұ߽�ĳ�ʼֵ���趨Ϊn
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top(); // -1���ڱ�
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