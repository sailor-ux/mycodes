#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1; // res初值=dp[0]=1
        for (int i = 1; i < n; i++) {
            int maxVal = 0; // maxVal初值<=1，其实不然，初值只能为0！！！当没有符合条件的dp[j]时，maxVal应当为0，dp[i]应当为1！！！
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