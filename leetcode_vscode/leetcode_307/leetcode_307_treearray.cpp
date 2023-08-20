#include <iostream>
#include <vector>
using namespace std;
//ǰ׺�����鳬ʱ����������CΪ��״���飡��һֱ����һ����ʽ������A������
class NumArray {
public:
    vector<int> tree;  // C
    vector<int>& nums; // A��nums��ͷ��һ��Ԫ�أ�A[0]����
    NumArray(vector<int>& nums) : nums(nums) {
        tree.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) { // ����A[i+1], A[i+1]=nums[i], A[i+1]ԭΪ0, A[i+1]+=nums[i]
            add(i + 1, nums[i]);
        }
    }

    void update(int index, int val) { // nums[index]/A[index+1] = val
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return getPreSum(right + 1) - getPreSum(left);
    }

    int lowbit1(int& x) {
        return x & (-x);
    }

    int getPreSum(int index) { // A[1]+A[2]+...+A[index]
        int preSum = 0;
        while (index > 0) {
            preSum += tree[index];
            index -= lowbit1(index);
        }
        return preSum;
    }

    void add(int index, int val) { //����A[index], A[index]+=val
        while (index < tree.size()) {
            tree[index] += val;
            index += lowbit1(index);
        }
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