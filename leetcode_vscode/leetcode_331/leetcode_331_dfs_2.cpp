#include <iostream>
#include <list>
using namespace std;
class Solution {
public:
    int n;
    bool isValidSerialization(string preorder) {
        n = preorder.length();
        int pos = 0;
        return dfs(preorder, pos) && pos == n + 1;
    }
    bool dfs(const string& preorder, int& pos) {
        if (pos == n + 1) {
            return false;
        }
        if (preorder[pos] == '#') {
            pos += 2;
            return true;
        }
        while (pos < n && isdigit(preorder[pos])) {
            pos++;
        }
        pos++;
        if (!dfs(preorder, pos)) {
            return false;
        }
        if (!dfs(preorder, pos)) {
            return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    cout << sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
    system("pause");
    return 0;
}