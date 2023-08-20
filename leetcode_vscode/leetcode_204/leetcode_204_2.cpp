#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 再度改进，节约时间！(注意使用long long类型)
    int countPrimes(int n) {
        int ans = 0;
        vector<int> isPrime(n, 1);
        for (long long i = 2; i < n; i++) {
            if (isPrime[i]) {
                ans++;
                for (long long j = i; i * j < n; j++) { // 从i * i开始，标记为0(合数)即可！！
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