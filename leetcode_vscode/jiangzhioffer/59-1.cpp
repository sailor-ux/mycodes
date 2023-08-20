#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    // ���ȶ��С������
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.push({nums[i], i});
        }
        vector<int> ans{q.top().first};
        for (int i = k; i < nums.size(); i++) {
            q.push({nums[i], i}); // ������������һλ
            while (q.top().second < i + 1 - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
    // ˫�˶���(������˫�˶���һ��������������С�)
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
            q.push_back(i); // ������������һλ�������ž��󻬶������ڵ����ֵ
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