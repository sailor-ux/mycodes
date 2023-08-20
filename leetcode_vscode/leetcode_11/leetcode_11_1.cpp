#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ˫ָ�룬ʱ�临�Ӷ�O(n)
    // �ƶ�ָ�����ӵĸ߶ȸ��͵��Ǹ�ָ�룡��
    // ������Ŀ����ˮ
    int maxArea(vector<int>& height) {
        int n = height.size(), maxCapacity = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            maxCapacity = max(maxCapacity, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxCapacity;
    }
};
int main() {

    system("pause");
    return 0;
}