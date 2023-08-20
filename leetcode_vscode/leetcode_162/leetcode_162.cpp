#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else if (mid == 0 || nums[mid - 1] < nums[mid]) {
                return mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
int main() {
    vector<int> nums{1, 2};
    Solution sol;
    cout << sol.findPeakElement(nums);
    system("pause");
    return 0;
}