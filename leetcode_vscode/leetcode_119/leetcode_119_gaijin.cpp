#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return {1};
        }
        vector<int> res{1, 1};
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = 0; j < res.size() - 1; j++) {
                res[j] = res[j] + res[j + 1];
            }
            res.insert(res.begin(), 1); // 最前面插入1
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> res = sol.getRow(4);
    for (int x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}