#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
  public:
    void reorderList(ListNode* head) {
        ListNode* midNode = middleNode(head);
        ListNode* list2 = reverseList(midNode->next); // list2链表中的元素需要插入进list1链表中去，插入操作也要注意怎么写
        midNode->next = nullptr;
        ListNode* list1 = head;
        while (list2) {
            ListNode* temp = list1->next;
            list1->next = list2;
            list1 = temp;
            temp = list2->next;
            list2->next = list1;
            list2 = temp;
        }
    }
    // 快慢指针找中间节点，见876题
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 原地反转链表，递归法，还有迭代法，见206题
    ListNode* reverseList(ListNode* head) { // head还是有可能为nullptr的，当链表只有一个结点的时候
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    ListNode* head = new ListNode(arr[0]);
    ListNode* headTemp = head;
    for (int i = 1; i < arr.size(); i++) {
        headTemp->next = new ListNode(arr[i]);
        headTemp = headTemp->next;
    }
    Solution sol;
    headTemp = head;
    while (headTemp) {
        cout << headTemp->val << ' ';
        headTemp = headTemp->next;
    }
    cout << "\n";
    sol.reorderList(head);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    system("pause");
    return 0;
}