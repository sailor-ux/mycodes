#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        do {
            if (!fast || !fast->next) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        ListNode* ptr = head;
        while (ptr != slow) {
            ptr = ptr->next;
            slow = slow->next;
        }
        return ptr; // slow ТаїЙ
    }
};
int main() {

    system("pause");
    return 0;
}