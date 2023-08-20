#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> rudu(numCourses, 0);
        vector<vector<int>> pointto(numCourses);
        queue<int> q;
        vector<int> res;
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
            int cour = q.front();
            q.pop();
            res.push_back(cour);
            for (const int& course : pointto[cour]) {
                if (--rudu[course] == 0) {
                    q.push(course);
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