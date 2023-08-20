#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (i > indexDiff) {
                int id = nums[i - indexDiff - 1] / (valueDiff + 1);
                mp.erase(id);
            }
            int id = nums[i] / (valueDiff + 1);
            if (id == 0 && nums[i] < 0) { //-3/5=-1而不是=0，-3应该在-1号桶而不是0号桶
                id = -1;
            }
            if (mp.count(id)) {
                return true;
            }
            mp[id] = nums[i];
            if ((mp.count(id - 1) && abs(mp[id - 1] - nums[i]) <= valueDiff) || (mp.count(id + 1) && abs(mp[id + 1] - nums[i]) <= valueDiff)) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    vector<int> nums{-3, 3};
    Solution sol;
    cout << sol.containsNearbyAlmostDuplicate(nums, 2, 4);
    system("pause");
    return 0;
}