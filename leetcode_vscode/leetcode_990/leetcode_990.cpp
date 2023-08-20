#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> fa;
    vector<int> rank;
    Solution() {
        fa.resize(26);
        rank.resize(26);
        for (int i = 0; i < 26; i++) {
            fa[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) { // 一路查找结点x最后的父节点(根节点)
        if (fa[x] == x) {
            return x;
        } else {
            fa[x] = find(fa[x]); // 路径压缩，查询时才进行，并且只压缩一条路径；find(fa[x])返回结点x最后的父节点
            return fa[x];
        }
        // return fa[x] == x ? x : (fa[x] = find(fa[x]));
    }
    void merge(int x, int y) {                // 将x和y所在的两棵树、两个集合合并成一棵树、一个集合(注意x和y可能早已经在一棵树上，一个集合内了)
        int rootX = find(x), rootY = find(y); // 若x和y早在一棵树上，rootX=rootY，可以直接return
        if (rank[rootX] <= rank[rootY]) {
            fa[rootX] = rootY;
        } else {
            fa[rootY] = rootX;
        }
        if (rank[rootX] == rank[rootY] && rootX != rootY) { // 若x和y早在一棵树上，rootX=rootY，rank不变！
            rank[rootY]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        for (const string& str : equations) {
            if (str[1] == '=') {
                merge(str[0] - 'a', str[3] - 'a');
            }
        }
        for (const string& str : equations) {
            if (str[1] == '!') {
                if (find(str[0] - 'a') == find(str[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    vector<string> equations{"a==b", "b!=c", "c==a"};
    Solution sol;
    cout << sol.equationsPossible(equations);
    system("pause");
    return 0;
}