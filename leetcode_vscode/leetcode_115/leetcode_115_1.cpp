#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // ���ǳ�ʱ��ͨ���Ĳ������������ˣ���
    // dfs + ���仯memo���飬ȥ�ؼ�֦����Ȼ��ʱ����ǰ�����
    // Ҫ�ü��仯memo���飬dfs����������void����(û�з���ֵ)��Ҫ����з���ֵ�ĺ������ͣ�
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