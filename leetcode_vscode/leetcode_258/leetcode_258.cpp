#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while (1) {
            while (num) {
                int x = num % 10;
                sum += x;
                num /= 10;
            }
            if (sum < 10) {
                return sum;
            }
            num = sum;
            sum = 0;
        }
    }
};
int main() {
    Solution sol;
    cout << sol.addDigits(38);
    system("pause");
    return 0;
}