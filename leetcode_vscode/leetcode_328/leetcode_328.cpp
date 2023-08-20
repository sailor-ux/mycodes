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
    // ��������˿���ѣ�����
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode *odd = head, *evenHead = head->next;
        ListNode* even = evenHead;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
int main() {

    system("pause");
    return 0;
}