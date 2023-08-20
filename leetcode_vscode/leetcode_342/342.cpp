#include <iostream>
using namespace std;
// == ¸ßÓÚ &
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};
int main() {

    system("pause");
    return 0;
}