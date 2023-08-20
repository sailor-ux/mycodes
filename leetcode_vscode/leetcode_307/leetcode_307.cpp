#include <iostream>
#include <vector>
using namespace std;
//前缀和数组超时！要学习线段树！！
class NumArray {
public:
    vector<int> preSum;
    vector<int> copyNums;
    NumArray(vector<int>& nums) {
        copyNums = nums;
        int presum = 0;
        preSum.push_back(0);
        for (const int& num : nums) {
            presum += num;
            preSum.push_back(presum);
        }
    }

    void update(int index, int val) {
        int sub = val - copyNums[index];
        copyNums[index] = val;
        for (int i = index + 1; i < preSum.size(); i++) {
            preSum[i] += sub;
        }
    }

    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main() {

    system("pause");
    return 0;
}