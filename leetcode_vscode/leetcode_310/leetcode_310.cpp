#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> ans;
        queue<int> q;
        vector<int> degree(n);
        vector<vector<int>> neighbors(n);
        vector<bool> visited(n, false); // 已经访问过的跳过，加速！
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            degree[u]++;
            degree[v]++;
            neighbors[u].push_back(v);
            neighbors[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            ans.clear();
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                degree[node]--;
                for (const int& neighbor : neighbors[node]) {
                    if (visited[neighbor]) {
                        continue;
                    }
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
                visited[node] = true;
            }
        }
        return ans;
    }
};
int main() {

    system("pause");
    return 0;
}