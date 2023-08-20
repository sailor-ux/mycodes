#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = popped.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || popped[i] != stk.top()) {
                while (idx < n && pushed[idx] != popped[i]) {
                    stk.push(pushed[idx]);
                    idx++;
                }
                if (idx == n) {
                    return false;
                }
                idx++;
            } else {
                stk.pop();
            }
        }
        return true;
    }
};
int main() {
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4, 3, 5, 1, 2};
    Solution sol;
    cout << sol.validateStackSequences(pushed, popped);
    system("pause");
    return 0;
}