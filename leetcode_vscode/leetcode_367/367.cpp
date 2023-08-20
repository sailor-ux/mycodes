#include <iostream>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            long square = (long)mid * (long)mid;
            if (square == num) {
                return true;
            } else if (square < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
int main() {

    system("pause");
    return 0;
}