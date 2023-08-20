#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // dfs ������ʱ ���ڴ������ظ����� ��Ҫȥ�ؼ�֦������
    // Ҳ��dp
    // ֮ǰ��һ����Ŀ������ ��Ҫ��������
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int sum = 0;
        dfs(s, t, 0, 0, sum);
        return sum;
    }
    void dfs(string& s, string& t, int start, int index, int& sum) {
        if (index == t.length()) {
            sum++;
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (s[i] == t[index]) {
                dfs(s, t, i + 1, index + 1, sum);
            }
        }
    }
};
int main() {
    Solution sol;
    cout << sol.numDistinct("babgbag", "bag");
    system("pause");
    return 0;
}