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
    // dfs(hash, flag, 0, 1); 死循环
    // dfs(0, 1)调用过，dfs(0, 1)有两种情况：
    // dfs(0, 1)最终还没有执行完 或者 dfs(0, 1)走到最里层走到最后也没有出现闭环, flag仍然为true
    // 所以dfs(0, 1)没必要再走，dfs(0, 1)不执行不调用或者走了也直接结束
};
int main() {
    vector<vector<int>> prerequisites{{0, 1}, {3, 1}, {1, 3}, {3, 2}};
    Solution sol;
    cout << sol.canFinish(4, prerequisites);
    system("pause");
    return 0;
}