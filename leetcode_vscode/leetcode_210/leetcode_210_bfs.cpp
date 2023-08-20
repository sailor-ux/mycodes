#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// ¿‡À∆”⁄207Ã‚ bfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
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
            int course = q.front();
            q.pop();
            res.push_back(course);
            for (const int& cour : edges[course]) {
                if (--indeg[cour] == 0) {
                    q.push(cour);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};
int main() {

    system("pause");
    return 0;
}