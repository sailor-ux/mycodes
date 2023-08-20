#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i] - 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
int main() {
    vector<int> nums{5, 4, 6, 7, 9, 3, 10, 9, 5, 6};
    Solution sol;
    vector<int> res = sol.findDuplicates(nums);
    for (auto x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}