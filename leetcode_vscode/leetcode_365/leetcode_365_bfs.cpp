#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// bfs
// 注意unordered_set不支持pair<int, int>！需要自定义SimpleHash！！！
class Solution {
public:
    struct SimpleHash {
        size_t operator()(const pair<int, int>& p) const {
            return p.first * 31 + p.second;
        }
    };
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        unordered_set<pair<int, int>, SimpleHash> st;
        queue<pair<int, int>> q;
        q.push({0, 0});
        st.insert({0, 0});
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                pair<int, int> state = q.front();
                q.pop();
                if (state.first == targetCapacity || state.second == targetCapacity || state.first + state.second == targetCapacity) {
                    return true;
                }
                if (!st.count({max(state.first - (jug2Capacity - state.second), 0), min(state.first + state.second, jug2Capacity)})) {
                    q.push({max(state.first - (jug2Capacity - state.second), 0), min(state.first + state.second, jug2Capacity)});
                    st.insert({max(state.first - (jug2Capacity - state.second), 0), min(state.first + state.second, jug2Capacity)});
                }
                if (!st.count({min(state.first + state.second, jug1Capacity), max(state.second - (jug1Capacity - state.first), 0)})) {
                    q.push({min(state.first + state.second, jug1Capacity), max(state.second - (jug1Capacity - state.first), 0)});
                    st.insert({min(state.first + state.second, jug1Capacity), max(state.second - (jug1Capacity - state.first), 0)});
                }
                if (!st.count({jug1Capacity, state.second})) {
                    q.push({jug1Capacity, state.second});
                    st.insert({jug1Capacity, state.second});
                }
                if (!st.count({state.first, jug2Capacity})) {
                    q.push({state.first, jug2Capacity});
                    st.insert({state.first, jug2Capacity});
                }
                if (!st.count({0, state.second})) {
                    q.push({0, state.second});
                    st.insert({0, state.second});
                }
                if (!st.count({state.first, 0})) {
                    q.push({state.first, 0});
                    st.insert({state.first, 0});
                }
            }
        }
        return false;
    }
};
int main() {
    Solution sol;
    cout << sol.canMeasureWater(3, 5, 4);
    system("pause");
    return 0;
}