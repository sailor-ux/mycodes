#include <iostream>
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
    ListNode* sortList(ListNode* head) {
        if (!head) {
            return head;
        }
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* midNode = slow;
        return mergeTwoList(sortList(head, midNode), sortList(midNode, tail));
    }
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* currNode = dummyHead;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                currNode->next = list1;
                list1 = list1->next;
            } else {
                currNode->next = list2;
                list2 = list2->next;
            }
            currNode = currNode->next;
        }
        if (list1) {
            currNode->next = list1;
        }
        if (list2) {
            currNode->next = list2;
        }
        return dummyHead->next;
    }
};
int main() {

    system("pause");
    return 0;
}