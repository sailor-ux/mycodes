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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode *left = dummyHead, *right = head;
        while (right) {
            if (right->val == val) {
                left->next = right->next;
                right = left->next;
            } else {
                left = left->next;
                right = right->next;
            }
        }
        return dummyHead->next;
    }
};
int main() {

    system("pause");
    return 0;
}