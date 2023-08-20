#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool flag = true;
        map<int, vector<int>> hash;
        set<pair<int, int>> st;
        for (const vector<int>& vec : prerequisites) {
            hash[vec[0]].push_back(vec[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            dfs(hash, st, flag, i, i);
            if (!flag) {
                return flag; // false
            }
        }
        return flag; // true
    }
    void dfs(map<int, vector<int>>& hash, set<pair<int, int>>& st, bool& flag, int begin, int temp) {
        if (st.find(make_pair(begin, temp)) != st.end()) {
            return;
        }
        st.insert(make_pair(begin, temp));
        if (hash.count(temp)) {
            for (const int& x : hash[temp]) {
                if (x == begin) {
                    flag = false;
                    return;
                }
                dfs(hash, st, flag, begin, x);
                if (!flag) {
                    return;
                }
            }
        }
    }
    // dfs(hash, flag, 0, 1); ��ѭ��
    // dfs(0, 1)���ù���dfs(0, 1)�����������
    // dfs(0, 1)���ջ�û��ִ���� ���� dfs(0, 1)�ߵ�������ߵ����Ҳû�г��ֱջ�, flag��ȻΪtrue
    // ����dfs(0, 1)û��Ҫ���ߣ�dfs(0, 1)��ִ�в����û�������Ҳֱ�ӽ���
};
int main() {
    vector<vector<int>> prerequisites{{0, 1}, {3, 1}, {1, 3}, {3, 2}};
    Solution sol;
    cout << sol.canFinish(4, prerequisites);
    system("pause");
    return 0;
}