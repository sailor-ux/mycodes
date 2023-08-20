#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 两层for循环，暴力超时！
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n - 1; i++) {
            bool flag = true;
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    ans[i] = j - i;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans[i] = 0;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    Solution sol;
    vector<int> res = sol.dailyTemperatures(temperatures);
    for (const int& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}