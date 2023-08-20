#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// ����ջ��
// Ѱ���Ҳ��һ�����Լ���ģ������ݼ�ջ����
// Ѱ���Ҳ��һ��(�ϸ�)���Լ���ģ����Ҳ����ջ��Ҳ����˵����ջ�Ͳ��ϸ��ˣ���
// �Ҳ������������˳�������
// ��ջ��ʱ�򣬶��ڳ�ջ(ջ��)Ԫ�أ�ȷ��(��Ӧ)�˵�ǰ����������Ԫ�أ�����
// ����stk.top()����һ�������Ԫ�ؼ�Ϊnums2[i]
// ջ�ڵ�����Ԫ�ر���ȫ����ջ��
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_map<int, int> mp;
        stack<int> stk;
        nums2.push_back(10001); // �ڱ�����֤ȫ����ջ
        for (int i = 0; i < nums2.size(); i++) {
            if (stk.empty() || nums2[i] <= stk.top()) {
                stk.push(nums2[i]);
            } else {
                while (!stk.empty() && nums2[i] > stk.top()) {
                    if (st1.count(stk.top())) {
                        mp[stk.top()] = nums2[i] == 10001 ? -1 : nums2[i];
                    }
                    stk.pop();
                }
                stk.push(nums2[i]);
            }
        }
        vector<int> res;
        for (const int& num : nums1) {
            res.push_back(mp[num]);
        }
        return res;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> stk;
        nums2.push_back(10001); // �ڱ�����֤ȫ����ջ
        for (int i = 0; i < nums2.size(); i++) {
            if (stk.empty() || nums2[i] <= stk.top()) {
                stk.push(nums2[i]);
            } else {
                while (!stk.empty() && nums2[i] > stk.top()) {
                    mp[stk.top()] = nums2[i] == 10001 ? -1 : nums2[i];
                    stk.pop();
                }
                stk.push(nums2[i]);
            }
        }
        vector<int> res;
        for (const int& num : nums1) {
            res.push_back(mp[num]);
        }
        return res;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums1[i]] = i;
        }
        vector<int> ans(n, -1);
        stack<int> stk;
        for (int i = 0; i < nums2.size(); i++) {
            if (stk.empty() || nums2[i] <= stk.top()) {
                stk.push(nums2[i]);
            } else {
                while (!stk.empty() && nums2[i] > stk.top()) {
                    if (mp.count(stk.top())) {
                        ans[mp[stk.top()]] = nums2[i];
                    }
                    stk.pop();
                }
                stk.push(nums2[i]);
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums1{2, 4}, nums2{1, 2, 3, 4};
    Solution sol;
    vector<int> res = sol.nextGreaterElement(nums1, nums2);
    for (auto& x : res) {
        cout << x << ' ';
    }
    system("pause");
    return 0;
}