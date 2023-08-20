#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) {
            return true;
        }
        int n = postorder.size(), root = postorder[n - 1], idx = 0;
        while (postorder[idx] < root) {
            idx++;
        }
        for (int i = idx + 1; i <= n - 2; i++) {
            if (postorder[i] < root) {
                return false;
            }
        }
        vector<int> leftTree, rightTree;
        leftTree.assign(postorder.begin(), postorder.begin() + idx);
        rightTree.assign(postorder.begin() + idx, postorder.end() - 1);
        return verifyPostorder(leftTree) && verifyPostorder(rightTree);
    }
};
int main() {

    system("pause");
    return 0;
}