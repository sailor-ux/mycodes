#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 1;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int left = 1, right = len;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (d[mid] < nums[i] && nums[i] <= d[mid + 1]) {
                        d[mid + 1] = nums[i];
                        break;
                    } else if (d[mid] >= nums[i]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                if (left == 1 && right == 0) {
                    d[1] = nums[i];
                }
            }
        }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 1;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0; // pos如果仍为初始值0,说明目前数组d的所有元素全部都是>=nums[i],找不到<nums[i]的,nums[i]<=d[1],d[1]更新为nums[i]!
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
int main() {

    system("pause");
    return 0;
}