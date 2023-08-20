#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int high = 0, low = 0;
        int maxVal = INT_MIN, minVal = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < maxVal) {
                high = i;
            } else {
                maxVal = nums[i];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > minVal) {
                low = i;
            } else {
                minVal = nums[i];
            }
        }
        return low == high ? 0 : high - low + 1;
    }
};
int main() {

    system("pause");
    return 0;
}