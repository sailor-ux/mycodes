#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 栈最后的时候可能还有一些元素残留，它们需要出栈吗？
// 就算出栈了，ans对应的元素也是赋值为0，不妨让ans初值全为0，如此一来不必出栈！
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || temperatures[stk.top()] >= temperatures[i]) {
                stk.push(i);
            } else {
                while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                    int idx = stk.top();
                    ans[idx] = i - idx;
                    stk.pop();
                }
                stk.push(i);
            }
        }
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