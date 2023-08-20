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
    int find(int x) { // һ·���ҽ��x���ĸ��ڵ�(���ڵ�)
        if (fa[x] == x) {
            return x;
        } else {
            fa[x] = find(fa[x]); // ·��ѹ������ѯʱ�Ž��У�����ֻѹ��һ��·����find(fa[x])���ؽ��x���ĸ��ڵ�
            return fa[x];
        }
        // return fa[x] == x ? x : (fa[x] = find(fa[x]));
    }
    void merge(int x, int y) {                // ��x��y���ڵ����������������Ϻϲ���һ������һ������(ע��x��y�������Ѿ���һ�����ϣ�һ����������)
        int rootX = find(x), rootY = find(y); // ��x��y����һ�����ϣ�rootX=rootY������ֱ��return
        if (rank[rootX] <= rank[rootY]) {
            fa[rootX] = rootY;
        } else {
            fa[rootY] = rootX;
        }
        if (rank[rootX] == rank[rootY] && rootX != rootY) { // ��x��y����һ�����ϣ�rootX=rootY��rank���䣡
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