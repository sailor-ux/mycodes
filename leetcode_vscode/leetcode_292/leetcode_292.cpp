#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int, bool> memoMap;
    bool canWinNim(int n) {
        if (memoMap.count(n)) {
            return memoMap[n];
        }
        if (n < 4) {
            memoMap[n] = true;
            return true;
        }
        return memoMap[n] = !canWinNim(n - 1) || !canWinNim(n - 2) || !canWinNim(n - 3);
    }
};
int main() {
    Solution sol;
    cout << sol.canWinNim(43);
    system("pause");
    return 0;
}