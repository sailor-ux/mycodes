#include <iostream>
#include <vector>
using namespace std;
// 桶排序线性时间复杂度O(n)
class Solution {
public:
    // 定义桶
    struct bucket {
        int minVal;
        int maxVal;
        bool isEmpty;
        bucket() : minVal(INT_MAX), maxVal(INT_MIN), isEmpty(true) {}
    };
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int maxVal = nums[0], minVal = maxVal;
        for (auto& num : nums) {
            maxVal = max(maxVal, num);
            minVal = min(minVal, num);
        }
        int d = max(1, (maxVal - minVal) / (n - 1)); // 桶的长度, 小心为0, 0不能做除数！
        int size = (maxVal - minVal) / d + 1;        // 桶的数量
        vector<bucket> buckets(size);                // 装着所有桶的容器
        for (auto& num : nums) {
            int idx = (num - minVal) / d;
            buckets[idx].isEmpty = false;
            buckets[idx].minVal = min(buckets[idx].minVal, num);
            buckets[idx].maxVal = max(buckets[idx].maxVal, num);
        }
        int res = 0;
        for (int i = 0, lastMax = minVal; i < size; i++) {
            if (!buckets[i].isEmpty) {
                res = max(res, buckets[i].minVal - lastMax);
                lastMax = buckets[i].maxVal;
            }
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}