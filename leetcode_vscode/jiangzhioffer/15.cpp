#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += n % 2;
            n >>= 1;
        }
        return count;
    }
};
int main() {

    system("pause");
    return 0;
}