#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    // ˫ָ��
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
    // ����˫ָ��Ľ�
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
    // ��ѽⷨ������ջ���ϸ񵥵��ݼ�ջ
    int trap(vector<int>& height) {
        stack<int> stk;
        int n = height.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || height[stk.top()] > height[i]) { // ���п��ޣ�
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
    // ��ѽⷨ������ջ�����ϸ񵥵��ݼ�ջ
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
    // height[mid]���۵ײ��ĸ߶ȣ�height[stk.top()]������ߵĸ߶ȣ�height[i]�����ұߵĸ߶�
};
int main() {

    system("pause");
    return 0;
}