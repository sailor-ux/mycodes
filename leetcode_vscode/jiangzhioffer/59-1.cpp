#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    // 优先队列、大根堆
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.push({nums[i], i});
        }
        vector<int> ans{q.top().first};
        for (int i = k; i < nums.size(); i++) {
            q.push({nums[i], i}); // 滑动窗口右移一位
            while (q.top().second < i + 1 - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
    // 双端队列(单调的双端队列一般称作「单调队列」)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans{nums[q.front()]};
        for (int i = k; i < n; i++) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i); // 滑动窗口右移一位，紧接着就求滑动窗口内的最大值
            while (q.front() < i + 1 - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
int main() {

    system("pause");
    return 0;
}