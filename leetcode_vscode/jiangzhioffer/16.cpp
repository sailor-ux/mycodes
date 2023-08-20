#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        if (N == 0) {
            return 1;
        }
        if (N == 1) {
            return x;
        }
        bool isNeg = false;
        if (N < 0) {
            isNeg = true;
            // n = -n; // n = INT_MINʱ�������Խ�磡����nת��Ϊlong����
            N = -N;
        }
        // double res = myPow(myPow(x, n >> 1), 2); // ��n=2������2�η�ʱ������д������ѭ����
        double res = myPow(x, N >> 1);
        res *= res; // ��ֹ��ѭ��������2�η�������myPow
        res *= (N & 1) ? x : 1;
        if (isNeg) {
            return 1 / res;
        }
        return res;
    }
};
int main() {
    Solution sol;
    cout << sol.myPow(4, -2);
    system("pause");
    return 0;
}