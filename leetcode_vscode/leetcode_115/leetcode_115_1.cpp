#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // 还是超时，通过的测试用例更多了！！
    // dfs + 记忆化memo数组，去重剪枝，仍然超时！从前往后的
    // 要用记忆化memo数组，dfs函数不能是void类型(没有返回值)，要变成有返回值的函数类型！
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int sum = 0;
        return dfs(s, t, 0, 0, memo);
    }
    int dfs(string& s, string& t, int start, int index, vector<vector<int>>& memo) {
        if (index == t.length()) {
            return 1;
        }
        if (start == s.length()) {
            return 0;
        }
        if (memo[start][index] != -1) {
            return memo[start][index];
        }
        int sum = 0;
        for (int i = start; i < s.length(); i++) {
            if (s[i] == t[index]) {
                sum += dfs(s, t, i + 1, index + 1, memo);
            }
        }
        memo[start][index] = sum;
        return sum;
    }
};
int main() {
    Solution sol;
    cout << sol.numDistinct("ddd", "dd");
    system("pause");
    return 0;
}