#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == i) {
                continue;
            }
            if (nums[nums[i]] == nums[i]) {
                return nums[i];
            }
            // swap(nums[i], nums[nums[i]]); // ³ö´í
            /* int temp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = temp; // ³ö´í */
            int temp = nums[i];
            nums[i] = nums[nums[i]];
            nums[temp] = temp;
        }
        return -1;
    }
};
int main() {

    system("pause");
    return 0;
}