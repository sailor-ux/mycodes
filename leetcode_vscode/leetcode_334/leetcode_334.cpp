#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> d;
        d.push_back(-1);
        d.push_back(nums[0]);
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > d[len]) {
                d.push_back(nums[i]);
                if (++len == 3) {
                    return true;
                }
            } else {
                int left = 1, right = len, pos = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return false;
    }
};
int main() {
    vector<int> nums{20, 100, 10, 12, 5, 13};
    Solution sol;
    cout << sol.increasingTriplet(nums);
    system("pause");
    return 0;
}