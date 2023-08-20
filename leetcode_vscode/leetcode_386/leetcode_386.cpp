#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //迭代，更像是找规律！！
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int num = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = num;
            if (10 * num <= n) {
                num *= 10;
            } else {
                while (num % 10 == 9 || num == n) {
                    num /= 10;
                }
                num++;
            }
        }
        return ans;
    }
    //递归
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, ans);
        }
        return ans;
    }
    void dfs(int cur, const int& n, vector<int>& ans) {
        if (cur <= n) {
            ans.push_back(cur);
            for (int i = 0; i <= 9; i++) {
                dfs(10 * cur + i, n, ans);
            }
        }
    }
    //递归改进加速！！
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= min(n, 9); i++) {
            dfs(i, n, ans);
        }
        return ans;
    }
    void dfs(int cur, const int& n, vector<int>& ans) {
        ans.push_back(cur);
        for (int i = 0; i <= 9; i++) {
            if (10 * cur + i > n) {
                return;
            }
            dfs(10 * cur + i, n, ans);
        }
    }
};
int main() {
    Solution sol;
    vector<int> res = sol.lexicalOrder(150);
    for (const int& x : res) {
        cout << x << ' ' << '\t';
    }
    system("pause");
    return 0;
}