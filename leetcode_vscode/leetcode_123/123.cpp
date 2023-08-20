#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /* int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        for (int i = 2; i <= prices.size(); i++) {
            vector<int> leftPrices = prices, rightPrices = prices;
            leftPrices.assign(leftPrices.begin(), leftPrices.begin() + i);  //[0, i)
            rightPrices.assign(rightPrices.begin() + i, rightPrices.end()); //[i, n-1]
            int profit = maxProfit121(leftPrices) + maxProfit121(rightPrices);
            maxPro = max(maxPro, profit);
        }
        return maxPro;
    }
    int maxProfit121(vector<int>& prices) { // 121题，最多一次交易的最大利润
        if (prices.empty()) {
            return 0;
        }
        int hisMinPri = prices[0];                // 历史最小价格
        int maxPro = 0;                           // 最大利润
        for (int i = 1; i < prices.size(); i++) { // 枚举在第i天抛售股票
            maxPro = max(maxPro, prices[i] - hisMinPri);
            hisMinPri = min(hisMinPri, prices[i]); // 求(更新)历史最小价格，不需要遍历，不需要O(n)的时间复杂度
        }
        return maxPro;
    }
    // leftPrices数组的长度多1时，两次调用maxProfit121，其中包含大量重复计算，所以超时 */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 以下类似于状态转移方程：
        //  left[i] = prices[0:i]一笔交易的最大利润 = max(left[i-1], 在第i天将股票抛售一笔交易可以获得的最大利润)
        //  right[i] = prices[i:n-1]一笔交易的最大利润 = max(right[i+1], 在第i天买入股票在未来的某一天抛售，一笔交易可以获得的最大利润)
        vector<int> left(n), right(n);
        for (int i = 1, hisMinPri = prices[0]; i < n; i++) {
            left[i] = max(left[i - 1], prices[i] - hisMinPri);
            hisMinPri = min(hisMinPri, prices[i]);
        }
        for (int i = n - 2, futMaxPri = prices[n - 1]; i >= 0; i--) {
            right[i] = max(right[i + 1], futMaxPri - prices[i]);
            futMaxPri = max(futMaxPri, prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};
int main() {

    system("pause");
    return 0;
}
