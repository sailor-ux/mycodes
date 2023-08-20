#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    // 双指针
    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        for (int i = 1; i <= n - 2; i++) {
            int leftMaxHeight = height[i];
            for (int j = i - 1; j >= 0; j--) {
                leftMaxHeight = max(leftMaxHeight, height[j]);
            }
            int rightMaxHeight = height[i];
            for (int j = i + 1; j < n; j++) {
                rightMaxHeight = max(rightMaxHeight, height[j]);
            }
            sum += (min(leftMaxHeight, rightMaxHeight) - height[i]);
        }
        return sum;
    }
    // 基于双指针改进
    // leftMax[i] = max{height[0:i]}, leftMax[i] = max(leftMax[i-1], height[i])
    int trap(vector<int>& height) {
        int n = height.size(), sum = 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        for (int i = 1; i < n - 1; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
    // 最佳解法：单调栈，严格单调递减栈
    int trap(vector<int>& height) {
        stack<int> stk;
        int n = height.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || height[stk.top()] > height[i]) { // 可有可无！
                stk.push(i);
                continue;
            }
            while (!stk.empty() && height[stk.top()] <= height[i]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    sum += (min(height[stk.top()], height[i]) - height[mid]) * (i - stk.top() - 1);
                }
            }
            stk.push(i);
        }
        return sum;
    }
    // 最佳解法：单调栈，不严格单调递减栈
    int trap(vector<int>& height) {
        stack<int> stk;
        int n = height.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            /* if (stk.empty() || height[stk.top()] > height[i]) {
                stk.push(i);
                continue;
            } */
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    sum += (min(height[stk.top()], height[i]) - height[mid]) * (i - stk.top() - 1); // h*w
                }
            }
            stk.push(i);
        }
        return sum;
    }
    // height[mid]凹槽底部的高度，height[stk.top()]凹槽左边的高度，height[i]凹槽右边的高度
};
int main() {

    system("pause");
    return 0;
}