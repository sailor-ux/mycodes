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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head, *tmp = cur;
        while (cur) {
            while (tmp && tmp->val == cur->val) {
                tmp = tmp->next;
            }
            cur->next = tmp;
            cur = cur->next;
        }
        return head;
    }
};
int main() {

    system("pause");
    return 0;
}