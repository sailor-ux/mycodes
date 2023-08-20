#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 类似于300题最长递增子序列的贪心+二分的解法
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> arr(n);
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& e1, const vector<int>& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        for (int i = 0; i < n; i++) {
            arr[i] = envelopes[i][1];
        }
        return lengthOfLIS(arr);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> d;
        d.push_back(-1);
        d.push_back(nums[0]);
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > d[len]) {
                d.push_back(nums[i]);
                len++;
            } else {
                int l = 1, r = len, pos = 0;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
int main() {
    vector<vector<int>> envelopes{{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370}, {6, 360}, {7, 380}};
    Solution sol;
    cout << sol.maxEnvelopes(envelopes);
    system("pause");
    return 0;
}