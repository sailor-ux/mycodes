#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> dp(n, INT_MAX);
        dp[0] = 1;
        vector<int> pointers(primes.size(), 0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < primes.size(); j++) {
                dp[i] = min(dp[i], dp[pointers[j]] * primes[j]);
            }
            for (int j = 0; j < primes.size(); j++) {
                if (dp[pointers[j]] * primes[j] == dp[i]) {
                    pointers[j]++;
                }
            }
        }
        return dp[n - 1];
    }
};
int main() {

    system("pause");
    return 0;
}