#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode *p1 = head, *p2 = head;
        do {
            if (!p2 || !p2->next) {
                return NULL;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        } while (p1 != p2);
        int count = 0;
        do {
            p1 = p1->next;
            count++;
        } while (p1 != p2);
        p1 = head;
        p2 = head;
        while (count--) {
            p2 = p2->next;
        }
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
int main() {

    system("pause");
    return 0;
}