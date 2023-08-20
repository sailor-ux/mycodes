#include <iostream>
#include <vector>
using namespace std;
// 把所有上升区间加起来
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sumPro = 0;
        for (int i = 1; i < prices.size(); i++) {
            sumPro += prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0;
        }
        return sumPro;
    }
};
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(prices);
    system("pause");
    return 0;
}