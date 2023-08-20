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
    // do-whileÐ´·¨
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        do {
            if (!fast || !fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        return true;
    }
};
int main() {

    system("pause");
    return 0;
}