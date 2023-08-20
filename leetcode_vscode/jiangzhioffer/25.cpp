#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 递归
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return NULL;
        }
        if (!l1 || !l2) {
            return l1 == NULL ? l2 : l1;
        }
        ListNode* mergedHead = nullptr;
        if (l1->val < l2->val) {
            mergedHead = l1;
            mergedHead->next = mergeTwoLists(l1->next, l2);
        } else {
            mergedHead = l2;
            mergedHead->next = mergeTwoLists(l1, l2->next);
        }
        return mergedHead;
    }
    // 迭代
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curTailNode = dummyHead; // curTailNode指向已合并链表的尾节点
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curTailNode->next = l1;
                l1 = l1->next;
            } else {
                curTailNode->next = l2;
                l2 = l2->next;
            }
            curTailNode = curTailNode->next;
        }
        if (l1) {
            curTailNode->next = l1;
        }
        if (l2) {
            curTailNode->next = l2;
        }
        return dummyHead->next;
    }
};
int main() {

    system("pause");
    return 0;
}