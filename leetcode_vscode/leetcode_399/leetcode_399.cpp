#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    unordered_map<string, int> hashMap;
    vector<int> fa;
    vector<double> weight;
    void init(int n) {
        fa.resize(n);
        weight.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            weight[i] = 1.00000;
        }
    }
    int find(int x) { // ×¢ÒâË³Ðò£¡£¡£¡
        if (fa[x] == x) {
            return x;
        }
        int originalFaNode = fa[x];
        fa[x] = find(fa[x]);
        weight[x] *= weight[originalFaNode];
        return fa[x];
    }
    void merge(int x, int y, double value) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        fa[rootX] = rootY;
        weight[rootX] = value * weight[y] / weight[x];
    }
    double isConnected(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) {
            return weight[x] / weight[y];
        }
        return -1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        int id = 0;
        for (const vector<string>& equation : equations) {
            for (int i = 0; i < 2; i++) {
                if (!hashMap.count(equation[i])) {
                    hashMap[equation[i]] = id++;
                }
            }
        }
        init(id);
        for (int i = 0; i < equations.size(); i++) {
            merge(hashMap[equations[i][0]], hashMap[equations[i][1]], values[i]);
        }
        for (int i = 0; i < queries.size(); i++) {
            if (hashMap.count(queries[i][0]) && hashMap.count(queries[i][1])) {
                res.push_back(isConnected(hashMap[queries[i][0]], hashMap[queries[i][1]]));
                continue;
            }
            res.push_back(-1.00000);
        }
        return res;
    }
};
int main() {
    vector<vector<string>> equations{{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}};
    vector<double> values{3.0, 4.0, 5.0, 6.0};
    vector<vector<string>> queries{{"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"}, {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}};
    Solution sol;
    vector<double> res = sol.calcEquation(equations, values, queries);
    for (double x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}