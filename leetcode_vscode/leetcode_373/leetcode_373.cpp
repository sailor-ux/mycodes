#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](const auto& a, const auto& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        vector<vector<int>> ans;
        bool flag = true;
        int n = nums1.size(), m = nums2.size();
        if (n > m) {
            swap(nums1, nums2);
            swap(n, m);
            flag = false;
        }
        int i = 0;
        for (int i = 0; i < min(n, k); i++) {
            q.push({i, 0});
        }
        while (ans.size() < k && !q.empty()) {
            auto [a, b] = q.top();
            q.pop();
            flag ? ans.push_back({nums1[a], nums2[b]}) : ans.push_back({nums2[b], nums1[a]});
            if (b + 1 < m) {
                q.push({a, b + 1}); //多路归并，b要立马看一下下一个，入队列；因此队列里面放下标而不放元素
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums1{1, 7, 11};
    vector<int> nums2{2, 4, 6};
    Solution sol;
    vector<vector<int>> ans = sol.kSmallestPairs(nums1, nums2, 6);
    for (auto vec : ans) {
        cout << vec[0] << ' ' << vec[1] << endl;
    }
    system("pause");
    return 0;
}