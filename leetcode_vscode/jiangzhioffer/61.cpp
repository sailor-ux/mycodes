#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt0 = 0, kongque = 0, n = nums.size();
        int i = 0;
        for (; i < n; i++) {
            if (nums[i] == 0) {
                cnt0++;
            } else {
                break;
            }
        }
        for (int j = i + 1; j < n; j++) {
            if (nums[j] == nums[j - 1]) {
                return false;
            }
            kongque += (nums[j] - nums[j - 1] - 1);
        }
        return cnt0 >= kongque;
    }
};
int main() {

    system("pause");
    return 0;
}