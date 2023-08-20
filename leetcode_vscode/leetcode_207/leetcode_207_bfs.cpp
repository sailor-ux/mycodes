#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// bfs 有向无环存在拓扑排序返回true 有向有环不存在拓扑排序返回false
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int visited = 0;
        vector<int> indeg(numCourses);
        vector<vector<int>> edges(numCourses);
        for (const vector<int>& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            visited++;
            int course = q.front();
            q.pop();
            for (const int& cour : edges[course]) {
                if (--indeg[cour] == 0) {
                    q.push(cour);
                }
            }
        }
        return visited == numCourses;
    }
};
int main() {

    system("pause");
    return 0;
}