#include <iostream>
using namespace std;
class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;                    // x=f(1)
        for (int i = 1; i < n; i++) { // 循环n-1次，递推n-1次，状态转移n-1次
            x = (x + m) % (i + 1);
        }
        return x;
    }
};
int main() {

    system("pause");
    return 0;
}