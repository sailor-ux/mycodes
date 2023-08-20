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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0), *pre = nullptr;
        dummy->next = head;
        while (head && head->next) {
            if (head->val <= head->next->val) {
                head = head->next;
                continue;
            }
            pre = dummy;
            while (pre->next->val < head->next->val) {
                pre = pre->next;
            }
            ListNode* node = head->next;
            head->next = node->next;
            node->next = pre->next;
            pre->next = node;
        }
        return dummy->next;
    }
};
int main() {

    system("pause");
    return 0;
}