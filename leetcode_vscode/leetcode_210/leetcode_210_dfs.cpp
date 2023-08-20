#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> res;
    bool valid = true;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses, {});
        visited.resize(numCourses, 0);
        for (const vector<int>& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                dfs(i);
                if (!valid) {
                    return {};
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(int u) {
        visited[u] = 1;
        for (const int& v : edges[u]) {
            if (!visited[v]) {
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        res.push_back(u);
    }
};
int main() {

    system("pause");
    return 0;
}