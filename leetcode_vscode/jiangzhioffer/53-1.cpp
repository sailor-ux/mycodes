#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1, pos = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                pos = mid;
                break;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (pos == -1) {
            return 0;
        }
        int posBegin = -1;
        l = 0, r = pos;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                posBegin = mid;
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        int posEnd = -1;
        l = pos, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                posEnd = mid;
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            }
        }
        return posEnd - posBegin + 1;
    }
    // 这个再优化了一下！
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        int posBegin = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                posBegin = mid;
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (posBegin == -1) {
            return 0;
        }
        l = posBegin, r = n - 1;
        int posEnd = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                posEnd = mid;
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            }
        }
        return posEnd - posBegin + 1;
    }
};
int main() {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    Solution sol;
    cout << sol.search(nums, 6);
    system("pause");
    return 0;
}