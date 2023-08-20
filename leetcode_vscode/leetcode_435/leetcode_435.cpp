#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= right) {
                ans++;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};
int main() {
    vector<vector<int>> intervals{{-1, 2}, {1, 2}, {2, 4}, {-2, -1}, {1, 3}};
    Solution sol;
    system("pause");
    return 0;
}