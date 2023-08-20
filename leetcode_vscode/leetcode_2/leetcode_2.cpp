#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// Ð´µÃÌ«·±ÔÓÁË£¡£¡
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = l1, *head2 = l2;
        int count = 0;
        while (head1 && head2) {
            int sum = head1->val + head2->val + count; // 0<=sum<=19
            count = 0;
            if (sum > 9) {
                count = 1;
                sum %= 10;
            }
            head1->val = sum;
            head2->val = sum;
            if (!head1->next && !head2->next) {
                if (count) {
                    head1->next = new ListNode(1);
                }
                return l1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        while (head1) {
            if (count == 0) {
                return l1;
            }
            int sum = head1->val + count;
            count = 0;
            if (sum == 10) {
                count = 1;
                sum = 0;
            }
            head1->val = sum;
            if (!head1->next) {
                if (count) {
                    head1->next = new ListNode(1);
                }
                return l1;
            }
            head1 = head1->next;
        }
        while (head2) {
            if (count == 0) {
                return l2;
            }
            int sum = head2->val + count;
            count = 0;
            if (sum == 10) {
                count = 1;
                sum = 0;
            }
            head2->val = sum;
            if (!head2->next) {
                if (count) {
                    head2->next = new ListNode(1);
                }
                return l2;
            }
            head2 = head2->next;
        }
        return nullptr;
    }
};
int main() {
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(1);
    ListNode* l2 = new ListNode(1);
    Solution sol;
    ListNode* ptr = sol.addTwoNumbers(l1, l2);
    while (ptr) {
        cout << ptr->val << ' ';
        ptr = ptr->next;
    }
    system("pause");
    return 0;
}