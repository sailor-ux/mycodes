#include <iostream>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int sum = 10, num = 9;
        for (int i = 9; i >= 11 - n; i--) {
            num *= i;
            sum += num;
        }
        return sum;
    }
};
int main() {

    system("pause");
    return 0;
}