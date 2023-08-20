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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur = new ListNode(), *dummyHead = cur;
        int carry = 0;
        while (l1 || l2) {
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            int sum = x + y + carry;
            carry = sum > 9 ? 1 : 0;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry) {
            cur->next = new ListNode(1);
        }
        return dummyHead->next;
    }
};
int main() {

    system("pause");
    return 0;
}