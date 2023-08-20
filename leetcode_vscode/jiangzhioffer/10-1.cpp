#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// 递归更慢！！！
class Solution01 {
public:
    int MOD = 1000000007;
    int fib(int n) {
        unordered_map<int, int> mp;
        return dfs(mp, n);
    }
    int dfs(unordered_map<int, int>& mp, int n) {
        if (mp.count(n)) {
            return mp[n];
        }
        if (n < 2) {
            mp[n] = n;
            return n;
        }
        mp[n] = (dfs(mp, n - 1) + dfs(mp, n - 2)) % MOD;
        return mp[n];
    }
};
class Solution02 {
public:
    int MOD = 1000000007;
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> mp(n + 1, -1);
        mp[0] = 0;
        mp[1] = 1;
        return dfs(mp, n);
    }
    int dfs(vector<int>& mp, int n) {
        if (mp[n] != -1) {
            return mp[n];
        }
        mp[n] = (dfs(mp, n - 1) + dfs(mp, n - 2)) % MOD;
        return mp[n];
    }
};
// 循环最快！！！！！
class Solution03 {
public:
    int MOD = 1000000007;
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        int p = 0, q = 1, r = -1; // 前面2个分别是p、q
        for (int i = 0; i < n - 1; i++) {
            r = (p + q) % MOD;
            p = q;
            q = r;
        }
        return r;
    }
};
int main() {
    Solution03 sol;
    cout << sol.fib(45);
    system("pause");
    return 0;
}