#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // �����ⷨ����ʱ
    // ÿһ�����ӣ���������������������ĸ߶�С����������
    // ������һ���߶�С���������ӣ����Ҳ��һ���߶�С����������
    // �ؼ��ʣ���һ��������������������õ���ջ�Ż������ⷨ��ʱ�临�Ӷȣ�����
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