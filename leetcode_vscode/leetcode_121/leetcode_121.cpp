#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hisMinPri = prices[0];                // 历史最小价格
        int maxPro = 0;                           // 最大利润
        for (int i = 1; i < prices.size(); i++) { // 枚举在第i天抛售股票
            maxPro = max(maxPro, prices[i] - hisMinPri);
            hisMinPri = min(hisMinPri, prices[i]); // 求(更新)历史最小价格，不需要遍历，不需要O(n)的时间复杂度
        }
        return maxPro;
    }
};
int main() {

    system("pause");
    return 0;
}