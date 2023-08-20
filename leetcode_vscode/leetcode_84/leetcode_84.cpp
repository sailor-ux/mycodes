#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // 暴力解法，超时
    // 每一个柱子，找它左右两侧离它最近的高度小于它的柱子
    // 找左侧第一个高度小于它的柱子，找右侧第一个高度小于它的柱子
    // 关键词：第一个，类似这样的问题采用单调栈优化暴力解法的时间复杂度！！！
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = heights[0];
        for (int i = 0; i < heights.size(); i++) {
            int l = i;
            for (; l >= 0; l--) {
                if (heights[l] < heights[i]) {
                    break;
                }
            }
            int r = i;
            for (; r < heights.size(); r++) {
                if (heights[r] < heights[i]) {
                    break;
                }
            }
            if ((heights[i] * (r - l - 1)) > maxArea) {
                maxArea = heights[i] * (r - l - 1);
            }
        }
        return maxArea;
    }
};
int main() {
    vector<int> heights{2, 1, 5, 6, 2, 3};
    Solution sol;
    cout << sol.largestRectangleArea(heights);
    system("pause");
    return 0;
}