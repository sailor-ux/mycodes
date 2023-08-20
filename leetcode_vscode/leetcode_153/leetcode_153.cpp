#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int minVal = 5001;
        while (left <= right) {
            int mid = (left + right) / 2;
            minVal = nums[mid] < minVal ? nums[mid] : minVal;
            if (nums[mid] < nums[right]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return minVal;
    }
};
int main() {
    vector<int> nums{11, 13, 15, 17};
    Solution sol;
    cout << sol.findMin(nums);
    system("pause");
    return 0;
}