#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        vector<int> temp = nums;
        for (int i = 0; i < n; i++) {
            temp.push_back(nums[i]);
        }
        for (int i = 0; i < 2 * n; i++) {
            if (stk.empty() || temp[stk.top()] >= temp[i]) {
                stk.push(i);
            } else {
                while (!stk.empty() && temp[stk.top()] < temp[i]) {
                    int idx = stk.top();
                    if (idx < n) {
                        ans[idx] = temp[i];
                    }
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums{1, 2, 3, 4, 3};
    Solution sol;
    vector<int> ans = sol.nextGreaterElements(nums);
    for (auto& x : ans) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}