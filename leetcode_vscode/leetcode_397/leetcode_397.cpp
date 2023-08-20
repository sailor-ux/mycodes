#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // dp��ʱ����ʱԭ������ǲ�������n=>1����С�滻������������(1~n-1)=>1����С�滻������������˺ܶ��м�״̬��
    int integerReplacement(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            if (i % 2) {
                dp[i] = 2 + min(dp[(i + 1) / 2], dp[(i - 1) / 2]);
            } else {
                dp[i] = 1 + dp[i / 2];
            }
        }
        return dp[n];
    }
    //�ݹ�û���⣡
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        }
        long temp = n; // n==INT_MAX�� n+1����int�ı�ʾ��Χ�������Խ��
        return 2 + min(integerReplacement((temp + 1) / 2), integerReplacement((temp - 1) / 2));
    }
};
int main() {

    system("pause");
    return 0;
}