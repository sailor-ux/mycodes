#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
            sum += nums[i];
        }
        int maxVal = f; // F(0)
        for (int i = n - 1; i >= 1; i--) {
            f += sum - n * nums[i];
            maxVal = max(maxVal, f);
        }
        return maxVal;
    }
};
int main() {

    system("pause");
    return 0;
}