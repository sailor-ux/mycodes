#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hisMinPri = prices[0];                // ��ʷ��С�۸�
        int maxPro = 0;                           // �������
        for (int i = 1; i < prices.size(); i++) { // ö���ڵ�i�����۹�Ʊ
            maxPro = max(maxPro, prices[i] - hisMinPri);
            hisMinPri = min(hisMinPri, prices[i]); // ��(����)��ʷ��С�۸񣬲���Ҫ����������ҪO(n)��ʱ�临�Ӷ�
        }
        return maxPro;
    }
};
int main() {

    system("pause");
    return 0;
}