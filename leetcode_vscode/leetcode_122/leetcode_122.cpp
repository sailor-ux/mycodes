#include <iostream>
#include <vector>
using namespace std;
// 把所有的上坡加起来
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i - 1] > 0) {
                sum += (prices[i] - prices[i - 1]);
            }
        }
        return sum;
    }
};
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(prices);
    system("pause");
    return 0;
}