#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1, n = nums.size(), maxErr = 0;
        for (; i < n - 1; i += 2) {
            maxErr = max(maxErr, max(abs(nums[i] - nums[i - 1]), abs(nums[i] - nums[i + 1])));
        }
        return n < 2 ? 0 : maxErr = max(maxErr, abs(nums[n - 1] - nums[n - 2]));
    }
};

int main() {

    system("pause");
    return 0;
}
