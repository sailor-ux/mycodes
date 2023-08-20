#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]) && i - mp[nums[i]].back() <= k) {
                return true;
            }
            mp[nums[i]].push_back(i);
            // mp[nums[i]].push_back(i);
            // int sz = mp[nums[i]].size();
            // if (sz != 1 && mp[nums[i]][sz - 1] - mp[nums[i]][sz - 2] <= k) {
            //     return true;
            // }
        }
        return false;
    }
};
int main() {

    system("pause");
    return 0;
}