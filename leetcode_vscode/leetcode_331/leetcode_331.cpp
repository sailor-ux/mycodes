#include <iostream>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int numNull = 0;
        for (int i = preorder.length() - 1; i >= 0; i--) {
            if (preorder[i] == '#') {
                numNull++;
            } else if (isdigit(preorder[i])) {
                if (numNull < 2) {
                    return false;
                }
                numNull--;
                while (i >= 0 && isdigit(preorder[i])) {
                    i--;
                }
            }
        }
        return numNull == 1;
    }
};
int main() {
    Solution sol;
    cout << sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
    system("pause");
    return 0;
}