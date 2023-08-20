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
    int maxProfit121(vector<int>& prices) { // 121�⣬���һ�ν��׵��������
        if (prices.empty()) {
            return 0;
        }
        int hisMinPri = prices[0];                // ��ʷ��С�۸�
        int maxPro = 0;                           // �������
        for (int i = 1; i < prices.size(); i++) { // ö���ڵ�i�����۹�Ʊ
            maxPro = max(maxPro, prices[i] - hisMinPri);
            hisMinPri = min(hisMinPri, prices[i]); // ��(����)��ʷ��С�۸񣬲���Ҫ����������ҪO(n)��ʱ�临�Ӷ�
        }
        return maxPro;
    }
    // leftPrices����ĳ��ȶ�1ʱ�����ε���maxProfit121�����а��������ظ����㣬���Գ�ʱ */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // ����������״̬ת�Ʒ��̣�
        //  left[i] = prices[0:i]һ�ʽ��׵�������� = max(left[i-1], �ڵ�i�콫��Ʊ����һ�ʽ��׿��Ի�õ��������)
        //  right[i] = prices[i:n-1]һ�ʽ��׵�������� = max(right[i+1], �ڵ�i�������Ʊ��δ����ĳһ�����ۣ�һ�ʽ��׿��Ի�õ��������)
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
