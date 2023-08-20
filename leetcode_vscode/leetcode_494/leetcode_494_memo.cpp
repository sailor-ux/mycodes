#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    //�����ݷ���������������������ʱ�临�ӶȺܸߣ�������ʱʱ�����ü��仯���ݣ�����
    //����������Ŀ���и���dp�ⷨ������
    unordered_map<string, int> hashMemo;
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        return dfs(nums, 0, target);
    }
    int dfs(vector<int>& nums, int index, int target) {
        string str = to_string(index) + "-" + to_string(target);
        if (hashMemo.count(str)) {
            return hashMemo[str];
        }
        if (index == nums.size()) {
            if (target == 0) {
                hashMemo[str] = 1; // ��ע�͸��ã��и���
                return 1;
            }
            hashMemo[str] = 0;
            return 0;
        }
        hashMemo[str] = dfs(nums, index + 1, target - nums[index]) + dfs(nums, index + 1, target + nums[index]);
        return hashMemo[str];
    }
};
int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    Solution sol;
    cout << sol.findTargetSumWays(nums, 3);
    system("pause");
    return 0;
}