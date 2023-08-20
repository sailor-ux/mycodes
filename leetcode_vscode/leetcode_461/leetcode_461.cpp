#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while (x || y) {
            count += x % 2 != y % 2;
            x >>= 1;
            y >>= 1;
        }
        return count;
    }
};
int main() {
    Solution sol;
    cout << sol.hammingDistance(1, 4);
    system("pause");
    return 0;
}