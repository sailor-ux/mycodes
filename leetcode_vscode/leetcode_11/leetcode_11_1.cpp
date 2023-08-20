#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 双指针，时间复杂度O(n)
    // 移动指向柱子的高度更低的那个指针！！
    // 相似题目接雨水
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