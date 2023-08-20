#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    // 时间复杂度为 O(N)，空间复杂度为 O(N)
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end()); // 用vector<int>初始化unordered_set<int>, 空间复杂度O(n)
        int num = 1;
        while (1) {
            if (st.find(num++) == st.end()) {
                return num - 1;
            }
        }
        return -1;
    }
    // 官方题解方法1：时间复杂度为 O(N)，空间复杂度为 O(1)
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1; // 不能转换成[1, n]中的数
            }
        }
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (1 <= num && num <= n && nums[num - 1] > 0) {
                nums[num - 1] = -nums[num - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num : nums) {
            if (num <= 0) {
                num = n + 1; // 不能转换成[1, n]中的数
            }
        }
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
int main() {

    system("pause");
    return 0;
}