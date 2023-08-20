#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// ջ����ʱ����ܻ���һЩԪ�ز�����������Ҫ��ջ��
// �����ջ�ˣ�ans��Ӧ��Ԫ��Ҳ�Ǹ�ֵΪ0��������ans��ֵȫΪ0�����һ�����س�ջ��
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