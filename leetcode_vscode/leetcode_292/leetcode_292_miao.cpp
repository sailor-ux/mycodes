#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
int main() {
    Solution sol;
    cout << sol.canWinNim(43);
    system("pause");
    return 0;
}