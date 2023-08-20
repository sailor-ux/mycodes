#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    // 自己写的都超时了！！！
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), maxNum = 1;
        sort(envelopes.begin(), envelopes.end());
        vector<int> mp(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1]) { // 第i个信封可以装入第j个信封
                    mp[i] = max(mp[i], mp[j] + 1);
                }
            }
            maxNum = max(maxNum, mp[i]);
        }
        return maxNum;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), maxNum = 1;
        sort(envelopes.begin(), envelopes.end());
        unordered_map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            mp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1]) { // 第i个信封可以装入第j个信封
                    mp[i] = max(mp[i], mp[j] + 1);
                }
            }
            maxNum = max(maxNum, mp[i]);
        }
        return maxNum;
    }
};
int main() {
    vector<vector<int>> envelopes{{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370}, {6, 360}, {7, 380}};
    Solution sol;
    cout << sol.maxEnvelopes(envelopes);
    system("pause");
    return 0;
}