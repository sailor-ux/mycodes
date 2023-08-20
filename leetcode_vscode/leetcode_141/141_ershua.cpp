#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }
        ListNode *p1 = head, *p2 = head->next;
        while (p1 != p2) {
            p1 = p1->next;
            if (p2 && p2->next) {
                p2 = p2->next->next;
            } else {
                return false;
            }
        }
        return true;
    }
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }
        ListNode *p1 = head, *p2 = head->next;
        while (p1 != p2) {
            if (!p2 || !p2->next) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return true;
    }
    // do-while
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }
        ListNode *p1 = head, *p2 = head;
        do {
            if (!p2 || !p2->next) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        } while (p1 != p2);
        return true;
    }
};
int main() {

    system("pause");
    return 0;
}