#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (const int& num : nums) {
                if (num <= i && dp[i] <= INT_MAX - dp[i - num]) { // dp[i] + dp[i - num]���ܻ��������ô������ӵ���ʽ�Ͳ��ܳ��֣�����������д��
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
int main() {

    system("pause");
    return 0;
}