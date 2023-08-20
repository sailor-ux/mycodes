#include <iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        for (int num = 5; num <= n; num += 5) {
            int temp = num;
            while (!(temp % 5)) {
                ++sum;
                temp /= 5;
            }
        }
        return sum;
    }
};
int main() {
    Solution sol;
    cout << sol.trailingZeroes(10);
    system("pause");
    return 0;
}