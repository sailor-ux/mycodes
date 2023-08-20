#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ������136��
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, a = 0, b = 0;
        for (const int& num : nums) {
            x ^= num;
        }
        x = x == INT_MIN ? x : x &= -x; // ��ֹ�������̫����
        for (const int& num : nums) {
            if (num & x) { // == x ��д�����ԣ���ʱ�������ʱ��ԣ�������
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};
int main() {
    vector<int> nums{1, 2, 1, 3, 2, 5};
    Solution sol;
    nums = sol.singleNumber(nums);
    for (int x : nums) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}