#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    // 单调栈，更多细节见平板！
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                int idx = stk.top();
                stk.pop();
                ans[idx] = i - idx;
            }
            stk.push(i);
        }
        // while (!stk.empty()) {
        //     int idx = stk.top();
        //     stk.pop();
        //     ans[idx] = 0;
        // }
        return ans;
    }
};
int main() {
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    Solution sol;
    vector<int> res = sol.dailyTemperatures(temperatures);
    for (const int& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}