#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long num = 0;
        while (x) {
            num = 10 * num + x % 10;
            if (num > INT_MAX || num < INT_MIN) {
                return 0;
            }
            x /= 10;
        }
        return num;
    }
};
int main() {
    Solution sol;
    cout << sol.reverse(-123);
    system("pause");
    return 0;
}