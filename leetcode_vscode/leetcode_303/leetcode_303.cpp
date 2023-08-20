#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int preSum = 0;
        prefixSum.push_back(preSum);
        for (const int& num : nums) {
            preSum += num;
            prefixSum.push_back(preSum);
        }
    }

    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};
int main() {

    system("pause");
    return 0;
}