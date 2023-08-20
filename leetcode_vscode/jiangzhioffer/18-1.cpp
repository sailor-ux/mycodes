#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // ���ϵģ�����O(1)
    ListNode* deleteNode(ListNode* head, ListNode* pToBeDeleted) { // ������Ҫɾ���Ľڵ��ָ�룬ʱ�临�Ӷ�����O(N)�����Բ��ø���+�����ķ���ʵ��O(1)
        if (!head->next) {                                         // ����ֻ��һ���ڵ㣬����Ҫɾ�������������
            return NULL;
        }
        if (!pToBeDeleted->next) { // Ҫɾ���Ľڵ���β�ڵ㣨���������
            ListNode* node = head;
            while (node->next != pToBeDeleted) {
                node = node->next;
            }
            node->next = NULL;
        } else { // Ҫɾ���Ľڵ㲻��β�ڵ�
            pToBeDeleted->val = pToBeDeleted->next->val;
            pToBeDeleted->next = pToBeDeleted->next->next;
        }
        return head;
    }
    // leetcode�ϵĸı���, ֻ��O(n), ���ϵķ�������O(1),
    // ���㣺
    // 1��Ҫ�ҵ��Ǳ�ɾ���ڵ����һ���ڵ�
    // 2�����Ҫɾ���Ľڵ���ͷ�ڵ㣬������������⿼�ǣ����߲���dummyHead����������������⿼�ǣ�����������ۣ�ʵ��ͳһ�Ĵ���
    ListNode* deleteNode(ListNode* head, int val) { // ������Ҫɾ���Ľڵ��val
        if (!head) {
            return NULL;
        }
        if (head->val == val) { // ���Ҫɾ���Ľڵ����ͷ�ڵ㣨���������
            return head->next;
        }
        ListNode* node = head;
        while (node->next->val != val) {
            node = node->next;
        }
        node->next = node->next->next;
        return head;
    }
};
int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    ListNode *head = new ListNode(nums[0]), *tmp = head;
    ListNode* pToBeDeleted = NULL;
    for (int i = 1; i < nums.size(); i++) {
        tmp->next = new ListNode(nums[i]);
        tmp = tmp->next;
        if (nums[i] == 4) {
            pToBeDeleted = tmp;
        }
    }
    cout << head->val << endl;
    cout << tmp->val << endl;
    cout << pToBeDeleted->val << endl;
    Solution sol;
    sol.deleteNode(head, pToBeDeleted);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    system("pause");
    return 0;
}