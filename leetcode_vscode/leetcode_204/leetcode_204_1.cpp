#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 一个合数(非质数)，必然存在某个比它小的质数，该合数是该质数的若干倍！！！
    // 可以再度改进，节约时间！
    int countPrimes(int n) {
        int ans = 0;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                ans++;
                for (int j = 2; i * j < n; j++) {
                    isPrime[i * j] = 0;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    cout << sol.countPrimes(10);
    system("pause");
    return 0;
}