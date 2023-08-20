#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(3, 0));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
    // �ռ�ѹ����
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int x = -prices[0], y = 0, z = 0;
        for (int i = 1; i < n; i++) {
            int originalX = x;
            x = max(x, z - prices[i]);
            z = max(y, z);
            y = originalX + prices[i];
        }
        return max(y, z);
    }
};
int main() {

    system("pause");
    return 0;
}