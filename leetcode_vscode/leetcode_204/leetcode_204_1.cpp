#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // һ������(������)����Ȼ����ĳ������С���������ú����Ǹ����������ɱ�������
    // �����ٶȸĽ�����Լʱ�䣡
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