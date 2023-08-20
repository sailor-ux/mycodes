#include <iostream>
using namespace std;
class Solution {
public:
    // ��ʱ��
    int countPrimes(int n) {
        int res = 0;
        for (int num = 2; num < n; num++) {
            if (isPrime(num)) {
                res++;
            }
        }
        return res;
    }
    bool isPrime(int x) { // �ж�x�ǲ���������ö��[2, sqrt(x)]������Χ�ڴ���x����������x��������
        for (int num = 2; num * num <= x; num++) {
            int y = x / num;
            if (y * num == x) { // x % num == 0, return false;
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    cout << sol.countPrimes(10);
    system("pause");
    return 0;
}