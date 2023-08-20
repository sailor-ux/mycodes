#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 盛水最多的容器一定以某一个柱子的高度为高，所以枚举每一根柱子的高度
    // 寻找左边(右边)最后(最远)一个大于等于的
    // 单调栈的话，应该是找第一个(最近)，所以不符合单调栈！
    // 时间复杂度O(n*n)，效率太低！改用双指针！！！
    int maxArea(vector<int>& height) {
        int n = height.size(), maxCapacity = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            while (height[l] < height[i]) {
                l++;
            }
            while (height[r] < height[i]) {
                r--;
            }
            maxCapacity = max(maxCapacity, (i - l) * height[i]);
            maxCapacity = max(maxCapacity, (r - i) * height[i]);
        }
        return maxCapacity;
    }
};
int main() {

    system("pause");
    return 0;
}