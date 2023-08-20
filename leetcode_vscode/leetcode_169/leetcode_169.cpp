#include <iostream>
#include <vector>
using namespace std;
// �ӵ�һ������ʼcount=1��������ͬ�ľͼ�1��������ͬ�ľͼ�1������0�����»�������ʼ�����������ҵ������Ǹ�
// ��ƴ����
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, val = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (!count) {
                val = nums[i];
                count++;
            } else if (nums[i] == val) {
                count++;
            } else {
                count--;
            }
        }
        return val;
    }
};
int main() {
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    cout << sol.majorityElement(nums);
    system("pause");
    return 0;
}