#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n) {
            sum += n % 2;
            n >>= 1;
        }
        return sum;
    }
};
int main() {

    system("pause");
    return 0;
}