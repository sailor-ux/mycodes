#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//Ì°ÐÄ
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int pos = points[0][1];
        int count = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > pos) {
                pos = points[i][1];
                count++;
            }
        }
        return count;
    }
};
int main() {

    system("pause");
    return 0;
}