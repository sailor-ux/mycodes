#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1; // res��ֵ=dp[0]=1
        for (int i = 1; i < n; i++) {
            int maxVal = 0; // maxVal��ֵ<=1����ʵ��Ȼ����ֵֻ��Ϊ0��������û�з���������dp[j]ʱ��maxValӦ��Ϊ0��dp[i]Ӧ��Ϊ1������
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    maxVal = max(maxVal, dp[j]);
                }
            }
            dp[i] += maxVal;
            res = max(res, dp[i]);
        }
        return res;
    }
};
int main() {

    system("pause");
    return 0;
}