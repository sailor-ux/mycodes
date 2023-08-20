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
    // 书上的，可以O(1)
    ListNode* deleteNode(ListNode* head, ListNode* pToBeDeleted) { // 给的是要删除的节点的指针，时间复杂度无需O(N)，可以采用复制+跳过的方法实现O(1)
        if (!head->next) {                                         // 链表只有一个节点，并且要删除（特殊情况）
            return NULL;
        }
        if (!pToBeDeleted->next) { // 要删除的节点是尾节点（特殊情况）
            ListNode* node = head;
            while (node->next != pToBeDeleted) {
                node = node->next;
            }
            node->next = NULL;
        } else { // 要删除的节点不是尾节点
            pToBeDeleted->val = pToBeDeleted->next->val;
            pToBeDeleted->next = pToBeDeleted->next->next;
        }
        return head;
    }
    // leetcode上的改编了, 只能O(n), 书上的方法可以O(1),
    // 两点：
    // 1、要找的是被删除节点的上一个节点
    // 2、如果要删除的节点是头节点，特殊情况，特殊考虑；或者采用dummyHead，避免特殊情况特殊考虑，避免分类讨论，实现统一的处理
    ListNode* deleteNode(ListNode* head, int val) { // 给的是要删除的节点的val
        if (!head) {
            return NULL;
        }
        if (head->val == val) { // 如果要删除的节点就是头节点（特殊情况）
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