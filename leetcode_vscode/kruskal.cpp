#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int begin;
    int end;
    int weight;
    Edge(int begin, int end, int weight) : begin(begin), end(end), weight(weight) {}
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0;
        int n = points.size();
        int numEdges = n * (n - 1) / 2;
        vector<Edge> edges(numEdges, {0, 0, 0});
        vector<int> fa(n, 0);
        vector<int> rank(n, 1);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        int idx = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                edges[idx].begin = i;
                edges[idx].end = j;
                edges[idx].weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                idx++;
            }
        }
        sort(edges.begin(), edges.end(), [](const Edge& edgeA, const Edge& edgeB) {
            return edgeA.weight < edgeB.weight;
        });
        for (int i = 0; i < numEdges; i++) {
            int n = find(fa, edges[i].begin);
            int m = find(fa, edges[i].end);
            if (n != m) {
                merge(fa, rank, n, m);
                cost += edges[i].weight;
            }
        }
        return cost;
    }
    int find(vector<int>& fa, int x) {
        if (fa[x] == x) {
            return x;
        }
        fa[x] = find(fa, fa[x]);
        return fa[x];
    }
    void merge(vector<int>& fa, vector<int>& rank, int i, int j) {
        int x = find(fa, i), y = find(fa, j);
        if (rank[x] < rank[y]) {
            fa[x] = y;
        } else {
            fa[y] = x;
        }
        if (rank[x] == rank[y] && x != y) {
            rank[x]++;
        }
    }
};
int main() {
    vector<vector<int>> points{{-1000000, -1000000}, {1000000, 1000000}};
    Solution sol;
    cout << sol.minCostConnectPoints(points);
    system("pause");
    return 0;
}