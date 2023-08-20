#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    // ����ö�٣���ÿһ�����ӵĸ߶�Ϊ�ߣ��������ε���������������ε������ѡ���ֵ
    int largestRectangleArea(vector<int>& heights) {
        int maxVal = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            int left = i - 1, right = i + 1;
            while (left >= 0 && heights[left] >= heights[i]) {
                left--;
            }
            while (right < n && heights[right] >= heights[i]) {
                right++;
            }
            maxVal = max(maxVal, heights[i] * (right - left - 1));
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