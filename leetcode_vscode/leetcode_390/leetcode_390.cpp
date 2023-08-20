#include <iostream>
using namespace std;
class Solution {
public:
    int lastRemaining(int n) {
        int first = 1, step = 1;
        bool flag = true;
        while (n > 1) {
            if (flag || n % 2 == 1) {
                first += step;
            }
            n /= 2;
            flag = !flag;
            step *= 2;
        }
        return first;
    }
};
int main() {

    system("pause");
    return 0;
}