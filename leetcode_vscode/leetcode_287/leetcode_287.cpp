#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // ������һ���������ٴ���һ�������������ظ�����2��
    // ���л����һ�����ھ����ظ�����2�ε�����
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
int main() {
    vector<int> nums{3, 1, 3, 4, 2};
    Solution sol;
    cout << sol.findDuplicate(nums);
    system("pause");
    return 0;
}