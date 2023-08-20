#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // k��Ķ�̬�滮�������ٷ���⣡����
    vector<double> dicesProbability(int n) {
        vector<double> f(6, 1.0 / 6.0); // f(1), f(n)�ĳ���5n+1
        for (int i = 2; i <= n; i++) {
            vector<double> tmp(5 * i + 1, 0.0); // tmp = f(i)
            for (int j = 0; j < f.size(); j++) {
                for (int k = 0; k < 6; k++) {
                    tmp[j + k] += f[j] / 6.0;
                }
            }
            f = tmp;
        }
        return f;
    }
};
int main() {
    Solution sol;
    vector<double> ps = sol.dicesProbability(2);
    for (const double& p : ps) {
        cout << p << ' ';
    }
    system("pause");
    return 0;
}