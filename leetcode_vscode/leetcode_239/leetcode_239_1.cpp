#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // deque˫�˶��У����������(��Ƚ��ڶ���queueֻ�ܶ�β�������׳�)
    // �ٽ⣬�е������ڵ���ջ(<�룬>=��)���е��ڼ�˼·��
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> res{nums[q.front()]};
        for (int i = k; i < n; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};
int main() {
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    Solution sol;
    vector<int> res = sol.maxSlidingWindow(nums, 3);
    for (auto x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}