#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, i = 0, j = 1;
        while (j + 1 < n) {
            int sub = nums[j] - nums[i];
            while (j + 1 < n && nums[j + 1] - nums[j] == sub) {
                j++;
            }
            if (j - i > 1) {
                sum += (j - i) * (j - i - 1) / 2;
            }
            i = j;
            j++;
        }
        return sum;
    }
};
int main() {

    system("pause");
    return 0;
}