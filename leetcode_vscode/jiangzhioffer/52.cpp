#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* node = headA;
        int cntA = 0, cntB = 0;
        while (node) {
            cntA++;
            node = node->next;
        }
        node = headB;
        while (node) {
            cntB++;
            node = node->next;
        }
        int k = abs(cntA - cntB);
        if (cntA > cntB) {
            while (k) {
                headA = headA->next;
                k--;
            }
        } else if (cntA < cntB) {
            while (k) {
                headB = headB->next;
                k--;
            }
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
int main() {

    system("pause");
    return 0;
}