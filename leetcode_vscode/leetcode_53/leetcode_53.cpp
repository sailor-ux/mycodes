#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int var = 0, res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            var = max(nums[i] + var, nums[i]);
            res = max(res, var);
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}