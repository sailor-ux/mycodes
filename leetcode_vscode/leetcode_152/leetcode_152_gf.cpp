#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0];
        int maxF_maxVal = maxF;
        for (int i = 1; i < nums.size(); i++) {
            int original_maxF = maxF;
            maxF = max(nums[i] * maxF, max(nums[i] * minF, nums[i]));
            minF = min(nums[i] * original_maxF, min(nums[i] * minF, nums[i]));
            maxF_maxVal = max(maxF, maxF_maxVal);
        }
        return maxF_maxVal;
    }
};
int main() {

    system("pause");
    return 0;
}