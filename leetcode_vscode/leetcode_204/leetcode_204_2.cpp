#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // �ٶȸĽ�����Լʱ�䣡(ע��ʹ��long long����)
    int countPrimes(int n) {
        int ans = 0;
        vector<int> isPrime(n, 1);
        for (long long i = 2; i < n; i++) {
            if (isPrime[i]) {
                ans++;
                for (long long j = i; i * j < n; j++) { // ��i * i��ʼ�����Ϊ0(����)���ɣ���
                    isPrime[i * j] = 0;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    cout << sol.countPrimes(499979);
    system("pause");
    return 0;
}