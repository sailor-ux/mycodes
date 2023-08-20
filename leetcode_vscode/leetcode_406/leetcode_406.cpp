#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 记忆评论区的题解！！！
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> res(n);
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = i;
        }
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < n; i++) {
            res[vec[people[i][1]]] = people[i];
            vec.erase(vec.begin() + people[i][1]);
        }
        return res;
    }
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] < b[0]) {
            return true;
        } else if (a[0] == b[0]) {
            if (a[1] > b[1]) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution sol;
    people = sol.reconstructQueue(people);
    for (auto vec : people) {
        cout << "[" << vec[0] << " , " << vec[1] << "]  ";
    }
    system("pause");
    return 0;
}