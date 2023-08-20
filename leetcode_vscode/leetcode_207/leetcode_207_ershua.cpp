#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> rudu(numCourses, 0);
        vector<vector<int>> pointto(numCourses);
        queue<int> q;
        int visited = 0;
        for (const vector<int>& prerequisite : prerequisites) {
            rudu[prerequisite[0]]++;
            pointto[prerequisite[1]].push_back(prerequisite[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (rudu[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            visited++;
            int cour = q.front();
            q.pop();
            for (const int& course : pointto[cour]) {
                if (--rudu[course] == 0) {
                    q.push(course);
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